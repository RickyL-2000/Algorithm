# 239. Sliding Window Maximum

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length

## my sol 1     20/7/18     60 min

执行用时：
84 ms
, 在所有 C++ 提交中击败了
72.65%
的用户
内存消耗：
28.4 MB
, 在所有 C++ 提交中击败了
5.88%
的用户

先学了下单调队列...所以花了比较久的时间，但是，这个技巧确实很有用

``` C++
#define MAXN 100010

int q[MAXN];

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        fill(q, q + MAXN, 0);
        int head = 0, tail = 0;
        for (int i = 0; i < k-1; i++) {
            while (head <= tail && nums[q[tail]] <= nums[i]) tail--;
            q[++tail] = i;
        }
        vector<int> ans;
        for (int i = k-1, n = nums.size(); i < n; i++) {
            while (head <= tail && nums[q[tail]] <= nums[i]) tail--;
            q[++tail] = i;
            while (q[head] <= i - k) head++;    // i - q[head] + 1 > k
            ans.push_back(nums[q[head]]);
        }
        return ans;
    }
};
```
