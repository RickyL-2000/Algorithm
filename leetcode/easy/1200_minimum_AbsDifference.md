# minimum_AbsDifference

Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

## my solutoin 1    20/1/13 30 min

FAIL

这题好奇怪，在本地跑得好好的在服务器上就是失败，编译倒是通过了

```
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int left, int right) {
    int i = left - 1,
        j = left,
        temp;
    for (; j < right; j++) {
        if (arr[j] < arr[right]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

void quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = partition(arr, left, right);
        quicksort(arr, left, mid-1);
        quicksort(arr, mid+1, right);
    }
}

int Abs(int a, int b) {
    return a > b ? a-b : b-a;
}

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size(); 
        quicksort(arr, 0, n-1);
        vector<vector<int>> ans;
        vector<int> cur;
        int min;
        for (int i = 0; i < n-1; i++) {
            if (min == 0 || Abs(arr[i], arr[i+1]) <= min) 
                min = Abs(arr[i], arr[i+1]);
        }
        for (int i = 0; i < n-1; i++) {
            if (Abs(arr[i], arr[i+1]) == min) {
                cur = {arr[i], arr[i+1]};
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
```