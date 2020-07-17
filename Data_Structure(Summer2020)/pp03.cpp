/*
 * test1
 * 4 3 4 -5 2  6 1  -2 0
 * 3 5 20  -7 4  3 1
 * 
 * test2
 * 1 0 0
 * 1 0 0
 * 
 * test3
 * 1 1 1
 * 1 -1 1
 * */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2010;

int poly1[MAXN];
int poly2[MAXN];
int prod[MAXN];
int sum[MAXN];

int main() {
    fill(poly1, poly1 + MAXN, 0);
    fill(poly2, poly2 + MAXN, 0);
    fill(prod, prod + MAXN, 0);
    fill(sum, sum + MAXN, 0);
    int n, c, e, d1, d2;
    bool flag = true;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &c, &e);
        poly1[e] = c;
        if (flag) {
            d1 = e;
            flag = false;
        }
    }
    flag = true;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &c, &e);
        poly2[e] = c;
        if (flag) {
            d2 = e;
            flag = false;
        }
    }
    for (int i = 0; i <= d1; i++) {
        for (int j = 0; j <= d2; j++) {
            prod[i + j] += poly1[i] * poly2[j];
        }
    }
    for (int i = 0; i <= max(d1, d2); i++) {
        sum[i] += poly1[i] + poly2[i];
    }

    int up = d1 + d2;
    while (prod[up] == 0 && up > 0) up--;
    printf("%d %d", prod[up], up);
    for (int i = up - 1; i >= 0; i--) {
        if (prod[i] != 0) {
            printf(" %d %d", prod[i], i);
        }
    }
    printf("\n");
    up = max(d1, d2);
    while (sum[up] == 0 && up > 0) up--;
    printf("%d %d", sum[up], up);
    for (int i = up - 1; i >= 0; i--) {
        if (sum[i] != 0) {
            printf(" %d %d", sum[i], i);
        }
    }
    return 0;
}
