# 1087_allRoadsLeadToRome

## my sol 1     20/2/6      60 min

3/30

用了非常非常麻烦的dijkstra方法，最后只得了3分...

很多错误，不知道是为什么...且看别人是怎么做的...

## ref sol 1

dfs?????

> 1087_allRoadsLeadToRome2.cpp

看起来很妙的样子...

也是用了dijkstra算法！

是先用dijkstra计算出所有可能的路线，用一个pre二维数组表示，然后再对这个二维数组进行dfs

所以虽然不知道具体是为什么，我的算法失败的原因应该就是我的算法是即时的，即dijkstra遍历一遍就以为能找到最佳方案，结果原来是因为sample太简单了...可能测试数据要更加复杂，导致这种半贪心的算法有了漏洞...

## my sol 2

是对ref sol 1的重复，巩固。

> 1087_allRoadsLeadToRome3.cpp