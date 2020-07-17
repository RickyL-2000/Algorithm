#include <iostream>
#include <algorithm>
using namespace std;

// FIXME one test point can't pass...

float e[2050];
float result[2050];

int main() {
    fill(e, e+2050, 0);
    int k1, k2, ex, tp_ex;
    float c, tp_c;
    int sum = 0;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        scanf("%d %f", &ex, &c);
        e[ex] = c;
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++) {
        scanf("%d %f", &ex, &c);
        for (int j = 2049; j >= 0; j--) {
            if (e[j] != 0) {
                tp_ex = j + ex;
                tp_c = e[j] * c;
                if (result[tp_ex] == 0) sum++;
                result[tp_ex] += tp_c;
            }
        }
    }
    printf("%d", sum);
    for (int i = 2049; i >= 0; i--) {
        if (result[i] != 0) {
            printf(" %d %.1f", i, result[i]);
        }
    }
    return 0;
}