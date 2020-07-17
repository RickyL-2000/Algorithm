#include <iostream>
#include <vector>
#include <algorithm>   // 因为 BUILD-MAX-HEAP 尚未完成
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

void HEAPSORT(vector<int>& nums) {
    make_heap(nums.begin(), nums.end());
    for (auto it = nums.end()-1; it > nums.begin(); --it) {
        int temp = *nums.begin();
        *nums.begin() = *it;
        *it = temp;
        MAX_HEAPIFY(nums, it, nums.begin());
    }
}

int main() {
    vector<int> nums = {1,5,2,6,2,1,5};
    HEAPSORT(nums);
    return 0;
}