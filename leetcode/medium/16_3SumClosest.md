# 16_3SumClosest

## my sol 1     20/6/20     30 min

24 ms   21.16%

10.1 mb 7.14%

用了上一题中ref的双指针法，确实空间少很多，但是时间也没有优化多少

发现了所谓
``` 
AddressSanitizer: heap-buffer-overflow on address 0x602000000040 at pc 0x000000406b5e bp 0x7ffc15cc0320 sp 0x7ffc15cc0318
```
的解决方法之一：

这个问题的原因是出现了潜在的数组越界，尽管逻辑上不会越界。以后还是得写得小心一点...

``` C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 20000, temp;
        int first, second, third;
        sort(nums.begin(), nums.end());
        for (first = 0; first < nums.size(); first++) {
            if (first > 0 && nums[first-1] == nums[first]) continue;
            for (second = first+1; second < nums.size(); second++) {    // !!! NOTE 就是这里，second < nums.size()-1，有潜在的数组越界可能，会被leetcode报错
                if (second > first + 1 && nums[second-1] == nums[second]) continue;
                third = nums.size() - 1;
                for (third = nums.size() - 1; third > second; third--) {
                    if (nums[first] + nums[second] + nums[third] <= target) break;
                }
                // 如果指针重合，说明没有找到相等的，只能从third+1处找最近的
                if (third == second) third += 1;
                if (nums[first] + nums[second] + nums[third] == target) return target;
                else {
                    if (third == nums.size()-1) {
                        temp = nums[first] + nums[second] + nums[third];
                        ret = abs(ret - target) > abs(temp - target) ? temp : ret;
                    } else {
                        temp = abs(nums[first] + nums[second] + nums[third] - target) >
                               abs(nums[first] + nums[second] + nums[third+1] - target) ?
                               nums[first] + nums[second] + nums[third+1] :
                               nums[first] + nums[second] + nums[third];
                        ret = abs(ret - target) > abs(temp - target) ? temp : ret;
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution s;
    printf("%d", s.threeSumClosest(nums, target));
    return 0;
}
```
