#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> ret = {};
        // vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        map<string, string> mp;
        mp["2"] = "abc";
        mp["3"] = "def";
        mp["4"] = "ghi";
        mp["5"] = "jkl";
        mp["6"] = "mno";
        mp["7"] = "pqrs";
        mp["8"] = "tuv";
        mp["9"] = "wxyz";
        for (int i = 0; i < digits.length(); i++) {
            string curstr = mp[digits.substr(i, 1)];
            if (ret.empty()) {
                for (int j = 0; j < curstr.length(); j++) {
                    ret.push_back(curstr.substr(j, 1));
                }
            } else {
                int cursize = ret.size();
                for (int j = 0; j < curstr.length(); j++) {
                    for (int k = 0; k < cursize; k++) {
                        if (j == 0) {
                            ret[k] = ret[k] + curstr.substr(j, 1);
                        } else {
                            ret.push_back(ret[k].substr(0, i) + curstr.substr(j, 1));
                        }
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    string digits = "23";
    Solution s;
    vector<string> ret = s.letterCombinations(digits);
    return 0;
}