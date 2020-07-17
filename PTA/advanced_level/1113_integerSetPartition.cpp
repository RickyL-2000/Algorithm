#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 50;
int nums[MAXN];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n);
    int sum1 = 0, sum2 = 0, len1 = n >> 1;
    printf("%d ", n & 1);
    for (int i = 0; i < len1; i++) {
        sum1 += nums[i];
    }
    for (int i = len1; i < n; i++) {
        sum2 += nums[i];
    }
    printf("%d", sum1 > sum2 ? sum1 - sum2 : sum2 - sum1);
    return 0;
}