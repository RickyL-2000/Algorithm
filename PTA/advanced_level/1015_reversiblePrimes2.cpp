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