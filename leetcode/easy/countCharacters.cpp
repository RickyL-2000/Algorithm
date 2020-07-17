#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool sInString(string str, string s) {
        vector<int> book(str.length(), 1);
        int check;
        for (int i = 0; i < s.length(); i++) {
            check = 0;
            for (int j = 0; j < str.length(); j++) {
                if (book[j] && str[j] == s[i]) {
                    book[j] = 0;
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
                sum += words[i].length();
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