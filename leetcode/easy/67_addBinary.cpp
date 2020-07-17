#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            swap(a, b);
        }
        b = string(a.length() - b.length(),'0') + b;
        int carry = 0, n = a.length();
        string ret(n, '0');
        int cur_a, cur_b;
        for (int i = n - 1; i >= 0; i--) {
            cur_a = a[i] - '0';
            cur_b = b[i] - '0';
            ret[i] = cur_a ^ cur_b ^ carry + '0';
            carry = (cur_a & cur_b) | (cur_a & carry) | (cur_b & carry);
        }
        if (carry > 0) ret = "1" + ret;
        return ret;
    }
};

int main() {
    string a = "11", b = "1";
    Solution s;
    cout << s.addBinary(a, b);
    return 0;
}