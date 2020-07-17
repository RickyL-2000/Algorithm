#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(),
            n = grid[0].size();
        int i, j;
        int sum = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n-1; j++) {
                if (grid[i][j] != grid[i][j+1]) {
                    sum++;
                }
            }
            if (grid[i][0] == 1) sum++;
            if (grid[i][n-1] == 1) sum++;
        }
        for (j = 0; j < n; j++) {
            for (i = 0; i < m-1; i++) {
                if (grid[i][j] != grid[i+1][j]) {
                    sum++;
                }
            }
            if (grid[0][j] == 1) sum++;
            if (grid[m-1][j] == 1) sum++;
        }
        return sum;
    }
};