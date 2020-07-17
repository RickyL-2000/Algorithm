# Distribute Candies

Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.

Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 

## my solution 1    20/1/13 20 min

FAIL!

```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size();
        int i, cnt = 1, pre = candies[0];
        for (i = 1; i < n; i++) {
            if (cnt >= n / 2) break;
            if (candies[i] != pre) {
                pre = candies[i];
                cnt++;
            }
        }
        return cnt;
    }
};
```

想得不够仔细啊！

[100000,0,100000,0,100000,0,100000,0,100000,0,100000,0]

👆这个测试样例就把我搞了！

## my solution 2    20/1/13

比较种类的数量和总数一半的数量：

```
#include <set>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size();
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(candies[i]);
        }
        int cnt = s.size();
        if (cnt >= n/2) return n/2;
        return cnt;
    }
};
```

但是这种方法比较慢，更好的方法是先排序，然后再遍历一遍计数。