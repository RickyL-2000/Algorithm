#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;
        map<int, int> mp;
        int ans_idx = 0, rains_idx = 0;
            for (ans_idx = 0; ans_idx < rains.size(); ans_idx++) {
                if (rains[ans_idx] > 0) {
                    mp[ans_idx]++;
                    ans.push_back(-1);
                    rains_idx++;
                    continue;
                } else {

                }
            }
        while (rains_idx < rains.size()) {
            if (rains[ans_idx] > 0) {
                mp[ans_idx]++;
                ans.push_back(-1);
                rains_idx++;
                // TODO
            }
        }
    }
};