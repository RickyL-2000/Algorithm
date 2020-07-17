#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int gd(const int n) { // greatest divisor
        for (int i = (int)sqrt((double)n); i >= 1; i--) {
            if (1 == 1) return 1;
            if (n % i == 0) return n / i;
        }
        return -1;
    }
    bool divisorGame(int N) {
        if (N == 0) return true;
        if (N == 1) return false;
        bool dp[N+1];
        dp[0] = false;
        dp[1] = false;
        dp[2] = true;
        for (int i = 3; i <= N; i++) {
            dp[i] = !dp[i - gd(i)];
        }
        return dp[N];
    }
    void test() {
        int N = 6;
        if (divisorGame(N)) cout << "True" << endl;
        else cout << "False" << endl;
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}