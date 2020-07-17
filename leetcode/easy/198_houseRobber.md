# House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my solution 1    20/1/18     20 min

t   0   100

m   8.1 5.08

（我好像没有用那么多内存？？）

```
class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int rob(vector<int>& nums) {
        switch (nums.size()) {
            case 0: {return 0;}
            case 1: {return nums[0];}
            case 2: {return max(nums[0], nums[1]);}
            case 3: {return max(nums[0]+nums[2], nums[1]);}
        }
        int ppp = nums[0],
            pp = nums[1],
            p = nums[2] + nums[0];
        int M = max(p, pp);
        int cur;
        for (int i = 3; i < nums.size(); i++) {
            cur = max(ppp, pp) + nums[i];
            if (cur > M) M = cur;
            ppp = pp;
            pp = p;
            p = cur;
        }
        return M;
    }
};
```