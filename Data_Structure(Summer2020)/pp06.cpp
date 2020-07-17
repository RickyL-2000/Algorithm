/*
 * 03-树1 树的同构
 * */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int input[12][3];   // input['A'][0] - left
int tree1[26][2];
int tree2[26][2];

int main() {
    fill(tree1[0], tree1[0] + 26 * 2, -2);
    fill(tree2[0], tree2[0] + 26 * 2, -2);
    int n1, n2;
    char val, ch_left, ch_right;
    int left, right;
    int root1, root2;
    scanf("%d", &n1);
    vector<bool> visited(n1, false);
    for (int i = 0; i < n1; i++) {
        // scanf("%c %c %c", &val, &ch_left, &ch_right);
        cin >> val >> ch_left >> ch_right;
        input[i][0] = val - 'A';
        input[i][1] = ch_left == '-' ? -1 : ch_left - '0';
        input[i][2] = ch_right == '-' ? -1 : ch_right - '0';
    }
    for (int i = 0; i < n1; i++) {
        tree1[input[i][0]][0] = input[i][1] == -1 ? -1 : input[input[i][1]][0];
        tree1[input[i][0]][1] = input[i][2] == -1 ? -1 : input[input[i][2]][0];
        if (input[input[i][1]][0] != -1) visited[input[input[i][1]][0]] = true;
        if (input[input[i][2]][0] != -1) visited[input[input[i][2]][0]] = true;
    }
    for (int i = 0; i < n1; i++) {
        if (visited[i] == false) {
            root1 = i;
            break;
        }
    }

    scanf("%d\n", &n2);
    if (n1 != n2) {
        printf("No");
        return 0;
    }
    visited = vector<bool> (n2, false);
    for (int i = 0; i < n2; i++) {
        // scanf("%c %c %c", &val, &ch_left, &ch_right);
        cin >> val >> ch_left >> ch_right;
        input[i][0] = val - 'A';
        input[i][1] = ch_left == '-' ? -1 : ch_left - '0';
        input[i][2] = ch_right == '-' ? -1 : ch_right - '0';
    }
    for (int i = 0; i < n2; i++) {
        tree2[input[i][0]][0] = input[i][1] == -1 ? -1 : input[input[i][1]][0];
        tree2[input[i][0]][1] = input[i][2] == -1 ? -1 : input[input[i][2]][0];
        if (input[input[i][1]][0] != -1) visited[input[input[i][1]][0]] = true;
        if (input[input[i][2]][0] != -1) visited[input[input[i][2]][0]] = true;
    }
    for (int i = 0; i < n1; i++) {
        if (visited[i] == false) {
            root2 = i;
            break;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (((tree1[i][0] != tree2[i][0]) && (tree1[i][1] != tree2[i][1])) &&
            ((tree1[i][0] != tree2[i][1]) && (tree1[i][1] != tree2[i][0]))) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
