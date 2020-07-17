#include <iostream>
#include <vector>
using namespace std;

int minSuffix(vector<string>& lines, int minLen, int num) {
    int index = 0;
    while (index < minLen) {
        char cur = lines[0][lines[0].length()-1-index];
        for (int i = 1; i < num; i++) {
            if (lines[i][lines[i].length()-1-index] != cur) {
                return index-1;
            }
        }
        index++;
    }
    return index-1;
}

int main() {
    int num;
    scanf("%d\n", &num);
    vector<string> lines(num, "");
    int minLen = 99999999;
    for (int i = 0; i < num; i++) {
        getline(cin, lines[i]);
        if (lines[i].length() < minLen) minLen = lines[i].length();
    }

    if (minLen == 0) { printf("nai");   return 0; }
    
    int index = minSuffix(lines, minLen, num);

    if (index == -1) { printf("nai");   return 0; }

    while (lines[0][lines[0].length()-1-index] == ' ') index--;
    int j = 0;
    while (lines[0][lines[0].length()-1-j] == ' ') j++;

    for (int i = index; i >= j; i--) {
        printf("%c", lines[0][lines[0].length()-1-i]);
    }

    return 0;
}