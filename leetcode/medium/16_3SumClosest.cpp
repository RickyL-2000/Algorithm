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
            for (second = first+1; second < nums.size(); second++) {
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
