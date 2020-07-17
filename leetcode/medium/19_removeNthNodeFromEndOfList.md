# 19_removeNthNodeFromEndOfList

## my sol 1     20/6/24     20 min

0 ms    100%

6.6 mb  100%

之所以花了这么长时间是因为写了一遍错了，后来重新写了一遍...

``` C++
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) return head;
        ListNode *ptr = head;
        vector<ListNode*> stk;
        while (ptr != NULL) {
            stk.push_back(ptr);
            ptr = ptr->next;
        }
        if (n == stk.size()) return head->next;
        else {
            ptr = stk[stk.size() - n - 1];
            ptr->next = ptr->next->next;
            return head;
        }
    }
};

int main() {
    vector<int> list = {1};
    int n = 1;
    ListNode *head = new ListNode(list[0]);
    ListNode *ptr = head;
    for (int i = 1; i < list.size(); i++) {
        ListNode *newNode = new ListNode(list[i]);
        ptr->next = newNode;
        ptr = newNode;
    }
    Solution s;
    ListNode *ret = s.removeNthFromEnd(head, n);
    vector<int> rst;
    while (ret != NULL) {
        rst.push_back(ret->val);
        ret = ret->next;
    }
    return 0;
}
```
