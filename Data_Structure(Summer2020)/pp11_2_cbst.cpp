#include"stdio.h"
#include"string.h"
#include"algorithm"
using namespace std;
const int MAXN = 12;
int a[MAXN];
int b[MAXN];
int cnt;
int n;
void dfs(int x)
{
    if(x>n)
        return ;
    dfs(2*x);
    b[x]=++cnt;//对应应该第x号输出对应的第a数组的第cnt元素。
    dfs(2*x+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    dfs(1);
    for(int i=1; i<=n; i++)
        if(i==1)
            printf("%d",a[b[i]]);
        else
            printf(" %d",a[b[i]]);
}