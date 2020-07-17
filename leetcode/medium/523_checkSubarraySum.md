# Continuous Subarray Sum

Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/continuous-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my solution 1    20/1/18     90 min

初学dp，总算是靠着对dp的理解自己独立把算法写出来了...

但是成绩不是很好看，提交了4遍才过了，关键是测试样例真的恶心。

成绩不好看的原因，貌似是这好像并不是真正的dp(?) 只是优化的暴力法

time    176     5.23%
mem     93.3    5.35%

```
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1) return false;

        if (!k) {
            int next;
            for (size_t i = 0; i < nums.size(); i++) {
                if (!nums[i] && i+1 < nums.size() && !nums[i+1]) {
                    return true;
                };
            }
            return false;
        }
        // 以上是为了健壮性，接下来是算法
        vector<vector<int>> books(nums.size()+1);
        books[0] = {0};
        books[1] = nums;
        int cur;
        for (size_t len = 2; len <= nums.size(); len++) {
            for (size_t i = 0; i <= nums.size() - len; i++) {
                cur = books[len-1][i] + nums[i+len-1];
                if (cur % k == 0) return true;
                books[len].push_back(cur);
            }
        }
        return false;
    }
};
```

## reference solution 1

前缀和余数法（？？？）

```
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (k == 0) {
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] == 0 && nums[i - 1] == 0) {
                    return true;
                }
            }
            return false;
        }
        k = abs(k);
        unordered_set<int> s{0};
        int t = nums[0] % k;
        for (int i = 1; i < nums.size(); ++i) {
            int t1 = t;
            t = (t + nums[i]) % k;
            if (s.count(t) > 0) {
                return true;
            }
            s.insert(t1); // 延迟更新，为了保证子数组长度至少为2
        }
        return false;
    }
};
```

貌似用了某种数论方面的数学技巧，但这怎么看也不像是dp题啊...

## my solution 2    20/1/18

只是一个不成熟的想法，就是每次计算len个连续数的和的时候都用k取模，然后在原数组上修改，相当于不断地缩小数组的size，直到有某一个更新过后的元素等于0(mod k)