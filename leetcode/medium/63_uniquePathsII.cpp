#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] || obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]) return 0;
        int dp[110][110];
        for (int i = 0; i < 110; i++) fill(dp[i], dp[i] + 110, 0);
        dp[1][1] = 1;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j]) dp[i+1][j+1] = 0;
                else dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j];
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<vector<int>> ob = {{1}};
    Solution s;
    cout << s.uniquePathsWithObstacles(ob);
    return 0;
}