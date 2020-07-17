#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> points;
        int sum = 0, cur = 0;
        auto op = ops.begin();
        auto cur_c = (*op).begin();
        for (op = ops.begin(); op != ops.end(); op++) {
            cur_c = (*op).begin();
            if (*cur_c - '0' >= 0 && *cur_c - '9' <= 0) {
                cur = 0;
                for (; cur_c != (*op).end(); cur_c++) {
                    cur = cur*10 + *cur_c - '0';
                }
                points.push_back(cur);
            } else if (*cur_c == '-') {
                cur = 0;
                for (cur_c = (*op).begin()+1; cur_c != (*op).end(); cur_c++) {
                    cur = cur*10 + *cur_c - '0';
                }
                points.push_back(-cur);
            } else if (*cur_c == 'D') {
                cur = points.back() * 2;
                points.push_back(cur);
            } else if (*cur_c == 'C') {
                points.pop_back();
            } else if (*cur_c == '+') {
                cur = *(points.end()-1) + *(points.end()-2);
                points.push_back(cur);
            }
        }
        for (auto p = points.begin(); p != points.end(); p++) {
            sum += *p;
        }
        return sum;
    }
    void test() {
        vector<string> que1 = {"5","-2","4","C","D","9","+","+"};
        vector<string> que2 = {"5","2","C","D","+"};
        vector<string> que3 = {"1","C","-62","-45","-68"};
        vector<string> que4 = {"-21","-66","39","+","+"};
        int ans = calPoints(que2);
        cout << ans << endl;
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}