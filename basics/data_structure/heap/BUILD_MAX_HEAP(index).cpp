#include <iostream>
#include <vector>
#include <algorithm>   // examine my own algorithm
using namespace std;

#define InHeap(n, i)   ((-1 < i) && (i < n)) // this begin and end is the range of heap, not container
#define Parent(i)       ((i-1) >> 1)
#define LChild(i)       (i + (i << 1))
#define RChild(i)       ((1 + i) << 1)

void MAX_HEAPIFY(vector<int>& nums, size_t heap_size, size_t i) {
    auto l = LChild(i);
    auto r = RChild(i);
    auto largest = 0;
    if (l < heap_size && nums[l] > nums[i]) {
        largest = l;
    } else largest = i;
    if (r < heap_size && nums[r] > nums[i]) {
        largest = r;
    }
    if (largest != i) {
        int temp = nums[largest];
        nums[largest] = nums[i];
        nums[i] = temp;
        MAX_HEAPIFY(nums, heap_size, largest);
    }
    return;
}

void BUILD_MAX_HEAP(vector<int>& nums, size_t heap_size) {
    for (int i = heap_size/2; i > 0; ++i) {
        MAX_HEAPIFY(nums, heap_size, i);
    }
    return;
}

int main() {
    vector<int> nums1 = {1,3,2,6,4,7,0,9,8};
    vector<int> nums2(nums1);

    BUILD_MAX_HEAP(nums1, nums1.size());
    make_heap(nums2.begin(), nums2.end());

    return 0;
}