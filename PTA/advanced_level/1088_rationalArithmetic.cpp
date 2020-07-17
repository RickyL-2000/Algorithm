#include <iostream>
using namespace std;

long int Abs(long int x) {return x > 0 ? x : -x;}

long int gcd(long int a, long int b) {
    return a == 0 ? Abs(b) : gcd(b % a, a);
}

struct RatN {
    int _k = 0;
    long int _num;
    long int _den;
    RatN() = default;
    RatN(int k, long int num, long int den) : _k(k), _num(num),  _den(den) {
        this->simplify();
    }
    void print() {
        if (_num < 0 || _k < 0) cout << '(';
        if (!_num)  cout << _k;
        else {
            if (_k)  printf("%ld %ld/%ld", _k, _num, _den);
            else printf("%ld/%ld", _num, _den);
        }
        if (_num < 0 || _k < 0) cout << ')';
    }
    RatN* neg() {
        return _k == 0 ? new RatN(_k, -_num, _den) : new RatN(-_k, _num, _den);
    }
    void simplify() {
        _k += _num / _den;
        _num %= _den;
        _num /= gcd(Abs(_num), _den);
        _den /= gcd(Abs(_num), _den);
        if (_num < 0) {_num *= -1; _k *= -1;}
    }
    RatN* reverse() {
        return new RatN(0, _den, _k * _den + _num);
    }
    bool divZ() {
        return _den == 0;
    }
    bool isZero() {return _k == 0 && _num == 0;}

};

RatN* plusR(RatN* num1, RatN* num2) {
    RatN* result = new RatN;
    result->_k = num1->_k + num2->_k;
    long int scm = num1->_den / gcd(num1->_den, num2->_den) * num2->_den;
    result->_den = scm;
    result->_num = num1->_num * (scm / num1->_den) + num2->_num * (scm / num2->_den);
    result->simplify();
    return result;
}

RatN* prodR(RatN* num1, RatN* num2) {
    if (num2->divZ()) return nullptr;
    if (num1->isZero() || num2->isZero()) return new RatN(0, 0, 1);
    RatN* result = new RatN;
    result->_num = (num1->_k * num1->_den + num1->_num) * (num2->_k * num2->_den + num2->_num);
    result->_den = num1->_den * num2->_den;
    result->_k = 0;
    result->simplify();
    return result;
}

int main() {
    RatN* num1 = new RatN, *num2 = new RatN;
    scanf("%ld/%ld %ld/%ld", &(num1->_num), &(num1->_den), &(num2->_num), &(num2->_den));
    num1->simplify();
    num2->simplify();

    RatN* plusResult = plusR(num1, num2);
    RatN* diffResult = plusR(num1->neg(), num2);
    RatN* prodResult = prodR(num1, num2);
    RatN* divideResult = prodR(num1, num2->reverse());

    num1->print();
    cout << " + ";
    num2->print();
    cout << " = ";
    plusResult->print();
    cout << endl;

    num1->print();
    cout << " - ";
    num2->print();
    cout << " = ";
    diffResult->print();
    cout << endl;

    num1->print();
    cout << " * ";
    num2->print();
    cout << " = ";
    prodResult->print();
    cout << endl;

    num1->print();
    cout << " / ";
    num2->print();
    cout << " = ";
    if (divideResult->divZ()) cout << "Inf";
    else divideResult->print();

    return 0;
}