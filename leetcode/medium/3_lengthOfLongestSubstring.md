# 3_lengthOfLongestSubstring

## my sol 1     20/6/15     30 min

FAIL

不起眼的小错误，就是在于每次找到重复数字的时候我都直接更新了left = right + 1，这是错误的。

正确的做法是找到那个重复字母的位置，然后从那个位置开始...

这样的话，最好还是用map...

``` C++
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        if (s.length() == 1) return 1;
        int left = 0, right = 0;
        int maxlen = 1;
        set<char> st;
        st.insert(s[0]);
        while (left < s.length()-1 && right < s.length()-1) {
            if (st.insert(s[right+1]).second) {
                // if insert succeed
                right++;
                continue;
            } else {
                st.clear();
                maxlen = right - left + 1 > maxlen ? right - left + 1 : maxlen;
                left = ++right;
                st.insert(s[right]);
            }
        }
        maxlen = right - left + 1 > maxlen ? right - left + 1 : maxlen;
        return maxlen;
    }
};

int main() {
    Solution s;
    string str = "dvdf";
    printf("%d", s.lengthOfLongestSubstring(str));
    return 0;
}
```


## my sol 2     20/6/15     20 min

FAIL

超出了时间限制...

氦，我也觉得这个用map的办法很麻烦，很难优化。可能是自己的思维被禁锢住了吧...

问题就是在于不知道如何处理map中的数据，每次都要清零很麻烦。

``` C++
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        if (s.length() == 1) return 1;
        int left = 0, right = 0;
        int maxlen = 1;
        map<char, int> mp;
        mp[s[0]] = 0;
        while (left < s.length()-1 && right < s.length()-1) {
            if (mp.find(s[right+1]) == mp.end()) {
                // not duplicate
                mp[s[right+1]] = right+1;
                right++;
            } else { 
                left = mp[s[right+1]] + 1;
                right = left;
                mp.clear();
                mp[s[left]] = left;
            }
            maxlen = right - left + 1 > maxlen ? right - left + 1 : maxlen;
            // if (st.insert(s[right+1]).second) {
            //     // if insert succeed
            //     right++;
            //     continue;
            // } else {
            //     st.clear();
            //     maxlen = right - left + 1 > maxlen ? right - left + 1 : maxlen;
            //     left = ++right;
            //     st.insert(s[right]);
            // }
        }
        maxlen = right - left + 1 > maxlen ? right - left + 1 : maxlen;
        return maxlen;
    }
};

int main() {
    Solution s;
    string str = "dvdf";
    printf("%d", s.lengthOfLongestSubstring(str));
    return 0;
}
```


## my sol 3     20/6/15     20 min

56 ms   36.23%

8.6 mb  100%

总算对了！就是在sol2基础上进行的改进，就是每次在查重的时候添加了一个对index和left的比较检查。但是时间还是比较长...


``` C++
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        if (s.length() == 1) return 1;
        int left = 0, right = 0;
        int maxlen = 1;
        map<char, int> mp;
        mp[s[0]] = 0;
        while (left < s.length()-1 && right < s.length()-1) {
            if (mp.find(s[right+1]) == mp.end() || mp[s[right+1]] < left) {
                // not duplicate
                mp[s[right+1]] = right+1;
                right++;
            } else { 
                left = mp[s[right+1]] + 1;
                // right = left + maxlen - 1;
                mp[s[right+1]] = right+1;
                right++;
            }
            maxlen = right - left + 1 > maxlen ? right - left + 1 : maxlen;
            // if (st.insert(s[right+1]).second) {
            //     // if insert succeed
            //     right++;
            //     continue;
            // } else {
            //     st.clear();
            //     maxlen = right - left + 1 > maxlen ? right - left + 1 : maxlen;
            //     left = ++right;
            //     st.insert(s[right]);
            // }
        }
        maxlen = right - left + 1 > maxlen ? right - left + 1 : maxlen;
        return maxlen;
    }
};

int main() {
    Solution s;
    string str = "abcabcbb";
    printf("%d", s.lengthOfLongestSubstring(str));
    return 0;
}
```
