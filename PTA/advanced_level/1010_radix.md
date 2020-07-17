# Radix

## my sol 1     20/1/21     30 min

部分正确

而且大部分运行超时？？

```
#include <iostream>
#include <math.h>
using namespace std;

int convert(const char r) {
    if (r <= '9' && r >= '0') {
        return r - '0';
    } else if (r <= 'z' && r >= 'a') {
        return r - 'a' + 10;
    }
}

int decimy(const string s, const int radix) {
    int sN;
    for (size_t i = 0; i < s.length(); i++) {
        sN += convert(s[i]) * pow(radix, s.length()-i-1);
    }
    return sN;
}

int main() {
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    string target, origin;
    if (tag == 1) {
        target = n2;
        origin = n1;
    } else {
        target = n1;
        origin = n2;
    }
    int originN = decimy(origin, radix);

    int radix_t = 1;    // target's init radix
    for (size_t i = 0; i < target.length(); i++) {
        if (convert(target[i]) > radix_t) radix_t = convert(target[i]);
    }
    radix_t += 1;
    while (decimy(target, radix_t) < originN) {
        radix++;
    }
    if (decimy(target, radix_t) == originN) {
        cout << radix_t << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
```

以为是int长度不够的问题，改了一下还是超时...

## ref sol 1