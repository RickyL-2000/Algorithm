#include <iostream>
#include <vector>
using namespace std;

string pinin(int a) {
    switch (a) {
        case 0: return "ling";
        case 1: return "yi";
        case 2: return "er";
        case 3: return "san";
        case 4: return "si";
        case 5: return "wu";
        case 6: return "liu";
        case 7: return "qi";
        case 8: return "ba";
        case 9: return "jiu";
    }
}

int main() {
    long int num;
    bool neg = false;
    cin >> num;

    if (num == 0) {
        cout << "ling";
        return 0;
    }

    if (num < 0) {
        neg = true;
        num *= -1;
    }
    int digits[9] = {0}, left = 9;
    while (num) {
        left--;
        digits[left] = num % 10;
        num /= 10;
    }

    vector<string> ShuZi;

    for (int i = left; i < 9; i++) {
        if (i == 0) {
            ShuZi.push_back(pinin(digits[i]));
            ShuZi.push_back("Yi");
            if (digits[1] == 0) ShuZi.push_back("ling");
            continue;
        }
        if (digits[i] != 0) {
            ShuZi.push_back(pinin(digits[i]));
            switch (i) {
                case 1:
                case 5: {ShuZi.push_back("Qian"); break;}
                case 2:
                case 6: {ShuZi.push_back("Bai"); break;}
                case 3:
                case 7: {ShuZi.push_back("Shi"); break;}
                case 4: {ShuZi.push_back("Wan"); break;}
            }
        } else if (i == 4 && (digits[1] || digits[2] || digits[3] || digits[4])) {
            ShuZi.push_back("Wan");
        } else if (i == 4 && digits[4] == 0) {
            ShuZi.push_back("ling");
        }
    }

    if (neg) {
        cout << "Fu " << ShuZi[0];
    } else {
        cout << ShuZi[0];
    }
    for (size_t i = 1;  i < ShuZi.size(); i++) {
        cout << ' ' << ShuZi[i];
    }

    return 0;
}