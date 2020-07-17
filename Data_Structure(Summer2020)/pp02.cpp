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
    // int left = 0, right = 0, temp_left = 0;
    // for (int i = 0; i < k; i++) {
    //     sum += array[i];
    //     if (sum < 0) {
    //         sum = 0;
    //         temp_left = i+1;
    //     }
    //     // sum = sum < 0 ? 0 : sum;
    //     //ans = ans < sum ? sum : ans;
    //     if (ans < sum) {
    //         ans = sum;
    //         left = temp_left;
    //         right = i;
    //     }
    // }
    int left = k, right = k, temp_right = k-1;
    bool isNegative;
    for (int i = k-1; i >= 0; i--) {
        sum += array[i];
        isNegative = false;
        if (sum < 0) {
            isNegative = true;
            sum = 0;
            temp_right = i-1;
        }
        if (ans <= sum && !isNegative) {
            ans = sum;
            right = temp_right;
            left = i;
        }
    }
    while (right > left && array[right] == 0) right--;
    if (ans == 0 && (left == k || right == k)) printf("0 %d %d", array[0], array[k-1]);
    else printf("%d %d %d", ans, array[left], array[right]);
    return 0;
}