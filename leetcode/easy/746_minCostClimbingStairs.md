# Min Cost Climbing Stairs

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my solution 1    20/1/18     10 min

time    8       66.59%

mem     8.9     15.45%

```
class Solution {
public:
    int min(int a, int b) {
        return a > b ? b : a;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return min(cost[0], cost[1]);
        int dp[cost.size()+1];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i <= cost.size(); i++) {
            if (i < cost.size())
                dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
            else
                dp[i] = min(dp[i-1], dp[i-2]);
        }
        return dp[cost.size()];
    }
};
```

## my solution 2    20/1/18

内存优化

t   8   66.59

m   8.6 80.28

```
class Solution {
public:
    int min(int a, int b) {
        return a > b ? b : a;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return min(cost[0], cost[1]);
        int pre, pre_pre, cur;
        pre_pre = cost[0];
        pre = cost[1];
        for (int i = 2; i <= cost.size(); i++) {
            if (i < cost.size())
                cur = min(pre, pre_pre) + cost[i];                
            else
                cur = min(pre, pre_pre);
            pre_pre = pre;
            pre = cur;
        }
        return cur;
    }
};
```