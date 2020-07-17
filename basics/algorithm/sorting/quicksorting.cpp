#include <iostream>
#include <vector>
using namespace std;
void quicksort(vector<int>&, size_t, size_t);
int partition(vector<int>&, size_t, size_t);

int main() {
    vector<int> nums = {1,5,2,3,7,4};
    quicksort(nums, 0, nums.size()-1);
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}

void quicksort(vector<int>& nums, size_t begin, size_t end) { // [begin, end]
    if (begin < end) {
        int mid = partition(nums, begin, end);
        quicksort(nums, begin, mid-1);
        quicksort(nums, mid+1, end);
    }
}

int partition(vector<int>& nums, size_t begin, size_t end) {
    int i = begin - 1;
    for (int j = begin; j < end; ++j) {
        if (nums[j] <= nums[end]) {
            ++i;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    int temp = nums[i+1];
    nums[i+1] = nums[end];
    nums[end] = temp;
    return i+1;
}