#include <iostream>
using namespace std;

int array[100050];

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &array[i]);
    }
    int sum = 0, ans = 0;
    for (int i = 0; i < k; i++) {
        sum += array[i];
        sum = sum < 0 ? 0 : sum;
        ans = ans < sum ? sum : ans;
    }
    printf("%d", ans);
    return 0;
}