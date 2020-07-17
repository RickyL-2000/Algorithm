#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int>&);

int main()
{
    vector<int> nums = {1,5,2,5,7,3,4};
    insertionSort(nums);
    for (int value : nums) {
        cout << value << ' ';
    }
    cout << endl;
    return 0;
}

void insertionSort(vector<int>& nums) {
    for (auto i = nums.begin() + 1; i != nums.end(); ++i) {
        int value = *i;
        auto beg = nums.begin(), end = i;
        auto mid = beg + (end - beg) / 2;
        while (mid != end && *mid != value) {
            if (value > *mid) {
                beg = mid + 1;
            } else if (value < *mid) {
                end = mid;
            }
            mid = beg + (end - beg) / 2;
        }
        auto index = (*mid >= value) ? mid : mid + 1;
        for (auto j = i - 1; j != index - 1; --j) {
            *(j+1) = *j;
        }
        *index = value;
    }
}