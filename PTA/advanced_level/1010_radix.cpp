/**
 * 思路很简单，把给的数据转化成十进制，然后把target的每一位输入数组digits，同时记录最大digit
 * 然后多项式求和即可
 */
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

long long decimy(const string s, const int radix) {
    long long sN;
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
    long long originN = decimy(origin, radix);

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