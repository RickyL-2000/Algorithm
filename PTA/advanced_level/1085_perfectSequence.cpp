#include <iostream>
#include <algorithm>
using namespace std;

long long int nums[100010];

int main() {
    long long int p;
    int n;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        scanf("%Ld", &nums[i]);
    }

    sort(nums, nums+n);

    int curN, maxN = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + maxN; j < n; j++) {
            if (nums[j] <= nums[i] * p) {
                curN = j - i + 1;
                if (curN > maxN) maxN = curN;
            } else break;
        }
    }

    cout << maxN;

    return 0;
}