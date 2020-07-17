#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i <= (int)sqrt((double)n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int reverse(int num, int radix) {
    vector<int> digits;
    while (num != 0) {
        digits.push_back(num % radix);  // the rightest digit
        num /= radix;
    }
    for (int i = 0; i < digits.size(); i++) {
        num += digits[i] * pow((float)radix, (float)(digits.size() - i - 1));
    }
    return num;
}

int main() {
    vector<string> ans;
    int num, radix;
    while (scanf("%d", &num) && num > 0) {
        scanf("%d", &radix);
        if (!isPrime(num)) {
            ans.push_back("No");
            continue;
        }
        num = reverse(num, radix);
        if (!isPrime(num)) {
            ans.push_back("No");
            continue;
        }
        ans.push_back("Yes");
    }

    for (size_t i = 0; i < ans.size(); i++) {
        printf("%s\n", ans[i].c_str());
    }

    return 0;
}