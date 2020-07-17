## my sol 1     20/6/15     10 min

fail

因为数字太大越界了，用long long也没有用。

看来需要用全加器了...

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned long long num1 = 0, num2 = 0;
        ListNode *ptr = l1;
        stack<int> stk;
        while (ptr != NULL) {
            stk.push(ptr->val);
            ptr = ptr->next;
        }
        while (!stk.empty()) {
            num1 = num1 * 10 + stk.top();
            stk.pop();
        }
        ptr = l2;
        while (ptr != NULL) {
            stk.push(ptr->val);
            ptr = ptr->next;
        }
        while (!stk.empty()) {
            num2 = num2 * 10 + stk.top();
            stk.pop();
        }
        unsigned long long result = num1 + num2;
        ListNode *ret = new ListNode(result % 10);
        ptr = ret;
        result /= 10;
        while (result != 0) {
            ListNode *temp = new ListNode(result % 10);
            result /= 10;
            ptr->next = temp;
            ptr = temp;
        }
        return ret;
    }
};
```

## my sol 2     20/6/15     30 min

32 ms   71.47%

9.3 mb  100%

看来太久没有用C++写算法题还是手生了啊...

用了全加器的算法，并且对小的数的高位补零。



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, num1, num2;
        ListNode *result = new ListNode(-1);
        ListNode *ptr1 = l1, *ptr2 = l2, *cur = result;
        while (ptr1 != NULL || ptr2 != NULL) {
            num1 = ptr1 == NULL ? 0 : ptr1->val;
            num2 = ptr2 == NULL ? 0 : ptr2->val;
            if (cur->val == -1) {
                // cur->val = (ptr1->val + ptr2->val + carry) % 10;
                // carry = (ptr1->val + ptr2->val + carry) / 10;
                // ptr1 = ptr1->next;
                // ptr2 = ptr2->next;
                cur->val = (num1 + num2 + carry) % 10;
                carry = (num1 + num2 + carry) / 10;
                ptr1 = ptr1 == NULL ? NULL : ptr1->next;
                ptr2 = ptr2 == NULL ? NULL : ptr2->next;
            } else {
                ListNode *temp = new ListNode((num1 + num2 + carry) % 10);
                cur->next = temp;
                cur = temp;
                carry = (num1 + num2 + carry) / 10;
                ptr1 = ptr1 == NULL ? NULL : ptr1->next;
                ptr2 = ptr2 == NULL ? NULL : ptr2->next;
            }
        }
        // if (ptr1 != NULL) {
        //     cur->next = ptr1;
        //     ptr1->val = (ptr1->val + carry) % 10;
        //     carry = (ptr1->val + carry) / 10;
        //     if (carry > 0 && ptr1->next != NULL) ptr1->next->val += carry;
        //     else if (carry > 0 && ptr1->next == NULL) {
        //         ListNode  *temp = new ListNode(carry);
        //         ptr1->next = temp;
        //     }
        // } else if (ptr2 != NULL) {
        //     cur->next = ptr2;
        //     ptr2->val = (ptr2->val + carry) % 10;
        //     carry = (ptr2->val + carry) / 10;
        //     if (carry > 0 && ptr2->next != NULL) ptr2->next->val += carry;
        //     else if (carry > 0 && ptr2->next == NULL) {
        //         ListNode  *temp = new ListNode(carry);
        //         ptr2->next = temp;
        //     }
        // } else if (ptr1 == NULL && ptr2 == NULL && carry > 0) {
        //     ListNode  *temp = new ListNode(carry);
        //     cur->next = temp;
        // }
        if (carry > 0) {
            ListNode  *temp = new ListNode(carry);
            cur->next = temp;
        }
        return result;
    }
};
```