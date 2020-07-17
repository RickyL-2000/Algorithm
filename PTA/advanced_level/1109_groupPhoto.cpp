#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
    string _name;
    int _height;
    //Person(string name, int h): _name(name), _height(h) {}
};

const int MAXN = 1e4 + 50;
Person* group[MAXN];
Person* row[MAXN];
int n, k, row_len, len;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        Person* p = new Person;
        cin >> p->_name;
        scanf("%d", &p->_height);     // @bug
        group[i] = p;
    }
    sort(group, group + n, [](Person* p1, Person* p2) {
        if (p1->_height > p2->_height) return true;
        if (p1->_height == p2->_height && p1->_name < p2->_name) return true;   // @bug
        return false;
    });
    int group_i = 0;
    row_len = n / k;
    for (int row_i = 0; row_i < k; row_i++) {
        if (row_i == 0) {
            len = row_len + n - k * row_len;
            group_i = 0;
        } else {
            group_i += len;
            len = row_len;
        }
        int temp_i = group_i + 1;
        for (int j = len / 2 - 1; j >= 0; j--) {
            row[j] = group[temp_i];
            temp_i += 2;
        }
        temp_i = group_i;
        for (int j = len / 2; j < len; j++) {
            row[j] = group[temp_i];
            temp_i += 2;
        }
        for (size_t j = 0; j < len; j++) {
            if (j != 0) printf(" ");
            printf("%s", row[j]->_name.c_str());
        }
        if (row_i != k-1) printf("\n");
    }

    return 0;
}