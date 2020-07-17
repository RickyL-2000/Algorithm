#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    int n, k, p, sum, index;
    cin >> n >> k >> p;
    vector<int> factors(k, 1);
    sum = k;
    index = 0;
    while (sum < n) {
        sum = sum + 2 * factors[index] + 1;     // - x^2 + (x+1)^2
        factors[index++]++;
        if (index >= k) index %= k;
    }
    if (sum == n) {
        printf("%d = ", n);
        for (size_t i = 0; i < k; i++) {
            printf("%d^%d", factors[i], p);
            if (i != k-1) printf(" + ");
        }
    } else {
        printf("Impossible");
    }
    
    return 0;
}