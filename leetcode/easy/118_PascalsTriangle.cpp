#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i != numRows; i++) {    // 第几行
            if (i == 0) {
                vector<int> row = {1};
                triangle.push_back(row);
                continue;
            }
            if (i == 1) {
                vector<int> row = {1, 1};
                triangle.push_back(row);
                continue;
            }
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j != i - 1; j++) {
                row.push_back(triangle[i-1][j] + triangle[i-1][j+1]);
            }
            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle;
    }
    void test(int n) {
        vector<vector<int>> ans = generate(n);
        for (int i = 0; i != ans.size(); i++) {
            for (int j = 0; j != ans[i].size(); j++) {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    s.test(5);
    return 0;
}