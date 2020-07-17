#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse (int x) {
        long long ret;
        string str = to_string(x);
        if (*str.begin() == '-') {
            std::reverse(str.begin()+1, str.end());
        } else {
            std::reverse(str.begin(), str.end());
        }
        stringstream ss;
        ss << str;
        ss >> ret;
        if (ret > INT_MAX || ret < INT_MIN) return 0;
        return ret;
    }
};

int main() {
    Solution s;
    printf("%d", s.reverse(-120));
    return 0;
}