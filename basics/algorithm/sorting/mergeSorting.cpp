// 有bug，得治
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>&, vector<int>::iterator, vector<int>::iterator, vector<int>::iterator, vector<int>&);
void mergeSort(vector<int>&, vector<int>::iterator, vector<int>::iterator, vector<int>&);


int main()
{
    cout << "Enter the group of numbers to be sorted (q to quit):" << endl;
    vector<int> nums;
    int num;
    while (cin >> num && num != 'q') {
        nums.push_back(num);
    }
    vector<int> temp(nums.size(), 0);
    mergeSort(nums, nums.begin(), nums.end(), temp);

    for (int n : nums) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}

void merge(vector<int>& nums, vector<int>::iterator beg, vector<int>::iterator mid, vector<int>::iterator end, vector<int>& temp)
{
    auto i = beg, j = mid+1;
    int k = 0;
    while (i != mid+1 && j != end) {
        if (*i <= *j) {
            *(nums.begin() + (k++)) = *(i++);
        } else if (*i > *j) {
            *(nums.begin() + (k++)) = *(j++);
        }
    }
    while (i != mid+1) {
        *(nums.begin() + (k++)) = *(i++);
    }
    while (j != end) {
        *(nums.begin() + (k++)) = *(j++);
    }
    for (int it = 0; it < k; ++it) {
        *(nums.begin() + it) = *(temp.begin() + it);
    }
}

void mergeSort(vector<int>& nums, vector<int>::iterator beg, vector<int>::iterator end, vector<int>& temp) {
    if (beg != end-1) {
        auto mid = beg + (end - beg)/2;
        mergeSort(nums, beg, mid+1, temp);
        mergeSort(nums, mid+1, end, temp);
        merge(nums, beg, mid, end, temp);
    }
}