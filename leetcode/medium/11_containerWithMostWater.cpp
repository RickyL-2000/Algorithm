#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            if ((right - left) * std::min(height[left], height[right]) > ret) {
                ret = (right - left) * std::min(height[left], height[right]);
            }
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return ret;
    }
};

int main() {}
