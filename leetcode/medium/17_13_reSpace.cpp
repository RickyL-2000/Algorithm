// 这是学了动规后自己加入剪枝的模仿版，没有利用Trie

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        set<string> dict;
        int maxLen = 0;
        for (string& word : dictionary) {
            maxLen = max(maxLen, (int) word.length());
            dict.insert(word);
        }
        vector<int> dp(sentence.length() + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= dp.size(); i++) {
            dp[i] = dp[i-1] + 1;
            for (int j = i - 1; j >= i - maxLen; j--) {
                if (dict.find(sentence.substr(j, i - j)) != dict.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[dp.size()-1];
    }
};

int main() {}
