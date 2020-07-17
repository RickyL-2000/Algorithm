#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int num_a = 0, num_b = 0;
        for (char ch : pattern) {
            if (ch == 'a') num_a++;
            if (ch == 'b') num_b++;
        }        
        if (value.length() == 0 && (num_a == 0 || num_b == 0)) return true;
        else if (value.length() == 0 && num_a > 0 && num_b > 0) return false;
        if (pattern.length() == 0) return false;
        int len_a, len_b;
        string a, b, temp;
        int idx;
        bool notMatch;
        if (num_a == 0) {
            len_b = value.length() / num_b;
            b = value.substr(0, len_b);
            idx = len_b;
            while (idx + len_b <= value.length()) {
                temp = value.substr(idx, len_b);
                if (temp != b) return false;
                idx += len_b;
            }
            return true;
        } else if (num_b == 0) {
            len_a = value.length() / num_a;
            a = value.substr(0, len_a);
            idx = len_a;
            while (idx + len_a <= value.length()) {
                temp = value.substr(idx, len_a);
                if (temp != a) return false;
                idx += len_a;
            }
            return true;
        }
        len_a = 0; 
        len_b = value.length() / num_b;
        while (len_a * num_a + len_b * num_b != value.length() && len_b >= 0) {
            len_a++;
            len_b = (value.length() - len_a * num_a) / num_b;
        }
        if (len_b < 0) return false;
        while (len_b >= 0) {
            notMatch = false;
            a = "0";
            b = "0";
            idx = 0;
            for (auto ch : pattern) {
                if (ch == 'a') {
                    temp = value.substr(idx, len_a);
                    if (a != "0" && a != temp) { 
                        notMatch = true;
                        break;
                    }
                    if (a == "0") a = temp;
                    idx += len_a;
                } else {
                    temp = value.substr(idx, len_b);
                    if (b != "0" && b != temp) {
                        notMatch = true;
                        break;
                    }
                    if (b == "0") b = temp;
                    idx += len_b;
                }
            }
            if (notMatch) {
                len_a++;
                len_b = (value.length() - len_a * num_a) / num_b;
                while (len_a * num_a + len_b * num_b != value.length()) {
                    len_a++;
                    len_b = (value.length() - len_a * num_a) / num_b;
                }
                continue;
            } else return true;
        }
        return false;
    }
};

int main() {
    string pattern = "bbbaa";
    string value = "xxxxxxy";
    Solution s;
    cout << s.patternMatching(pattern, value);
    return 0;
}