// 带头结点，是dummynode的意思吗？

#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge( List L1, List L2 ) {
    List ptr1 = L1->Next, ptr2 = L2->Next;
    L1->Next = NULL, L2->Next = NULL;
    List L = (List) malloc (sizeof(struct Node)) , ptr = L;
    L->Next = NULL;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->Data < ptr2->Data) {
            ptr->Next = ptr1;
            ptr1 = ptr1->Next;
            ptr = ptr->Next;
        } else {
            ptr->Next = ptr2;
            ptr2 = ptr2->Next;
            ptr = ptr->Next;
        }
    }
    while (ptr1 != NULL) {
        ptr->Next = ptr1;
        ptr = ptr->Next;
        ptr1 = ptr1->Next;
    }
    while (ptr2 != NULL) {
        ptr->Next = ptr2;
        ptr = ptr->Next;
        ptr2 = ptr2->Next;
    }
    ptr->Next = NULL;
    return L;
}