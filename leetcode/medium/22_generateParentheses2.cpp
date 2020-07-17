#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int len = 0;    // length = 2 * len
    vector<string> ans;
    void backtrack(string cur, int left, int right) {
        if (cur.length() == 2 * len) {
            ans.push_back(cur);
            return;
        }
        if (left < len) {
            backtrack(cur + "(", left + 1, right);
        }
        if (right < left) {
            backtrack(cur + ")", left, right + 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        len = n;
        backtrack("", 0, 0);
        return ans;
    }
};