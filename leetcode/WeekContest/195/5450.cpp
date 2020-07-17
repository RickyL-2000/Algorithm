#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        long long int ans = 0;
        while (nums[len-1] >= target && len-1 > 0) {
            len--;
        }
        int left = 0, right = len-1;
        while (right > 0 && nums[left] + nums[right] > target) {
            right--;
        }
        ans = (1<<(right - left + 1)) - 1;
        for (int i = right; i >= left; i--) {
            if (nums[i] * 2 > target) ans--;
            else break;
        }
        int pre = right;
        for (int i = right; i > 0; i--) {
            if (i != right && nums[i] == nums[pre]) continue;
            else pre = i;
            for (int j = left; j < i; j++) {
                if (nums[j] + nums[i] > target) {
                    ans -= (1 << (i - j + 1)) - 1 - (i - j + 1);
                    break;
                }
            }
        }
        ans %= (long)1e9 + 7;
        return ans;
    }
};

int main() {
    vector<int> nums = {7,10,7,5,6,7,3,4,9,6};
    int target = 9;
    Solution s;
    cout << s.numSubseq(nums, target);
    return 0;
}