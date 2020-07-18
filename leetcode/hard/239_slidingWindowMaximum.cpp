#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100010

int q[MAXN];

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        fill(q, q + MAXN, 0);   // 如果没有这一句，q的初始值可能是负数导致溢出
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

int main() {
    vector<int> nums = {1};
    int k = 1;
    Solution s;
    vector<int> ans = s.maxSlidingWindow(nums, k);
    return 0;
}
