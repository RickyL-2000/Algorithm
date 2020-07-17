// FAIL

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ret = 0.0;
        long start1 = 0, start2 = 0, step_length;
        bool isOdd, interrupt_flag = false;
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            isOdd = true;
            step_length = (nums1.size() + nums2.size()) / 2;
        } else {
            isOdd = false;
            step_length = (nums1.size() + nums2.size() - 1) / 2;
        }

        while (step_length > 1) {
            if (start1 + step_length / 2 - 1 >= nums1.size()) {
                // 这里不作step_length的更新，在循环外更新
                interrupt_flag = true;
                break;
            }
            if (start2 + step_length / 2 - 1 >= nums2.size()) {
                // 这里不作step_length的更新，在循环外更新
                interrupt_flag = true;
                break;
            }
            if (nums1[start1 + step_length / 2 - 1] < nums2[start2 + step_length / 2 - 1]) {
                start1 += step_length / 2;
                step_length /= 2;
            } else if (nums1[start1 + step_length / 2 - 1] < nums2[start2 + step_length / 2 - 1]) {
                start2 += step_length / 2;
                step_length /= 2;
            }
        }

        if (interrupt_flag) {
            if (start1 + step_length / 2 - 1 >= nums1.size()) {
                step_length -= nums1.size() - start1;
                if (isOdd) {
                    ret = (double) nums2[start2 + step_length];
                    return ret;
                } else {
                    ret = ((double) nums2[start2 + step_length] + (double) nums2[start2 + step_length + 1]) / 2;
                    return ret;
                }
            } else {
                step_length -= nums2.size() - start2;
                if (isOdd) {
                    ret = (double) nums1[start1 + step_length];
                    return ret;
                } else {
                    ret = ((double) nums1[start1 + step_length] + (double) nums1[start1 + step_length + 1]) / 2;
                    return ret;
                }
            }
        } else {
            if (isOdd) {
                return nums1[start1] > nums2[start2] ? (double) nums2[start2] : (double) nums1[start1];
            } else {
                if (nums1[start1] > nums2[start2]) {
                    ret += (double) nums2[start2];
                    if (start2+1 >= nums2.size() || nums1[start1] < nums2[start2+1]) {
                        ret += (double) nums1[start1];
                        ret /= 2;
                        return ret;
                    } else {
                        ret += (double) nums2[start2+1];
                        ret /= 2;
                        return ret;
                    }
                } else {
                    ret += (double) nums1[start1];
                    if (start1+1 >= nums1.size() || nums2[start2] < nums1[start1+1]) {
                        ret += (double) nums2[start2];
                        ret /= 2;
                        return ret;
                    } else {
                        ret += (double) nums1[start1+1];
                        ret /= 2;
                        return ret;
                    }
                }
            }
        }
        
    }
};

int main() {
    vector<int> nums1 = {1, 3},
                nums2 = {2};
    Solution s;
    printf("%lf", s.findMedianSortedArrays(nums1, nums2));
    return 0;
}