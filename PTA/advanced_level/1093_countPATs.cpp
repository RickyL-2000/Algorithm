/**
 * 计算A的个数的前缀和！ 
 */

#include <iostream>
#include <string>
using namespace std;

char str[100010];
int preA[100010];
int n;

int main() {
    long int cnt = 0;
    int index = 0;
    char ch;
    while (scanf("%c", &ch) == 1 && ch != EOF) {
        str[index] = ch;
        index++;
        n++;
    }

    // cutting head and tail
    size_t head = 0, tail =  n - 1;
    while (str[head] != 'P') {
        head++;
    }
    while (str[tail] != 'T') {
        tail--;
    }

    // forming prefix sum
    int temp = 0;
    for (size_t i = head; i <= tail; i++) {
        if (str[i] == 'A') preA[i] = ++temp;
        else preA[i] = temp;
    }

    for (size_t i = head; i <= tail; i++) {
        if (str[i] != 'P') continue;
        for (size_t j = tail; j > i; j--) {
            if (str[j] != 'T') continue;
            cnt += preA[j] - preA[i];
        }
    }

    cout << cnt % 1000000007;

    return 0;
}