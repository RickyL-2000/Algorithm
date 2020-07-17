#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        sort(nums.rbegin(), nums.rend());
        int idx = 1, i = 1;
        while (i < nums.size() && idx < k) {
            if (nums[i] != nums[i-1]) {
                idx++;
            }
            i++;
        }
        return nums[i-1];
    }
};

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    Solution s;
    cout << s.findKthLargest(nums, k);
    return 0;
}