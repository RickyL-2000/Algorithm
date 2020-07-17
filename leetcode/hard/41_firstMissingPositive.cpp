#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int minval = INT_MAX;
        set<int> check;
        for (int num : nums) {
            // if (num > 0 && num < minval) {
            //     minval = num;
            // }
            check.insert(num);
        }
        // if (minval > 1) return 1;
        int ret = 1;
        while (check.find(ret) != check.end()) {
            ret++;
        }
        return ret;
    }
};

int main() {}