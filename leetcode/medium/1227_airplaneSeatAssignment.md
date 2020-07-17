# Airplane Seat Assignment Probability

n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of passengers will:

Take their own seat if it is still available, 
Pick other seats randomly when they find their seat occupied 
What is the probability that the n-th person can get his own seat?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/airplane-seat-assignment-probability
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my sol 1     20/1/19     20 min

t   36  11.25

m   9.1 15.62

```
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n == 1) return 1;
        if (n == )
        double dp[n+1];
        dp[0] = 0.0;
        dp[1] = 1.0;
        dp[2] = 0.5;
        for (size_t i = 3; i <= n; i++) {
            dp[i] = (dp[i-1]*(i-1) + dp[i-1])/i;
        }
        return dp[n];
    }
};
```

## ref sol 1

我傻了，居然可以只传回1或者0.5。。。。。。

我算是明白了，以后能算出递推公式的通项公式的，直接用通项公式计算，可以有O(1)的时间复杂度......