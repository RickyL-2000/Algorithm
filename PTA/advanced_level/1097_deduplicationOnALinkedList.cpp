#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int _key;
    int _next;
    Node() = default;
    Node(int k, int n): _key(k), _next(n) {}
};
Node* nodes[100010];
int book[10010];
int root, n, remove_root = -1;

int main() {
    cin >> root >> n;
    fill(nodes, nodes+n, nullptr);
    int address, key, next;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &key, &next);
        nodes[address] = new Node(key, next);
    }

    int ptr = root, pre_ptr = -1, remove_ptr;
    while (ptr != -1) {
        if (book[abs(nodes[ptr]->_key)] == false) {
            book[abs(nodes[ptr]->_key)] = true;
            pre_ptr = ptr;
            ptr = nodes[ptr]->_next;
        } else {
            if (remove_root == -1) {
                remove_root = ptr;
                remove_ptr = remove_root;
            } else {
                nodes[remove_ptr]->_next = ptr;
                remove_ptr = ptr;
            }
            nodes[pre_ptr]->_next = nodes[ptr]->_next;
            ptr = nodes[ptr]->_next;
            nodes[remove_ptr]->_next = -1;
        }
    }

    ptr = root, remove_ptr = remove_root;
    while (ptr != -1) {
        if (nodes[ptr]->_next != -1)    printf("%05d %d %05d\n", ptr, nodes[ptr]->_key, nodes[ptr]->_next);
        else printf("%05d %d %d\n", ptr, nodes[ptr]->_key, nodes[ptr]->_next);
        ptr = nodes[ptr]->_next;
    }
    while (remove_ptr != -1) {
        if (nodes[remove_ptr]->_next != -1) printf("%05d %d %05d\n", remove_ptr, nodes[remove_ptr]->_key, nodes[remove_ptr]->_next);
        else printf("%05d %d %d\n", remove_ptr, nodes[remove_ptr]->_key, nodes[remove_ptr]->_next);
        remove_ptr = nodes[remove_ptr]->_next;
    }

    return 0;
}