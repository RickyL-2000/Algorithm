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