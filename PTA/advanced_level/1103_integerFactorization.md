# 1103_integerFactorization

## my sol 1     20/2/13     20 min

23/30

> 1103_integerFactorization.cpp

有两个测试点错了

我采用的是非常简单的算法，即我认为当k个factors都比较接近的时候，sum会最大，而为了使得更large，我采用从0开始遍历，一个个+1的方法。

这两个测试点过不去可能就是因为我的算法太简单了

来看看她的dfs

哦.....我大概知道为什么自己会错了...因为我的算法最多保证factors里面各个数字只相差1，但是是有可能要相差2或者更多的....

这么大的漏洞居然只有2个测试点没有过去...

## ref sol 1

> 1103_integerFactorization2.cpp

说实话没有看懂...反正就dfs呗...


## my sol 2

反正就dfs呗...

反正就是重写一遍呗，以后巩固的时候再写