# Counting Bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my sol 1     20/1/18 15 min

t   8   97.58

m   10.1    7.47

```
class Solution {
public:
    vector<int> countBits(int num) {
        if (!num) return {0};
        if (num == 1) return {0,1};
        if (num == 2) return {0,1,1};
        vector<int> dp(num+1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for (size_t i = 3; i < num+1; i++) {
            if (i % 2 == 1) dp[i] = dp[i-1] + 1;
            else dp[i] = dp[i/2];
        }
        return dp;
    }
};
```