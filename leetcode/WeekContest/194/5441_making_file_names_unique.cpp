#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> mp;
        vector<string> ans;
        int k;
        for (string name : names) {
            if (mp.find(name) == mp.end()) {
                mp[name]++;
                ans.push_back(name);
            } else {
                k = mp[name];
                while (mp.find(name + "(" + to_string(k) + ")") != mp.end()) {
                    k++;
                    mp[name]++;
                }
                mp[name + "(" + to_string(k) + ")"]++;
                mp[name]++;
                ans.push_back(name + "(" + to_string(k) + ")");
            }
        }
        return ans;
    }
};
