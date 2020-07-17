# Reversible Primes

## my sol 1     20/1/24     30 min

20/20

> reversiblePrimes.cpp

```
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i <= (int)sqrt((double)n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int reverse(int num, int radix) {
    vector<int> digits;
    while (num != 0) {
        digits.push_back(num % radix);  // the rightest digit
        num /= radix;
    }
    for (int i = 0; i < digits.size(); i++) {
        num += digits[i] * pow((float)radix, (float)(digits.size() - i - 1));
    }
    return num;
}

int main() {
    vector<string> ans;
    int num, radix;
    while (scanf("%d", &num) && num > 0) {
        scanf("%d", &radix);
        if (!isPrime(num)) {
            ans.push_back("No");
            continue;
        }
        num = reverse(num, radix);
        if (!isPrime(num)) {
            ans.push_back("No");
            continue;
        }
        ans.push_back("Yes");
    }

    for (size_t i = 0; i < ans.size(); i++) {
        printf("%s\n", ans[i].c_str());
    }

    return 0;
}
```

怎么说呢...尝试了两次，第三次终于过了。第一次是因为自己觉得可以优化速度导致出现了bug这种愚蠢的行为，第二次...

第二次是没有考虑到1不是prime

但是我也稍微尝试去查了一下别人的算法...感觉有些地方非常值得学...

## ref sol 1

> reversiblePrimes2.cpp

```
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
int prime[maxn];
bool vis[maxn] = {false};
int cnt = 0;
void findPrime(){   //埃氏筛法
    //每找到一个一个素数将其倍数都标记为不是素数
    //时间复杂度O(n loglogn)
    for(int i = 2; i < maxn; i++){
        if(vis[i] == false){    //i是素数
            prime[cnt++] = i;
            for(int j = 2 * i; j < maxn; j += i){
                vis[j] = true;  //标记所以i的倍数
            }
        }
    }
}
LL toDecimal(string num, int radix){    //将某进制数转化为10进制
    LL ans = 0;
    for(int i = 0; i < num.size(); i++){
        ans = ans * radix + (num[i] - '0');
        if(ans < 0)
            return -1;
    }
    return ans;
}
string decimalToOther(int num, int radix){  //将十进制数转化为其他进制数
    string ans;
    //ans从最低位开始记录，结束后得到的直接就是转化后数字的反转
    while(num){
        ans += (num % radix) + '0';
        num /= radix;
    }
    return ans;
}
int n, d;
int main()
{
    findPrime();    //素数打表
    while(scanf("%d", &n) != EOF && n > 0){
        //输入n，n < 0时直接结束运算
        scanf("%d", &d);
        //输入进制d
        if(vis[n] == true || n <= 1){   //若n不是素数直接输出No进行下一次运算
            printf("No\n");
            continue;
        }
        string toRadix = decimalToOther(n, d);
        //将n转化为d进制并反转
        int ans = toDecimal(toRadix, d);
        //将反转的数重新转化为10进制
        if(vis[ans] == true || ans <= 1){//若反转的数不是素数输出No
            printf("No\n");
            continue;
        }
        printf("Yes\n");    //否则输出Yes
    }
    return 0;
}
```

