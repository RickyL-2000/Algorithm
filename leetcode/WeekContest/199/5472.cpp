#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<pair<string, int>> array;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            array.push_back(make_pair(s.substr(i, 1), indices[i]));
        }
        sort(array.begin(), array.end(), [](pair<string, int> &a, pair<string, int> &b) {
            return a.second < b.second;
        });
        string ans = "";
        for (int i = 0; i < len; i++) {
            ans = ans + array[i].first;
        }
        return ans;
    }
};