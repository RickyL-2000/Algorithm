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