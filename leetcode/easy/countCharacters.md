# countCharacters

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my solution 1    20/1/14

FAIL!

```
class Solution {
public:
    bool sInString(string str, string s) {
        vector<int> book(str.size(), 1);
        int check;
        for (int i = 0; i < s.size(); i++) {
            check = 0;
            for (int j = 0; j < str.size(); j++) {
                if (book[i] && str[j] == s[i]) {
                    book[i] = 0;
                    check = 1;
                    break;
                } 
            }
            if (!check) return false;
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        int i, j;
        int check, sum = 0;
        for (i = 0; i < words.size(); i++) {
            if (sInString(chars,words[i])) {
                sum += words[i].size();
            }
        }
        return sum;
    }
};
```

Don't know why...


## my solution 2    20/1/15 20 min

原来是book[]里面的Index搞错了！！！！

time:   104 39.97%

memory: 29.6    100%

## reference solution 1

hash map:
> countCharacter2.cpp

```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> htc(26);
        for (char ch : chars) {
            htc[ch - 'a']++;
        }
        int ans = 0;
        for (string &w : words) {
            vector<int> htw(26);
            int i;
            for (i = 0; i < w.size(); i++) {
                if (++htw[w[i] - 'a'] > htc[w[i] - 'a']) {
                    break;
                }
            }
            if (i >= w.size()) {
                ans += w.size();
            }
        }
        return ans;
    }
};
```

## my solution 3    20/1/15

和上一个答案的性能几乎一样...

time    60  91.73%

memory  21.8    100%

```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        bool check;
        int sum = 0;
        for (string& str : words) {
            check = 1;
            vector<int> hmc(26, 0);
            for (auto c : chars) {
                hmc[c - 'a']++;
            }
            for (auto c : str) {
                if (hmc[c - 'a'] <= 0) {
                    check = 0;
                    break;
                }
                hmc[c - 'a']--;
            }
            if (check) {
                sum += str.length();
            }
        }
        return sum;
    }
};
```