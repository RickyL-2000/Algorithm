# 41_firstMissingPositive

## my sol 1     20/6/27     15 min

8 ms    54.43%

6.8 mb  100%

啊这，这道题居然是hard？不是用一个set两边遍历就完了吗？

虽然说这个算法可能不算通常意义上的O(n)...不过我觉得强行说O(n)也是可以的

``` C++
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int minval = INT_MAX;
        set<int> check;
        for (int num : nums) {
            // if (num > 0 && num < minval) {
            //     minval = num;
            // }
            check.insert(num);
        }
        // if (minval > 1) return 1;
        int ret = 1;
        while (check.find(ret) != check.end()) {
            ret++;
        }
        return ret;
    }
};

int main() {}
```

## ref sol 1    20/6/27

不过确实，别人的算法更强

对于「前言」中提到的第一种做法：

我们可以将数组所有的数放入哈希表，随后从 11 开始依次枚举正整数，并判断其是否在哈希表中。

仔细想一想，我们为什么要使用哈希表？这是因为哈希表是一个可以支持快速查找的数据结构：给定一个元素，我们可以在 O(1)O(1) 的时间查找该元素是否在哈希表中。因此，我们可以考虑将给定的数组设计成哈希表的「替代产品」。

实际上，对于一个长度为 NN 的数组，其中没有出现的最小正整数只能在 [1, N+1][1,N+1] 中。这是因为如果 [1, N][1,N] 都出现了，那么答案是 N+1N+1，否则答案是 [1, N][1,N] 中没有出现的最小正整数。这样一来，我们将所有在 [1, N][1,N] 范围内的数放入哈希表，也可以得到最终的答案。而给定的数组恰好长度为 NN，这让我们有了一种将数组设计成哈希表的思路：

我们对数组进行遍历，对于遍历到的数 xx，如果它在 [1, N][1,N] 的范围内，那么就将数组中的第 x-1x−1 个位置（注意：数组下标从 00 开始）打上「标记」。在遍历结束之后，如果所有的位置都被打上了标记，那么答案是 N+1N+1，否则答案是最小的没有打上标记的位置加 11。

那么如何设计这个「标记」呢？由于数组中的数没有任何限制，因此这并不是一件容易的事情。但我们可以继续利用上面的提到的性质：由于我们只在意 [1, N][1,N] 中的数，因此我们可以先对数组进行遍历，把不在 [1, N][1,N] 范围内的数修改成任意一个大于 NN 的数（例如 N+1N+1）。这样一来，数组中的所有数就都是正数了，因此我们就可以将「标记」表示为「负号」。算法的流程如下：

我们将数组中所有小于等于 00 的数修改为 N+1N+1；

我们遍历数组中的每一个数 xx，它可能已经被打了标记，因此原本对应的数为 |x|∣x∣，其中 |\,|∣∣ 为绝对值符号。如果 |x| \in [1, N]∣x∣∈[1,N]，那么我们给数组中的第 |x| - 1∣x∣−1 个位置的数添加一个负号。注意如果它已经有负号，不需要重复添加；

在遍历完成之后，如果数组中的每一个数都是负数，那么答案是 N+1N+1，否则答案是第一个正数的位置加 11。

``` C++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```
