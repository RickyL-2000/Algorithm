#include <iostream>
using namespace std;

const int MAXN = 100010;
double nums[MAXN], preSum[MAXN];
int n;
double ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &nums[i]);
        preSum[i] = i == 0 ? nums[i] : preSum[i-1] + nums[i];
    }
    for (int i = -1; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (i == -1) {
                ans += preSum[j];
            } else {
                ans += preSum[j] - preSum[i];
            }
        }
    }

    printf("%.2lf", ans);
    return 0;
}