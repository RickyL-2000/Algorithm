#include <iostream>
using namespace std;

int main() {
    int cur;
    int pre = 0;
    int sum = 0;
    cin >> cur;
    while (cin >> cur) {
        if (cur > pre) {
            sum += (cur - pre) * 6;
        } else {
            sum += (pre - cur) * 4;
        }
        pre = cur;
        sum += 5;
    }
    cout << sum;
}