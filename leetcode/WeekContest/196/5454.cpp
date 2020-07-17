#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int dp[200][200];
        fill(dp[0], dp[0] + 200 * 200, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j];
                }
            }
        }
        int cnt = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                for (int i = x+1; i <= m; i++) {
                    for (int j = y+1; j <= n; j++) {
                        if ((i - x) * (j - y) == dp[i][j] - dp[i][y] - dp[x][j] + dp[x][y]) 
                            cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<int>> mat = {{0,1,1,0},
                               {0,1,1,1},
                               {1,1,1,0}};
    Solution s;
    cout << s.numSubmat(mat);
    return 0;
}