# 4_medianOfTwoSortedArrays

## my sol 1     20/6/16     25 min

FAIL

实在想不到有什么log(m+n)的方法...

主要是...又遇到了这个heap overflow的问题...不知道如何解决...

``` C++

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

```

## ref sol 1

二分搜索

``` C++

class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};

```

真的是很久没有谢代码了啊，自己写的东西是真的丑啊...

啊啊啊啊，原来这是一道困难题...