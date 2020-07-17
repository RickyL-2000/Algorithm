#include <iostream>
#include <vector>
using namespace std;

#define InHeap(begin, end, it)   ((begin <= it) && (it < end)) // this begin and end is the range of heap, not container
#define Parent(begin, it)       (begin + (((it - begin - 1) >> 1)))
#define LChild(begin, it)       (begin + (1 + ((it - begin) << 1)))
#define RChild(begin, it)       (begin + ((1 + it - begin) << 1))

void MAX_HEAPIFY(vector<int>& nums, vector<int>::iterator it) {
    auto l = LChild(nums.begin(), it);
    auto r = RChild(nums.begin(), it);
    auto largest = nums.begin();
    if (l < nums.end() && *l > *it) {
        largest = l;
    } else auto largest = it;
    if (r < nums.end() && *r > *it) {
        largest = r;
    }
    if (largest != it) {
        int temp = *largest;
        *largest = *it;
        *it = temp;
        MAX_HEAPIFY(nums, largest);
    }
    return;
}