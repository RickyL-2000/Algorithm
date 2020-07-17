#include <cstdio>
#include <vector>
using namespace std;

int main() {
    long a, b;
    scanf("%ld %ld", &a, &b);
    a = a + b;
    if (a < 0) printf("-");
    if (a == 0) printf("0");
    a = a > 0 ? a : -a;
    vector<long> stk;
    while (a != 0) {
        stk.push_back(a % 10);
        a = a / 10;
    }
    for (auto it = stk.rbegin(); it != stk.rend(); it++) {
        printf("%ld", *it);
        if (it != stk.rend()-1 && (stk.rend() - it - 1) % 3 == 0) printf(",");
    }
    return 0;
}