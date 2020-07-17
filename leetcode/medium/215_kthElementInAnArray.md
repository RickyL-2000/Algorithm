# 215_kthElementInAnArray

## my sol 1     20/6/29     10 min

想了一会儿...发现这不是一道最水的题吗？

32 ms   45.55%

9.9 mb  5.88%

``` C++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        sort(nums.rbegin(), nums.rend());
        // int idx = 1, i = 1;
        // while (i < nums.size() && idx < k) {
        //     if (nums[i] != nums[i-1]) {
        //         idx++;
        //     }
        //     i++;
        // }
        // return nums[i-1];
        return nums[k-1];
    }
};
```

转念一想...肯定没有这么简单...

## ref sol 1    20/6/29

小顶堆的算法

``` C++

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int result = 0;
        int numsSize = int(nums.size());
        if (numsSize == 0 || k > numsSize)
        {
            return 0;
        }

        priority_queue<int, vector<int>, greater<int>> store;
        //堆中维持k个最大数
        for (int i = 0; i < numsSize; i++)
        {
            store.push(nums[i]);
            if (int(store.size()) > k)
            {
                store.pop();
            }
        }

        result = store.top();
        return result;
    }
};
```

据说这种算法只需要O(k)的复杂度
