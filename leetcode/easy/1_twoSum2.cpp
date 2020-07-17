#include <iostream>
#include <map>
#include <vector>
#include <utility>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> n_map;
        std::vector<int> result(2,-1);
        
        for (int i = 0; i < nums.size(); ++i) {
            n_map.insert(std::make_pair(nums[i],i));
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (n_map.count(target - nums[i]) > 0) {
                result[0] = n_map[target - nums[i]];
                result[1] = i;
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = s.twoSum(nums, target);
    printf("%d %d", result[0], result[1]);
    return 0;
}
