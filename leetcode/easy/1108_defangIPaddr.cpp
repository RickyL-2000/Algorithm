#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        for (auto it = address.begin(); it != address.end(); it++) {
            if (*it == '.') {
                it = address.insert(it, '[');
                it = address.insert(it+2, ']');
            }
        }
        return address;
    }
    void test() {
        string address1 = "1.1.1.1";
        string address2 = "255.100.50.0";
        string ans = defangIPaddr(address2);
        printf("%s", ans.c_str());
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}