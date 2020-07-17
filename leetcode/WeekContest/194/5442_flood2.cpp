#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 0);
        priority_queue<int, vector<int>, greater<int>> work;
        map<int, int> water;
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                work.push(i);
            } else {
                if (water.find(rains[i]) != water.end()) {
                    // this lake has been rain over before
                    vector<int> temp;   // 用于存放work.pop出来的东西
                    while (!work.empty() && work.top() < water[rains[i]]) {
                        // 需要找到该湖最后一次下雨之后最早可以进行排水的日子
                        temp.push_back(work.top());
                        work.pop();
                    }
                    if (work.empty()) return {};
                    int toWork = work.top();
                    ans[toWork] = rains[i];
                    work.pop();
                    for (int e : temp) work.push(e);    // 将缓存push回
                }
                water[rains[i]] = i;
                ans[i] = -1;
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 0) ans[i] = 1;
        }
        return ans;
    }
};

int main() {
    vector<int> rains = {1,0,2,0,2,1};
    Solution s;
    auto ans = s.avoidFlood(rains);
    return 0;
}