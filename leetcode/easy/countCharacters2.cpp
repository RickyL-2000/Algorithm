/* hash map */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> htc(26);
        for (char ch : chars) {
            htc[ch - 'a']++;
        }
        int ans = 0;
        for (string &w : words) {
            vector<int> htw(26);    // 其实这里不需要再搞一个hash map
            int i;
            for (i = 0; i < w.size(); i++) {
                if (++htw[w[i] - 'a'] > htc[w[i] - 'a']) {
                    break;
                }
            }
            if (i >= w.size()) {
                ans += w.size();
            }
        }
        return ans;
    }
};