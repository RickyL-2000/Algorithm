// FIXME can't one test point

#include <iostream>
using namespace std;

int dp[10050][2];   // dp[0] first val, dp[1] last val

int main() {
    int k;
    cin >> k;

    int thisSum, cur, maxIndex = 0, maxN;
    if (k) cin >> thisSum;
    dp[0][0] = dp[0][1] = maxN = thisSum;

    bool allNegative = true;
    int first = dp[0][0], last = dp[0][0];
    for (int i = 1; i < k; i++) {
        cin >> cur;
        if (cur >= 0) allNegative = false;
        if (i == k-1) last = cur;
        if (thisSum < 0) {
            dp[i][0] = dp[i][1] = cur;
            thisSum = cur;
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = cur;
            thisSum += cur;  
        }
        if (thisSum > maxN) {
            maxIndex = i;
            maxN = thisSum;
        }
    }
    if (allNegative) {
        cout << 0 << ' ' << first << ' ' << last << endl;
    } else
        cout << maxN << ' ' << dp[maxIndex][0] << ' ' << dp[maxIndex][1] << endl;
    return 0;
}