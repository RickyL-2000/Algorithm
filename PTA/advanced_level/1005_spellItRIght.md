# Spell it Right

## my sol 1     20/1/20     20 min

部分正确

真是想不通...为什么会错？？？

```
#include <iostream>
#include <sstream>
using namespace std;

int digits[3];

void printD(int d) {
    switch (d) {
        case 0: {printf("zero"); break;}
        case 1: {printf("one"); break;}
        case 2: {printf("two"); break;}
        case 3: {printf("three"); break;}
        case 4: {printf("four"); break;}
        case 5: {printf("five"); break;}
        case 6: {printf("six"); break;}
        case 7: {printf("seven"); break;}
        case 8: {printf("eight"); break;}
        case 9: {printf("nine"); break;}        
    }
}

int convert(char c) {
    stringstream stream;
    int result;
    stream << c;
    stream >> result;
    return result;
}

int main() {
    int sum = 0;
    char temp;
    while (scanf("%c", &temp) == 1) {
        int digit = convert(temp);
        sum += digit;
    }
    digits[0] = sum / 100;
    digits[1] = (sum / 10) % 10;
    digits[2] = sum % 10;
    if (!sum) {
        printD(0);
        return 0;
    } else if (sum / 10 == 0) {
        printD(digits[2]);
        return 0;
    } else if (sum / 100 == 0 && sum / 10 != 0) {
        printD(digits[1]);
        printf(" ");
        printD(digits[2]);
        return 0;
    } else if (sum / 100 != 0) {
        printD(digits[0]);
        printf(" ");
        printD(digits[1]);
        printf(" ");
        printD(digits[2]);
        return 0;
    }
}
```

不过说实在的，感觉自己确实思路被夹死了...这么简单一个程序写的好麻烦...

## ref sol 1

来自liu

```
#include <iostream>
using namespace std;
int main() {
    string a;
    cin >> a;
    int sum = 0;
    for (int i = 0; i < a.length(); i++)
        sum += (a[i] - '0');
    string s = to_string(sum);
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << arr[s[0] - '0'];
    for (int i = 1; i < s.length(); i++)
        cout << " " << arr[s[i] - '0'];
    return 0;
}
```

不得不说，先读入字符串再对字符串进行操作这个真的厉害！