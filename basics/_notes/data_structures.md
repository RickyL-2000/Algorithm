# 数据结构

以伪代码的形式描述数据结构和算法。有C++程序语言实现。

通过使用指针来建立简单的数据结构，来表示动态集合。

## 数组

## 链表

### 接口

#### 列表节点

* ADT 接口

|   操 作 接 口   |                     功 能                     |
| :-------------: | :-------------------------------------------: |
|     data()      |             当前节点所存数据对象              |
|     pred()      |            当前节点前驱节点的位置             |
|     succ()      |            当前节点后继节点的位置             |
| insertAsPred(e) | 插入前驱节点，存入被引用对象e，返回新节点位置 |
| insertAsSucc(e) | 插入后继节点，存入被引用对象e，返回新节点位置 |

* ListNode 模板类

> example: ListNode_template.cpp

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

#### 列表

* ADT 接口

|              操 作 接 口              |                           功 能                            |
| :-----------------------------------: | :--------------------------------------------------------: |
|                size()                 |               报告列表当前的规模（节点总数）               |
|           first()、 last()            |                    返回首、末节点的位置                    |
|   insertAsFirst(e)、insertAsLast(e)   |                   将e当作首、末节点插入                    |
| insertBefore(p, e)、insertAfter(p, e) |             将e当作节点p的直接前驱、 后继插入              |
|               remove(p)               |               删除位置p处的节点，返回其数值                |
|             disordered()              |               刞断所有节点是否已按非降序排列               |
|                sort()                 |             调整各节点癿位置，使之按非降序排列             |
|                find(e)                |               查找目标元素e，失败时反回NULL                |
|               search(e)               | 查找目标元素e，迒回不大于e且秩最大的节点(只适用于有序列表) |
|             deduplicate()             |                        剔除重复节点                        |
|              uniquify()               |               剔除重复节点(只适用于有序列表)               |
|              traverse()               |       遍历幵统一处理所有节点，处理方法由函数对象指定       |



## 向量

各元素的秩(rank)互异，且均为[0, n)内的整数。在此序列中，各递归实例的秩反映了它们各自被创建的时间先后，每一递归实例的秩等于早于它出现的实例总数。 反过来，通过r亦可唯一确定e = vr。 这是向量特有的元素访问方式，称作“循秩访问” （call-by-rank）

在用C++中的vector操作时，如果遇到需要反向的问题(比如需要将一个vector反向或者类似的)，可以利用rbegin()和rend()！！！这两个迭代器不仅和begin()和end()相反，其增长顺序**貌似**也是相反的，比如要将一个vector反向，只需要：```vector<T> v2(v1.rbegin(), v1.rend())```!!!

## 栈和队列

### 栈 (stack)

栈实现的是一种后进先出 (LIFO) 的策略。

栈上的 INSERT 操作被称为压入 （PUSH)，而无元素参数的 DELETE 操作称为弹出 （POP)。

如果试图对一个空栈执行弹出操作，则称栈下溢 (underflow)，反之则是上溢。

可以用一个数组 S[0..n] 来实现一个最多可容纳 n 个元素的栈。该数组有一个属性 S.top (像索引)，指向最新插入的元素。

既然栈可以视作序列的特例，故只需要将栈作为

### 队列 (queue)

队列实现的是一种先进先出 (FIFO) 的策略。

队列上的 INSERT 操作称为入队 (ENQUEUE)，DELETE 操作称为出队 (DEQUEUE)。


## 链表

链表的顺序是由各个对象里的指针决定的。链表为动态集合提供了一种简单而灵活的表示方法。

**双向链表(doubly linked list)** L 的每个元素都是一个对象，每个对象都有一个关键字 key 和两个指针：next 和 prev。对象中还可以包含其他的辅助数据(或称卫星数据)。

链表的搜索

    LIST-SEARCH(L, k)
        x = L.head
        while x != NIL and x.key != k;
            x = x.next;
        return x;

链表的插入

    LIST-INSERT(L, x)
        x.next = L.head;
        if L.head != NIL
            L.head.prev = x;
        L.head = x;
        x.prev = NIL
        // 为什么要这么麻烦？

链表的删除

    LIST-DELETE(L, x)
        if x.prev != NIL
            x.prev.next = x.next;
        else L.head = x.next;
        if x.next != NIL
            x.next.prev = x.prev

### 有根树的表示


## 图

## 树

### 自由树

自由树是一个连通的、无环的无向图。通常情况，当我们提到一个图是树时，会省略形容词“自由”。称一个可能不连通的无向无环图为**森林**。许多树的算法对森林也适用。

#### 关于自由树的定理

**自由树性质**：令 G = (V, E) 是一个无向图，下面的描述是等价的。
1. G 是自由树
2. G 中任何两顶点由唯一简单路径相连
3. G 是联通的，但是从图中移除任意一条边得到的图均不连通
4. G 是连通的，且 |E| = |V| - 1
5. G 是无环的，且 |E| = |V| - 1
6. G 是无环的，但是如果向 E 中添加任何一条边，均会造成图包含一个环


### 有根树

有根树是一棵自由树，其顶点中存在一个与其他顶点不同的顶点，我们称该不同顶点为树的根。一棵有根树的顶点常常称为树的结点。

考虑以 r 为根的有根树 T 中的一个结点 x。从 r 到 x 的唯一简单路径上任意结点 y 称为 x 的一个**祖先**。如果 y 是 x 的祖先，则 x 是 y 的**后代**。**每一个结点既是自己的祖先也是自己的后代**。如果 y 是 x 的祖先且 x != y，则 y 是 x 的一个**真祖先**，且 x 是 y 的一个**真后代**。

如果从树 T 的根 r 到一个结点 x 的简单路径上最后一条边是 (y, x)，则 y 是 x 的**双亲**，而 x 是 y 的**孩子**。根是树中唯一没有双亲的结点。如果两个结点有相同的双亲，则它们是**兄弟**。一个没有孩子的结点为**叶节点**（或称**外部结点**）。一个非叶节点是**内部结点**。

有根树 T 中一个结点 x 的孩子数目等于结点 x 的**度**。从根 r 到结点 x 的一条简单路径的长度即为 x 在 T 中的**深度**。树的一个**层**包含了同一深度的所有结点。结点在树中的**高度**是指从该结点到叶节点最长的一条简单路径上边的数目。**树的高度也等于树中点的最大深度。**


### 有序树

有序树是一颗有根树，其中每个结点的孩子是有序的。也就是说，如果一个结点有 k 个孩子，则这些孩子之间会区分哪个是第一孩子，哪个是第二孩子，……，哪个是第 k 孩子。

**如果树是有序树，树种某结点的孩子之间的左右位置关系有影响，否则没影响。**


### 二叉树

递归地定义：二叉树是定义在有限结点集上的结构，它或者不包含任何结点，或者包含三个不相交的结点集合：一个**根结点**，一棵称为**左子树**的二叉树，以及一棵称为**右子树**的二叉树。

不包含任何结点的二叉树称为**空树**或**零树**，有时用符号 **NIL** 表示。如果左/右子树非空，则它的根称为整棵树的根的**左/右孩子**。

二叉树不仅仅是一棵结点度均为 2 的有序树。**在一棵二叉树中，如果一个结点仅有一个孩子，则它是左孩子还是右孩子是有关系的。**而在有序树种，是没有必要区分一个单独的孩子是左还是右的。

二叉树的位置信息可以用有序树种的内部结点来表示。这一想法需要将二叉树种的每个缺失的孩子用一个没有孩子的结点替代。这些叶节点在图中表示为正方形。这样得到的树是**满二叉树**：每个结点是叶节点或者度为2。


### 位置树

区分二叉树与有序树的存储位置信息可以扩展到结点有多余2个孩子的树上，在一棵**位置树**中，结点的孩子被标记为不同的正整数。**k叉树是一棵位置树，其中对于每个结点，所有标记大于 k 的孩子均缺失。因此，二叉树是 k = 2 的 k 叉树。**

**完全k叉树是所有叶节点深度相同，且所有内部结点度为 k 的 k 叉树**。一棵高度为 h 的完全 k 叉树的内部结点数目为: 
$$ 1 + k + k^2 + k^{h-1} = \frac{k^h - 1}{k - 1} $$

因此，完全二叉树有 $2^h-1$ 个内部结点。


## 堆 (heap)

(二叉)堆是一个数组，它可以被看成一个近似的完全二叉树。树上的每一个结点对应数组中的一个元素。**除了最底层外，该树是完全充满的，而且是从左向右填充。**

表示堆的数组 A 包括两个属性：A.length (通常)给出数组元素的个数，A.heap_size 表示有多少个堆元素存储在该数组中。也就是说，虽然 A[0...A.length] 可能存有数据，但只有 A[0..A.heap-size]中存放的是堆的有效元素。

树的根结点是 A[1]，这样给定一个结点的下标 i，我们很容易计算得到它的父节点、左孩子和右孩子的下标：

    PARENT(i)
        return [i/2]

    LEFT(i)
        return 2i

    RIGHT(i)
        return 2i+1

下标的计算关系到堆在数组中的填充方法，是上到下、从左到右依次填充的。

**NOTE**：在大多数计算机上，通过将 i 的值左移或者右移就能达到 2i 或者 i/2 的效果了。在堆排序的好的实现中，这三个函数通常是以“宏”或者“内联函数”的方式实现的。

二叉堆可以分为两种形式：最大堆和最小堆。
1. 最大堆，满足某个结点的值至多与其父节点一样大。所以，堆中的最大元素存放在根结点中。
2. 最小堆，与最大堆完全相反。


既然一个包含 n 个元素的堆可以看作一棵完全二叉树，那么该堆的高度是 lgn。我们会发现，堆结构上的一些基本操作的运行时间至多与堆的高度成正比，即时间复杂度为 O(lgn)。

**NOTE**：在堆排序算法中使用最大堆。最小堆通常用于构造优先队列。


关于堆的一些基本过程：
1. MAX-HEAPIFY 过程。时间复杂度 O(lgn)，是维护最大堆性质的关键
2. BUILD-MAX-HEAP 过程。具有线性时间复杂度，从无序的输入数组中构造一个最大堆
3. HEAPSORT 过程。时间复杂度 O(nlgn)，对一个数组进行原址排序
4. MAX-HEAP-INSERT, HEAP-EXTRACT-MAX, HEAP-INCREASE-KEY, HEAP-MAXIMUM 过程。时间复杂度 O(lgn)，利用堆实现一个优先队列



### 维护堆的性质 MAX-HEAPIFY

> example: MAX-HEAPIFY.cpp

本过程的输入为一个数组 A 和一个下标 i。在调用 MAX-HEAPIFY 的时候，我们假定根结点为 LEFT(i) 和 RIGHT(i) 的二叉树都是最大堆，但这时 A[i] 有可能小于其孩子，这样就违背了最大堆的性质。MAX-HEAPIFY 通过让 A[i] 的值在最大堆中“逐级下降”，从而使得以下标 i 为根结点的子数重新遵循最大堆的性质。


    MAX-HEAPIFY (A, i)
        l = LEFT(i)
        r = RIGHT(i)
        if l <= A.heap-size && A[l] > A[i]
            largest = l
        else largest = i
        if r <= A.heap-size && A[r] > A[largest]
            largest = r
        if largest != i
            exchange A[i] with A[largest]
            MAX-HEAPIFY (A, largest)


**疑问**：这个递归貌似只会从一条路走到头吧？有点像阉割过的深搜。如果 left 和 right 都有违反最大堆性质的结点存在怎么办？



### 建堆 BUILD-MAX-HEAP

> example: BUILD-MAX-HEAP.cpp

可以用自底向上的方法利用过程 MAX-HEAPIFY 把一个大小为 n = A.length 的数组 A[0..n] 转换为最大堆。

**NOTE**：子数组 A[n/2 .. n] 中的元素都是树的叶节点，它们没有孩子所以不用再往下比较。每个叶节点都可以看成是只包含一个元素的堆。过程 BUILD-MAX-HEAP 对树中的其他点都调用一次 MAX-HEAPIFY

    BUILD-MAX-HEAP (A)
        A.heap-size = A.length;
        for i = A.length/2 downto 1
            MAX-HEAPIFY(A, i)


**NOTE**：这个过程的时间复杂度为 O(n)



### 堆排序算法

初始，堆排序算法利用 BUILD-MAX-HEAP 将输入数组 A[0..n]建成最大堆，其中 n = A.length。因为数组中的最大元素总在根节点 A[0] 中，通过把它与 A[n-1】 进行互换，我们可以让该元素放到正确的位置。这时候，我们再从堆中去掉结点 n-1，剩余的节点中，原来根的孩子结点仍然是最大堆，但是新的根结点可能会违背最大堆的性质。那就只需要调用 MAX-HEAPIFY(A, 1)，从而在 A[0..n-1] 上构造一个新的最大堆。之后不断重复这一过程。

    HEAPSORT(A)
        BUILD_MAX_HEAP(A);
        for i = A.length downto 2
            exchange A[1] with A[i];
            A.heap-size = A.heap-size - 1; // 去掉结点 n-1
            MAX-HEAPIFY(A, 0)



### 优先队列    (priority queue)    {????}

堆排序是一个优秀的算法，但是在实际应用中，快速排序的性能一般会优于堆排序。尽管如此，堆这一数据结构仍然会有很多应用。堆的一个常见应用就是高效的优先队列。

和堆一样，优先队列也有两种形式：最大优先队列和最小优先队列。这里我们关注如何基于最大堆实现最大优先队列。

优先队列是一种用来维护由一组元素构成的集合S的数据结构，其中的每一个元素都有一个相关的值，称为**关键字(key)**，一个最大优先队列支持以下操作：
1. INSERT(S, x)     把元素 x 插入集合 S 中，这一操作等价于 S = S 并 {x}
2. MAXIMUM(S)       返回 S 中具有最大关键字的元素
3. EXTRACT-MAX(S)   去掉并返回 S 中的具有最大关键字的元素
4. INCREASE-KEY(S, x, k)    将元素 x 的关键字值增加到 k，这里假设 k 的值不小于 x 的原关键字值


显然，优先队列可以用堆来实现。在用堆来实现优先队列时，需要在堆中的每个元素里存储对应对象的**句柄 (handle)**。句柄（如一个指针或一个整型数等）的准确含义依赖于具体的应用程序。通常，这一句柄是数组的下标。由于在堆的操作过程中，元素会改变其在数组中的位置，因此，在具体的实现中，在重新确定堆元素位置时，我们也需要更新相应应用程序对象中的数组下标。


现在讨论如何用堆实现最大优先队列的操作。


1. 过程 HEAP-MAXIMUM 可以在常量时间内实现 MAXIMUM 操作

        HEAP-MAXIMUM(A)
            return A[0];

2. 过程 HEAP-EXTRACT-MAX 实现了 EXTRACT-MAX 操作。它与 HEAPSORT 过程中的 for 循环体部分很相似。时间复杂度为 O(lgn)

        HEAP-EXTRACT-MAX(A)
            if A.heap-size < 1
                error "heap underflow";
            max = A[0];
            A[0] = A[A.heap.size - 1];
            A.heapsize = A.heapsize - 1;
            MAX-HEAPIFY(A, 0);
            return max;

3. HEAP-INCREASE-KEY 能够实现 INCREASE-KEY 操作。在优先队列中，增加关键字的优先队列元素由对应的数组下标 i 来标识。这一操作需要首先将元素 A[i] 的关键字更新为新值。因为增大 A[i] 的关键字可能会违反最大堆的性质。所以上述操作采用了类似于插入排序中的方式，在从当前节点到根节点的路径上，为新增的关键字寻找恰当的插入位置。

        HEAP-INCREASE-KEY(A, i, key)
            if key < A[i]
                error "new key is smaller than current key";
            A[i] = key;
            while i > 0 && A[PARENT(i)] < A[i]
                exchange A[i] with A[PARENT(i)];
                i = PARENT(i);