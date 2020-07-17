#include <iostream>
#include <vector>
using namespace std;

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
        int min;
        for (int i = 0; i < n-1; i++) {
            if (min == 0 || Abs(arr[i], arr[i+1]) <= min) 
                min = Abs(arr[i], arr[i+1]);
        }
        for (int i = 0; i < n-1; i++) {
            if (Abs(arr[i], arr[i+1]) == min) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
    void test() {
        vector<int> arr = {3,8,-10,23,19,-4,-14,27};
        vector<vector<int>> ans = minimumAbsDifference(arr);
        cout << ans.size() << endl;
        int i;
        i = i + 1;      // for debugger;
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}