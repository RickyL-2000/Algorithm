#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int len = target.length();
        char pre = '0';
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (target[i] == pre) continue;
            pre = target[i];
            ans++;
        }
        return ans;
    }
};