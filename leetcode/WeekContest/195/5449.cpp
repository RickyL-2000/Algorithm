#include <iostream>
#include <vector>
using namespace std;

int num[100010];

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        fill(num, num+100010, 0);
        for (int i = 0; i < arr.size(); i++) {
            arr[i] %= k;
            arr[i] = arr[i] >= 0 ? arr[i] : arr[i] + k;
            num[arr[i]]++;
        }
        for (int i = 1; i < k; i++) {
            if (num[i] != num[k - i]) return false;
        }
        return true;
    }
};

int main() {
    vector<int> arr = {1,2,3,4,5,6};
    int k = 7;
    Solution s;
    cout << s.canArrange(arr, k);
    return 0;
}