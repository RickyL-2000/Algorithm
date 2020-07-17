#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row, col;
        int n = matrix.size();
        row = k / n;
        col = k % n - 1;
        if (col == -1) return matrix[row-1][n-1];
        else return matrix[row][col];
    }
};

int main() {
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    Solution s;
    cout << s.kthSmallest(matrix, k);
    return 0;
}