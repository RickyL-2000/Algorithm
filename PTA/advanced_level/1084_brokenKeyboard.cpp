#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

int main() {
    string origin, typeout;
    cin >> origin >> typeout;
    map<char, int> book;
    string ans = "";
    char temp;
    for (size_t i = 0, j = 0; i < origin.length(); i++) {
        if (origin[i] == origin[j] ||
                (origin[i] != origin[j] && 
                (isalpha(origin[i]) && isalpha(origin[j]) && 
                (origin[i]-origin[j]=='A'-'a' || origin[j]-origin[i]=='A'-'a')))) {
            temp = islower(origin[i]) ? origin[i]+'A'-'a' : origin[i];
            if (!book.count(temp)) {
                book[temp] = 1;
            }
            j++;
        } else {
            if (book.count(origin[i]) || (islower(origin[i]) && book.count(origin[i]+'A'-'a'))) 
                continue;
            else {
                temp = islower(origin[i]) ? origin[i]+'A'-'a' : origin[i];
                book[temp] = 1;
                ans += temp;
            }
        }
        // 如果有时候打得出有时候打不出....emmmmm
        // @bug TODO
        cout << ans;
        return 0;
    }
}