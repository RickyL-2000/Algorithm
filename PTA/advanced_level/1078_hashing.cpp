#include <iostream>
#include <algorithm>
using namespace std;

long nums[10010];
int MSize, num;

bool isPrime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0 || n <= 1) return false;
    for (int i = 3; i*i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &MSize, &num);
    while (!isPrime(MSize)) MSize++;
    fill(nums, nums+MSize, -1);
    for (int i = 0; i < num; i++) {
        long long cur;
        scanf("%lld", &cur);
        cur = cur % MSize;
        if (nums[cur] < 0) {
            nums[cur] = cur;
            printf("%lld", cur);
        } else {
            printf("-");
        }
        if (i != num-1) printf(" ");
    }

    return 0;
}