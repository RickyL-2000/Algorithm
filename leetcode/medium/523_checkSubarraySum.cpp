#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief book stores n+1 books, each represents the sum of i numbers in nums
     */
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1) return false;

        if (!k) {
            int next;
            for (size_t i = 0; i < nums.size(); i++) {
                if (!nums[i] && i+1 < nums.size() && !nums[i+1]) {
                    return true;
                };
            }
            return false;
        }

        vector<vector<int>> books(nums.size()+1);
        books[0] = {0};
        books[1] = nums;
        int cur;
        for (size_t len = 2; len <= nums.size(); len++) {
            for (size_t i = 0; i <= nums.size() - len; i++) {
                cur = books[len-1][i] + nums[i+len-1];
                if (cur % k == 0) return true;
                books[len].push_back(cur);
            }
        }
        return false;
    }
    void test() {
        vector<int> nums = {23, 2, 4, 7};
        int k = 6;
        if (checkSubarraySum(nums, k))  printf("True");
        else printf("False");
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}