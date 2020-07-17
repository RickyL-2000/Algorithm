#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1010][1010];

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        fill(dp[0], dp[0] + 1010 * 1010, 0);
        
        int m = A.size(), n =B.size();
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> A = {1,2,3,2,1}, B = {3,2,1,4,7};
    Solution s;
    cout << s.findLength(A, B) << endl;
    return 0;
}