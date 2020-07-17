#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define InHeap(begin, end, it)  ((it >= begin) && (it < end))
#define Parent(begin, it)   (begin + ((it-begin-1) >> 1))
#define LChild(begin, it)   (begin + (1 + ((it - begin) << 1)))
#define RChild(begin, it)   (begin + ((1 + it - begin) << 1))

int main() {
    vector<int> nums = {1,2,6,3,4,8,1,0,4,6};
    make_heap(nums.begin(), (nums.begin()+7));
    pop_heap(nums.begin(), (nums.begin()+7));
    int root = nums.front();
    auto it = is_heap_until(nums.begin(), nums.end());
    int end_of_heap = *it;

    cout << "The left child of " << *(nums.begin()+1) << " is " << *(LChild(nums.begin(), nums.begin()+1)) << endl;
    return 0;
}