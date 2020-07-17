# 22_generateParentheses

## my sol 1     20/6/24

想了很久也没有实际想出一个办法...肯定是结构递归，但是总是想不好怎么写...

## ref sol 1    20/6/26

``` C++
class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
```

grass，这个方法确实妙，把我的思想非常好地表达了出来。这个backtrack确实经典

为了更好地理解，我觉得我需要自己再写一遍。


## my sol 1     20/6/26     10 min

12 ms   32.83%

15.2 mb 53.49%

重写成功！

``` C++
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
```
