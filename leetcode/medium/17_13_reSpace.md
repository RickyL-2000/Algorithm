# 面试题 17.13. Re-Space LCCI

Oh, no! You have accidentally removed all spaces, punctuation, and capitalization in a lengthy document. A sentence like "I reset the computer. It still didn't boot!" became "iresetthecomputeritstilldidntboot''. You'll deal with the punctuation and capi­talization later; right now you need to re-insert the spaces. Most of the words are in a dictionary but a few are not. Given a dictionary (a list of strings) and the document (a string), design an algorithm to unconcatenate the document in a way that minimizes the number of unrecognized characters. Return the number of unrecognized characters.

Note: This problem is slightly different from the original one in the book.

Example:

Input: 
dictionary = ["looked","just","like","her","brother"]
sentence = "jesslookedjustliketimherbrother"
Output:  7
Explanation:  After unconcatenating, we got "jess looked just like tim her brother", which containing 7 unrecognized characters.
Note:

0 <= len(sentence) <= 1000
The total number of characters in dictionary is less than or equal to 150000.
There are only lowercase letters in dictionary and sentence.

## my sol 1     20/7/9

这道题和 139单词拆分 很像，但又很不一样，因为这个是要计算多余字母数量的...

我放弃了，我想不出什么非常好的方法...


## ref sol 1    20/7/9

动态规划 & 字典树

定义 dp[i] 表示考虑前 ii 个字符最少的未识别的字符数量，从前往后计算 dp 值。

考虑转移方程，每次转移的时候我们考虑第 j(j≤i) 个到第 ii 个字符组成的子串 sentence[j−1⋯i−1] （注意字符串下标从 00 开始）是否能在词典中找到，如果能找到的话按照定义转移方程即为 dp[i]=min(dp[i],dp[j−1]) 否则没有找到的话我们可以复用 dp[i−1] 的状态再加上当前未被识别的第 i 个字符，因此此时 dp 值为 dp[i]=dp[i−1]+1

最后问题化简成了转移的时候如何快速判断当前子串是否存在于词典中，与「单词拆分」类似我们可以选择用哈希表来优化，但笔者实测下来速度很慢，因为用哈希表来实现本身有两个问题，一个是哈希表本身的常数很大，还有一个是我们在枚举子串是否在词典中的时候有些其实是没有必要的枚举。简单举例，如果我们有词典：['aabc', 'babc', 'cbc'] ，但是我们在倒序枚举的时候检查 dc 这个子串没出现在词典中以后我们就没必要再接着往前枚举是否有合法的子串了，因为 dc 本身已经不是词典中「任意一个单词的后缀」，我们再接着枚举 *dc 或者 **dc 判断其是否在词典中都是无用功。

因此最终笔者选择了用字典树 Trie 来优化查找，Trie 是一种最大程度利用多个字符串前缀信息的数据结构，它可以在 O(w) 的时间复杂度内判断一个字符串是否是一个字符串集合中某个字符串的前缀，其中 w 代表字符串的长度。这里具体实现不再展开，我们只讲怎么使用。上文提到了哈希表实现的时候会出现很多冗余的判断，最关键的一点就是当前枚举的子串已经不再是词典中「任意一个单词的后缀」，这点我们可以利用 Trie 来解决。

我们将词典中所有的单词「反序」插入字典树中，然后每次转移的时候我们从当前的下标 ii 出发倒序遍历 i−1,i−2,⋯,0。在 Trie 上从根节点出发开始走，直到走到当前的字符 sentence[j] 在 Trie 上没有相应的位置，说明 sentence[j⋯i−1] 不存在在词典中，且它已经不是「任意一个单词的后缀」，此时我们直接跳出循环即可。否则，我们需要判断当前的子串是否是一个单词，这里我们直接在插入 Trie 的时候在单词末尾的节点打上一个 isEnd 的标记即可，这样我们在走到某个节点的时候就可以判断是否是一个单词的末尾并根据状态转移方程更新我们的 dp 值。

``` C++
class Trie {
public:
    Trie* next[26] = {nullptr};
    bool isEnd;
    
    Trie() {
        isEnd = false;
    }

    void insert(string s) {
        Trie* curPos = this;

        for (int i = s.length() - 1; i >= 0; --i) {
            int t = s[i] - 'a';
            if (curPos->next[t] == nullptr) {
                curPos->next[t] = new Trie();
            }
            curPos = curPos->next[t];
        }
        curPos->isEnd = true;
    }
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.length(), inf = 0x3f3f3f3f;

        Trie* root = new Trie();
        for (auto& word: dictionary) {
            root->insert(word);
        }

        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;

            Trie* curPos = root;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a';
                if (curPos->next[t] == nullptr) {
                    break;
                } else if (curPos->next[t]->isEnd) {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
                if (dp[i] == 0) {
                    break;
                }
                curPos = curPos->next[t];
            }
        }
        return dp[n];
    }
};
```

我的思考：这个算法还可以加入剪枝，或者已经被Trie优化掉了？
