#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (a && b) {
        if (a > b) a %= b;
        else if (b > a) b %= a;
        else if (a == b) return a;
    }
    if (a) return a;
    return b;
}

int scm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n;
    scanf("%d", &n);
    long int num, denom, ans_n = 0, ans_den = 0, ans_int = 0;
    long int temp;
    for (int i = 0; i < n; i++) {
        scanf("%ld/%ld", &num, &denom);
        if (num == 0) continue;
        if (ans_n == 0) {
            ans_n = num / (temp = gcd(num, denom)); // simplify
            ans_den = denom / temp;
            continue;
        } else {
            temp = scm(ans_den, denom);
            ans_n = ans_n*temp/ans_den + num*temp/denom;
            if (ans_n == 0) continue;
            ans_den = temp;
            ans_n = ans_n / (temp = gcd(ans_n, ans_den)); // simplify
            ans_den = ans_den / temp;           
        }
    }

    if (ans_n > ans_den) {
        ans_int = ans_n / ans_den;
        ans_n %= ans_den; 
    }
    if (ans_int && ans_n) printf("%ld ", ans_int);
    else if (ans_int && !ans_n) printf("%ld", ans_int);
    else if (!ans_int && !ans_n) printf("0");
    if (ans_n) printf("%ld/%ld", ans_n, ans_den);

    return 0;
}