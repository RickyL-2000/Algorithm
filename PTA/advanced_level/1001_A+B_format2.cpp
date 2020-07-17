#include <iostream>
#include <string>
using namespace std;

int main() {
    long int a, b;
    scanf("%ld %ld", &a, &b);
    string ret = to_string(a+b);
    int len = ret.length();
    for (int i = 0; i < len; i++) {
        printf("%c", ret[i]);
        if (ret[i] == '-') continue;
        if ((i+1) % 3 == len % 3 && i != len - 1) printf(",");
    }
    return 0;
}