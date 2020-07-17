#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int in, num, rem;
    char c;
    cin >> in >> c;
    num = (int) sqrt((double)(in+1)/2);
    rem = in - 2*num*num + 1;
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < i; j++) {
            cout << ' ';
        }
        for (j = 0; j < 2*num-1-2*i; j++) {
            cout << c;
        }
        cout << endl;
    }
    for (i = 1; i < num; i++) {
        for (j = num-i-1; j > 0; j--) {
            cout <<  ' ';
        }
        for (j = 0; j < 2*i+1; j++) {
            cout << c;
        }
        cout << endl;
    }
    cout << rem << endl;
    return 0;
}