#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<pair<int, int>> area(n+1);
        for (int i = 0; i < area.size(); i++) {
            area[i] = make_pair(0, i);
        }
        int state = rounds[0];
        area[state] = make_pair(1, state);
        for (int i = 1; i < rounds.size(); i++) {
            if (rounds[i] > state) {
                for (int j = state + 1; j <= rounds[i]; j++) {
                    area[j].first++;
                }
            } else {
                for (int j = state + 1; j < area.size(); j++) {
                    area[j].first++;
                }
                for (int j = 1; j <= rounds[i]; j++) {
                    area[j].first++;
                }
            }
            state = rounds[i];
        }
        sort(area.begin(), area.end(), [](pair<int, int> &a1, pair<int, int> &a2) {return a1.first < a2.first;});
        vector<int> ret = {area[area.size()-1].second};
        int pre = area[area.size()-1].first;
        for (int i = area.size()-2; i > 0; i--) {
            if (area[i].first == pre) {
                ret.push_back(area[i].second);
            } else break;
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    int n = 4;
    vector<int> rounds = {1, 3, 1, 2};
    Solution s;
    vector<int> ret = s.mostVisited(n, rounds);
    return 0;
}