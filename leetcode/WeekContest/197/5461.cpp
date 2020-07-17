#include <iostream>
using namespace std;

class Solution {
public:
    int sum_add(int num) {
        int ans = 0;
        for (int i = 1; i <= num; i++) {
            ans += i;
            ans %= 1000000007;
        }
        return ans;
    }
    int numSub(string s) {
        int left = -1, right = -1;
        int ans = 0;
        while (left <= right && right < (int) s.length()) {
            left = right + 1;
            while (s[left] == '0' && left < s.length()) left++;
            if (left == s.length()) break;
            right = left;
            while (s[right] == '1' && right < s.length()) right++;
            right--;
            ans += sum_add(right-left+1);
            ans %= 1000000007;
        }
        return ans;
    }
};

int main() {
    string str = "0110111";
    Solution s;
    cout << s.numSub(str);
    return 0;
}