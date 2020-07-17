# Divisor Game

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divisor-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my solution 1    20/1/18     30 min

FAIL!

```
class Solution {
public:
    int gd(const int n) { // greatest divisor
        for (int i = (int)sqrt((double)n); i >= 1; i--) {
            if (i == 1) return 1;
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
};
```

我傻了，原本以为这是一道动态规划题，但是...这个**optimal**的理解实在是气人啊！

原来这是一道数学题啊！！！

## reference solution 1

如果N是奇数，因为奇数的所有因数都是奇数，因此 N 进行一次 N-x 的操作结果一定是偶数，所以如果 a 拿到了一个奇数，那么轮到 b 的时候，b拿到的肯定是偶数，这个时候 b 只要进行 -1， 还给 a 一个奇数，那么这样子b就会一直拿到偶数，到最后b一定会拿到最小偶数2，a就输了。

所以如果游戏开始时Alice拿到N为奇数，那么她必输，也就是false。如果拿到N为偶数，她只用 -1，让bob 拿到奇数，最后bob必输，结果就是true。

```
bool divisorGame(int N) {
    return !(N&1);
}
```
