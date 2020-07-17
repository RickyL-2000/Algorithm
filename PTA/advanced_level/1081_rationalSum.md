# 1081_rationalSum

## my sol 1     20/1/30     

最后一个测试点过不去...

之前也有2个测试点过不去，排查原因得出又是我用scanf()读入long int的时候用%d了...而那个时候最后一个测试点不是错的问题，而是超时的问题。

那么...

update 20/1/30

啊我知道了！！！应该是结果等于0的时候我什么也没有输出!!!

好吧，最后一个测试点是结果等于0...

过了！ 

20/20

## ref sol 1

计算 gcd 的最佳方法！

long long gcd(long long a, long long b) {return b == 0 ? abs(a) : gcd(b, a % b);}