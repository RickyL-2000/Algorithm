#include <iostream>
#include <string>
using namespace std;

const int MAXN = 100010;
char str[MAXN];
int preP[MAXN];
int preT[MAXN];
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
    int tempP = 0, tempT = 0;
    for (size_t i = head; i <= tail; i++) {
        if (str[i] == 'P') preP[i] = ++tempP;
        else if (str[i] == 'T') preT[i] = ++tempT;
        else { 
            preP[i] = tempP;
            preT[i] = tempT;
        }
    }

    for (size_t i = head; i <= tail; i++) {
        if (str[i] != 'A') continue;
        cnt += preP[i] * (preT[tail] - preT[i]);
        if (cnt > 1000000007) cnt %= 1000000007;
    }

    cout << cnt;

    return 0;
}