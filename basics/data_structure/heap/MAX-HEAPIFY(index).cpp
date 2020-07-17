#include <iostream>
#include <vector>
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