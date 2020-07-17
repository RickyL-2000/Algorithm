#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int fac(int num) {
        if (num == 0) return 1;
        int ans = 1;
        for (int i = 1; i <= num; i++) {
            ans *= i;
        }
        return ans;
    }
    int numIdenticalPairs(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        sort(nums.begin(), nums.end());
        nums.push_back(0);
        int cnt = 1, ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                ans += fac(cnt) / fac(cnt-2) / fac(2);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,3,1,1,3};
    Solution s;
    cout << s.numIdenticalPairs(nums);
    return 0;
}