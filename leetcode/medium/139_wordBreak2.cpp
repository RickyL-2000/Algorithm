#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> check;
        int maxLen = 0;
        for (string word : wordDict) {
            if (maxLen < word.length()) maxLen = word.length();
            check.insert(word);
        }

        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (i - j > maxLen) break;
                if (dp[j] && check.find(s.substr(j, i - j)) != check.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};