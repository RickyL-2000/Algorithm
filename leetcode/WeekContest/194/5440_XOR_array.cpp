#include <vector>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back(start + 2 * i);
        }
        int ret = nums[0];
        for (int i = 1; i < n; i++) {
            ret = ret ^ nums[i];
        }
        return ret;
    }
};
