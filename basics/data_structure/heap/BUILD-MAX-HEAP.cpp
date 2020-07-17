#include <iostream>
#include <vector>
#include <algorithm> // used to examine my algorithm is correct
using namespace std;

#define InHeap(begin, end, it)   ((begin <= it) && (it < end)) // this begin and end is the range of heap, not container
#define Parent(begin, it)       (begin + (((it - begin - 1) >> 1)))
#define LChild(begin, it)       (begin + (1 + ((it - begin) << 1)))
#define RChild(begin, it)       (begin + ((1 + it - begin) << 1))

void MAX_HEAPIFY(vector<int>& nums, vector<int>::iterator end, vector<int>::iterator it) {
    auto l = LChild(nums.begin(), it);
    auto r = RChild(nums.begin(), it);
    auto largest = nums.begin();
    if (l < end && *l > *it) {  // 这个nums.end()的本意是heap的end，但同时又是nums的end（吗？）
        largest = l;
    } else auto largest = it;
    if (r < end && *r > *it) {
        largest = r;
    }
    if (largest != it) {
        int temp = *largest;
        *largest = *it;
        *it = temp;
        MAX_HEAPIFY(nums, end, largest);
    }
    return;
}

void BUILD_MAX_HEAP(vector<int>& nums, vector<int>::iterator end) { // 指的是heap的end
    for (auto it = nums.begin()+(end-nums.begin())/2; it >= nums.begin(); --it) {
        MAX_HEAPIFY(nums, end, it);
    }
    return;
}

int main() {
    vector<int> nums1 = {1,3,2,6,4,7,0,9,8};
    vector<int> nums2(nums1);

    BUILD_MAX_HEAP(nums1, nums1.end());
    make_heap(nums2.begin(), nums2.end());

    return 0;
}