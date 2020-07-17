# remove Duplicate Node

## my sol 1     20/6/26     8 min

84 ms       38.8%

17.2 mb     100%

``` C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *first = head, *second = head->next;
        set<int> check;
        check.insert(first->val);
        while (second != NULL) {
            if (check.find(second->val) != check.end()) {
                first->next = second->next;
                second = second->next;
            } else {
                check.insert(second->val);
                first = second;
                second = second->next;
            }
        }
        return head;
    }
};
```
