# 1090_highestPriceSupplyChain

## my sol 1     20/2/10     30 min

14/25

> 1090_highestPriceSupplyChain.cpp

emmmmm

我觉得我的算法应该没错啊？遍历所有结点，从该结点一路往上爬到根节点并存入栈，然后再一路弹出计算这条路的长度——即深度，还有很多优化的代码...为什么只过了两个测试点？

emmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm....

原来10的5次方不是10000.......

经修改，只剩一个测试点过不去了....

24/25

## ref sol 1

> 1090_highestPriceSupplyChain2.cpp

原来可以这样！

```
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if(temp == -1)
            root = i;
        else
            v[temp].push_back(i);
    }
```
这样父级和子级就不是反过来了！！！妙啊！！！

## my sol 2

> 1090_highestPriceSupplyChain3.cpp

而且由于这是稀疏图，且结点数量极大，就不能用邻接矩阵表示，得用邻接链表。

然而还是一堆错误与段错误...

啊！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

原来10的5次方不是10000！！！！！！！！！！！！！！！！！！！！！

原来是这里错了！！！！！！！！！！！！！

过了!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!