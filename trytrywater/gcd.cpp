#include <iostream>
using namespace std;

int Abs(int x) {return x > 0 ? x : -x;}

int gcd(int a, int b) {
    return a == 0 ? Abs(b) : gcd(b % a, a);
}

int main() {
    int a = 50, b = 40;
    int x = gcd(a, b);
    cout << x;
    return 0;
}