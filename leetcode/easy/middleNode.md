# middle of the linked list

返回单向链表的中间结点

## my solution 1    20/1/15 10 min

time    4   65.93%
mem     8.7 5.11%

```
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
    ListNode* middleNode(ListNode* head) {
        ListNode* ans = head, *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            ans = ans->next;
            if (ptr->next != NULL) {
                ptr = ptr->next;
            } else {
                return ans;
            }
        }
        return ans;
    }
};
```

为什么这么慢...

## reference solution 1

```
ListNode* middleNode(struct ListNode* head) { 
    ListNode* fast = head; 
    ListNode* low = head;
    while(fast != NULL && (fast->next != NULL)) {
    low = low->next;
    fast = fast->next->next;
    }
    return low;
}
```

这样只是看起来简洁，空间复杂度并没有好多少...