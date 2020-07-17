# longestPalindrome

## my sol 1     2020/6/19

思路：将s反转，然后查找两个字符串的最大公共子串

真是太奇怪了，有一个测试样例"abb"通不过，但是我本地却是可以通过的...

``` C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1010][1010];

class Solution {
public:
    string longestPalindrome(string s) {
        // fill(dp[0], dp[0] + 1010*1010, 0);
        string ret, s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        int maxlen = 0, start = 0;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= s_rev.length(); j++) {
                if (s[i-1] == s_rev[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if (dp[i][j] > maxlen) {
                        maxlen = dp[i][j];
                        start = i - maxlen;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};

int main() {
    string str = "abb";
    Solution s;
    cout << s.longestPalindrome(str);
    return 0;
}
```