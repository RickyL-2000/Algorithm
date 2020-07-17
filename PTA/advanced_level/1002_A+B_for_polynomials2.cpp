#include <iostream>
using namespace std;

double poly1[1001], poly2[1001];

int main() {
    int k, n, cnt = 0;
    double a;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%lf", &n, &a);
        poly1[n] = a;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%lf", &n, &a);
        poly2[n] = a;
    }
    for (int i = 0; i < 1001; i++) {
        if (poly1[i] != 0 || poly2[i] != 0) cnt++;
        poly1[i] += poly2[i];
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (poly1[i] != 0) {
            printf(" %d %.1lf", i, poly1[i]);
        }
    }
    return 0;
}