#include <iostream>
#include <map>
using namespace std;

map<char, int> beads;
string given, need;
int given_len = 0, need_len = 0, lessN = 0;
bool found = true;

int main() {
    cin >> given >> need;
    for (size_t i = 0; i < given.length(); i++) {
        if (!beads.count(given[i])) {
            beads[given[i]] = 1;
        } else {
            beads[given[i]]++;
        }
        given_len++;
    }

    for (size_t i = 0; i < need.length(); i++) {
        if (!beads.count(need[i]) || beads[need[i]] == 0) {
            lessN++;
            found = false;
        } else {
            beads[need[i]]--;
        }
        need_len++;
    }

    if (found) {
        printf("Yes %d", given_len - need_len);
    } else {
        printf("No %d", lessN);
    }

    return 0;
}