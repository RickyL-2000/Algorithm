// 看姥姥的课程记的笔记~
// 计算多项式在某点x的值的问题，主要思想就是从里往外算：
// p = a0 + x(a1 + x(a2 + ... + x(an-1 + x(an))...)
#include <iostream>
#include <vector>
using namespace std;
double polynomial(int, vector<double>, double);

int main() {
    vector<double> coeffs = {0, 1};
    double value = polynomial(1, coeffs, 1);
    cout << value << endl;
}

double polynomial(int n, vector<double> coeffs, double x) {
    double sum = coeffs[n];
    for (int i = n-1; i != -1; --i) {
        sum = coeffs[i] + x*sum;
    }
    return sum;
}