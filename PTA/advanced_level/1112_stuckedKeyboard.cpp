#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string target;
int rep[1010];
int k;
map<char, int> isStuck; // -1 not sure, 0 not, 1 yes
map<char, bool> have_printed;

int main() {
    fill(rep, rep+1010, 1);
    cin >> k >> target;
    isStuck[target[0]] = -1;
    for (size_t i = 1; i < target.length(); i++) {
        if (target[i] == target[i-1]) {
            rep[i] = rep[i-1] + 1;
        }
        isStuck[target[i]] = -1;
    }
    int index = target.length()-1;
    while (index >= 0) {
        if (rep[index] > 1) {
            for (int i = index; i > index - rep[index]; i--) {
                rep[i] = rep[index];
            }
            index = index - rep[index];
        } else index--;
    }
    for (size_t i = 0; i < target.length(); i++) {
        if (rep[i] % k != 0) {
            isStuck[target[i]] = 0;
        }
    }
    for (size_t i = 0; i < target.length(); i++) {
        if (rep[i] % k == 0 && isStuck[target[i]] != 0) {
            isStuck[target[i]] = 1;
            if (have_printed.count(target[i]) == 0) {
                printf("%c", target[i]);
                have_printed[target[i]] = 1;
            }
        }
    }
    printf("\n");
    for (size_t i = 0; i < target.length(); i++) {
        printf("%c", target[i]);
        if (isStuck[target[i]] == 1) i += k-1;
    }
    return 0;
}