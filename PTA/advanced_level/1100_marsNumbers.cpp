#include <iostream>
#include <vector>
#include <string>
using namespace std;

string digits[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high_digits[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
vector<string> nums;
int n;

int main() {
    cin >> n;
    int dec_num, index1, index2;
    bool found;
    string num = "", str1, str2, mar_num;
    getline(cin, num);
    for (int i = 0; i < n; i++) {
        getline(cin, num);
        nums.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        num = nums[i];
        if (isdigit(num[0])) {
            mar_num = "";
            sscanf(num.c_str(), "%d", &dec_num);
            index1 = dec_num / 13;
            if (index1 == 0) mar_num = digits[dec_num];
            else if (dec_num - index1 * 13 == 0) mar_num = high_digits[index1];
            else mar_num = high_digits[index1] + " " + digits[dec_num - index1 * 13];
            cout << mar_num << endl;
        } else {
            if (num.size() > 4) {
                str1 = num.substr(0, 3);
                str2 = num.substr(4, 3);
                for (index1 = 1; index1 < 13; index1++) {
                    if (high_digits[index1] == str1) break;
                }
                for (index2 = 0; index2 < 13; index2++) {
                    if (digits[index2] == str2) break;
                }
                dec_num = index1 * 13 + index2;
            } else {
                str2 = num;
                found = false;
                for (index2 = 0; index2 < 13; index2++) {
                    if (digits[index2] == str2) {
                        found = true;
                        break;
                    }
                }
                if (found) dec_num = index2;
                else {
                    for (index1 = 1; index1 < 13; index1++) {
                        if (high_digits[index1] == str2) {
                            found = true;
                            dec_num = index1 * 13;
                            break;
                        }
                    }
                }
            }
            cout << dec_num << endl;
        }
    }
    return 0;
}