#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


template<class out_t, class in_t>
out_t convert(const in_t& t) {
    stringstream stream;
    out_t result;
    stream << t;
    stream >> result;
    return result;
}

void printN(const vector<int>& num) {
    int init = 1;
    if (num[0]) init = 0;
    for (unsigned int i = init; i < num.size(); i++) {  // ignore the top digit
        cout << num[i];
    }
    cout << endl;
}

vector<int> doubleN(const vector<int>& num) {
    int carry = 0;
    vector<int> new_arr(num);
    for (int i = num.size()-1; i >= 0; i--) {
        new_arr[i] = num[i]*2 + carry;
        carry = new_arr[i] / 10;
        new_arr[i] = new_arr[i] - 10*carry;
    }
    return new_arr;
}

bool d_in_arr(int d, const vector<int>& arr, vector<int>& book) {
    for (unsigned int i = 1; i < arr.size(); i++) {
        if (d == arr[i] && book[i]) {
            book[i] = 0;
            return true;
        }
    }
    return false;
}

bool isPermutation(const vector<int>& num1, const vector<int>& num2) {
    vector<int> book(num2.size(), 1);
    for (unsigned int i = 1; i < num1.size(); i++) {
        if (!d_in_arr(num1[i], num2, book)) {
            return false;
        }
    }
    return true;
}

int main() {
    char c;
    int d;
    vector<int> num1;
    stringstream stream;
    num1.push_back(0);  // 最高位，用于进位的可能性

    while (cin >> c && c != EOF) {
        d = convert<int>(c);
        num1.push_back(d);
    }

    // printN(num1);   // for debug

    vector<int> num2 = doubleN(num1);

    if (num1[1] > 5 || num2[0]) {
        cout << "No" << endl;
        printN(num2);
        return 0;
    }

    if (isPermutation(num1, num2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    printN(num2);

    return 0;
}