# 32_longestValidParentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

## my sol 1     20/7/4  40 min

FAIL

初步想法：动态规划，遍历一遍记录左括号和右括号的前缀和，然后双指针

居然超出时间了？？我以为这个方法很快了

好的，这个测试样例是一大堆"("，这样用我的逻辑就是n^2的复杂度，难怪超出了时间(虽然我本地运行貌似挺快的)

## my sol 2     20/7/4  5 min

如果我加上一句判断 ```if (left[s.length()] == 0 || right[s.length()] == 0) return 0;``` 呢？

1352 ms 5.21%

7.9 mb  100 %

好嘛，这就过了？看来这个测试样例也不咋地啊，我就能想到一个能把我这个算法击败的测试样例，就是一大堆"("然后在最最后面加上一个")"，这样我的算法直接凉凉，超时。

``` C++
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> left(s.length() + 1, 0), right(s.length() + 1, 0);
        for (int i = 1; i <= s.length(); i++) {
            if (s[i-1] == '(') {
                left[i] = left[i-1] + 1;
                right[i] = right[i-1];
            } else {
                right[i] = right[i-1] + 1;
                left[i] = left[i-1];
            }
        }
        if (left[s.length()] == 0 || right[s.length()] == 0) return 0;
        int len = s.length();
        int begin = 0, end = 1, ans = 0;
        int ptr;
        bool flag;
        while (begin + ans < len) {
            // end = ans != 0 ? begin + ans : begin + 1;
            while (end < len && (left[end] - left[begin] > right[end] - right[begin])) {
                end++;
            }
            if (left[end] - left[begin] == right[end] - right[begin]) {
                flag = true;
                for (ptr = max(begin+1, ptr); ptr <= end; ptr++) {
                    if (right[ptr] - right[begin] > left[ptr] - left[begin]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = end - begin;
                    end = begin + ans + 1;
                    continue;
                }
            }
            begin++;
            ptr = begin;
            end = ans != 0 ? begin + ans : begin + 1;
        }
        return ans;
    }
};
```

## ref sol 1    20/7/4

动态规划

这个答案的动态规划比我的强太多了！这就是动规的精髓吗？

哦，这不就是离散里的递推公式吗？我离散已经忘了很多了...

首先，dp数组全部初始化为0，而且以'('结尾的子串对应的dp值必定为0

从前往后遍历字符串求解dp值，每两个字符检查一次：

1. s[i] = ')' 且 s[i-1] = '('，则 dp[i] = dp[i - 2] + 2
2. s[i] = ')' 且 s[i-1] = ')'，则：如果s[i - dp[i - 1] - 1] = '('，那么dp[i] = dp[i-1] + dp[i - 1 - dp[i-1] - 1] + 2，即加上s[i-1]所在的子串的长度，再加2，还要再加上s[i-1]所在的子串之前的有效子串的长度。

``` C++
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};
```

忘了很久的动态规划的精髓，即递推公式，终于在这道题想起来了！以前还算过什么铺地砖、0101串的题目！

## ref sol 2    20/7/4

不需要额外的空间

在此方法中，我们利用两个计数器 left 和 right 。首先，我们从左到右遍历字符串，对于遇到的每个 '('，我们增加 left 计数器，对于遇到的每个 ')' ，我们增加 right 计数器。每当 left 计数器与 right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串。当 right 计数器比 left 计数器大时，我们将 left 和 right 计数器同时变回 00。

这样的做法贪心地考虑了以当前字符下标结尾的有效括号长度，每次当右括号数量多于左括号数量的时候之前的字符我们都扔掉不再考虑，重新从下一个字符开始计算，但这样会漏掉一种情况，就是遍历的时候左括号的数量始终大于右括号的数量，即 (() ，这种时候最长有效括号是求不出来的。

解决的方法也很简单，我们只需要从右往左遍历用类似的方法计算即可，只是这个时候判断条件反了过来：

当 left 计数器比 right 计数器大时，我们将 left 和 right 计数器同时变回 00
当 left 计数器与 right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串
这样我们就能涵盖所有情况从而求解出答案。

``` C++
public class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
}
```

这个正向拟象遍历的算法，真的是学到了