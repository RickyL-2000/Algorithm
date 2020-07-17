#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        long long cnt = -1, idx1 = 0, idx2 = 0;
        double ret, cur;
        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            if (nums1[idx1] > nums2[idx2]) {
                cur = (double)nums2[idx2];
                idx2++;
                cnt++;
            } else {
                cur = (double)nums1[idx2];
                idx1++;
                cnt++;
            }
            if (cnt == (nums1.size() + nums2.size() - 1) / 2) {
                if ((nums1.size() + nums2.size()) % 2 == 0) {
                    // average
                    ret = (cur + (double)std::min(nums1[idx1], nums2[idx2])) / 2;
                    return ret;
                } else {
                    return (double) cur;
                }
            }
        }
        while (cnt < (nums1.size() + nums2.size() - 1) / 2) {
            if (idx1 < nums1.size()) {
                cur = (double)nums1[idx2];
                idx1++;
                cnt++;
            }
            if (idx2 < nums2.size()) {
                cur = (double)nums2[idx2];
                idx2++;
                cnt++;
            }
        }
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            // average
            if (idx1 < nums1.size()) {
                ret = (cur + (double)nums1[idx1]) / 2;
                return ret;
            } else {
                ret = (cur + (double)nums2[idx2]) / 2;
                return ret;
            }
        } else {
            return (double) cur;
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