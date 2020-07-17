#include <iostream>
using namespace std;

// const int MAXN = 100010;
// double nums[MAXN];

int main() {
    int n;
    double ans = 0.0;
    double temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &temp);
        ans += (n * i - i * i - i + n) * temp;
    }
    printf("%.2lf", ans);
    return 0;
}