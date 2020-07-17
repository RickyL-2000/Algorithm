# Unique BST

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my sol 1     20/1/19     30 min

t   0   100
m   8.3 43.11

```
class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        int cur;
        for (int i = 3; i <= n; i++) {
            cur = 2*dp[i-1];
            if (i % 2 == 0) {
                for (int j = 1; j <= i/2-1; j++) {
                    cur += 2*dp[j]*dp[i-j-1];
                }
            } else {
                for (int j = 1; j < i/2; j++) {
                    cur += 2*dp[j]*dp[i-j-1];
                }
                cur += dp[i/2]*dp[i/2];
            }
            dp[i] = cur;
        }
        return dp[n];
    }
};
```