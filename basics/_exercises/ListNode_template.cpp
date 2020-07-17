typedef int Rank;   //秩
#define ListNodePosi(T) ListNode<T>*    //列表节点位置

template <typename T> struct ListNode { //列表节点模板类（以双向链表形式实现）
// 成员
    T data; ListNodePosi(T) pred; ListNodePosi(T) succ;
// 构造函数
    ListNode() {}   // 针对header和trailer的构造
    ListNode( T 2, ListNodePosi(T) p = nullptr, ListNodePosi(T) s = nullptr)
        : data(e), pred(p), succ(s) {} // 默认构造器
// 操作接口
    ListNode(T) insertAsPred(T const& e);
    ListNode(T) insertAsSucc(T const& e);
};