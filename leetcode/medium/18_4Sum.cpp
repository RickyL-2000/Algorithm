#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int first, second, third, fourth, temp;
        for (first = 0; first < nums.size() - 3; first++) {
            if (first > 0 && nums[first-1] == nums[first]) continue;
            for (second = first+1; second < nums.size() - 2; second++) {
                if (second > first+1 && nums[second-1] == nums[second]) continue;
                for (third = second+1; third < nums.size() - 1; third++) {
                    if (third > second+1 && nums[third-1] == nums[third]) continue;
                    fourth = nums.size() - 1;
                    temp = nums[first] + nums[second] + nums[third];
                    while (fourth > third && temp + nums[fourth] > target) {
                        fourth--;
                    }
                    if (fourth == third) break;
                    if (temp + nums[fourth] == target) {
                        ret.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                    }
                }
            }
        }
        return ret;
    }
};

int main() { 
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution s;
    auto ret = s.fourSum(nums, target);
    return 0;
}