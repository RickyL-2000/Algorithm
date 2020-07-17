#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    void test() {
        vector<string> words1 = {"dyiclysmffuhibgfvapygkorkqllqlvokosagyelotobicwcmebnpznjbirzrzsrtzjxhsfpiwyfhzyonmuabtlwin",
                                "ndqeyhhcquplmznwslewjzuyfgklssvkqxmqjpwhrshycmvrb",
                                "ulrrbpspyudncdlbkxkrqpivfftrggemkpyjl",
                                "boygirdlggnh",
                                "xmqohbyqwagkjzpyawsydmdaattthmuvjbzwpyopyafphx",
                                "nulvimegcsiwvhwuiyednoxpugfeimnnyeoczuzxgxbqjvegcxeqnjbwnbvowastqhojepisusvsidhqmszbrnynkyop",
                                "hiefuovybkpgzygprmndrkyspoiyapdwkxebgsmodhzpx",
                                "juldqdzeskpffaoqcyyxiqqowsalqumddcufhouhrskozhlmobiwzxnhdkidr",
                                "lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo",
                                "oxgaskztzroxuntiwlfyufddl",
                                "tfspedteabxatkaypitjfkhkkigdwdkctqbczcugripkgcyfezpuklfqfcsccboarbfbjfrkxp",
                                "qnagrpfzlyrouolqquytwnwnsqnmuzphne",
                                "eeilfdaookieawrrbvtnqfzcricvhpiv",
                                "sisvsjzyrbdsjcwwygdnxcjhzhsxhpceqz",
                                "yhouqhjevqxtecomahbwoptzlkyvjexhzcbccusbjjdgcfzlkoqwiwue",
                                "hwxxighzvceaplsycajkhynkhzkwkouszwaiuzqcleyflqrxgjsvlegvupzqijbornbfwpefhxekgpuvgiyeudhncv",
                                "cpwcjwgbcquirnsazumgjjcltitmeyfaudbnbqhflvecjsupjmgwfbjo",
                                "teyygdmmyadppuopvqdodaczob",
                                "qaeowuwqsqffvibrtxnjnzvzuuonrkwpysyxvkijemmpdmtnqxwekbpfzs",
                                "qqxpxpmemkldghbmbyxpkwgkaykaerhmwwjonrhcsubchs"};
        string chars = "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp";
        vector<string> words2 = {"boygirdlggnh"};
        vector<string> words3 = {"lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo"};
        int ans = countCharacters(words1, chars);
        cout << ans << endl;
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}