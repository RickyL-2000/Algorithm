#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while (num / 10 != 0 && num != 0) {
            while (num / 10 != 0 && num != 0) {
                sum += num % 10;
                num = num / 10;
            }
            sum += num;
            num = sum;
            sum = 0;
        }
        sum += num;
        return sum;
    }
    void test(int num) {
        int ans = addDigits(num);
        cout << ans << endl;
    }
};

int main() {
    Solution s1;
    s1.test(38);
    return 0;
}