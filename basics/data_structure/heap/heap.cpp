#include <iostream>
#include <vector>
using namespace std;

#define InHeap(size_of_heap, index)    (((-1 < index) && (index < size_of_heap))) //判断是否在堆中
#define Parent(index)                   (i-1 >> 1)  // H[index]的父节点 (除以2)
#define LastInternal(size_of_heap)      Parent(size_of_heap-1) //最后一个内部结点
#define LChild(index)                   (1 + (index << 1))
#define RChild(index)                   ((1+index) << 1)
#define ParentValid(index)              (0 < index) //判断是否有父亲
#define LChildValid(size_of_heap, index)    InHeap(size_of_heap, LChild(index))
#define RChildValid(size_of_heap, index)    InHeap(size_of_heap, RChile(index))
