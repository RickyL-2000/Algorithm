# Add Digits

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.


## my solution 1 20/1/10 20 min

4 ms

8.2 mb

```c++
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
```

## reference solution 1

对9取余？？？？？？

```c++
class Solution {
public:
    int addDigits(int num) {
        return num % 9 == 0 ? 9 : num % 9;
    }
};
```