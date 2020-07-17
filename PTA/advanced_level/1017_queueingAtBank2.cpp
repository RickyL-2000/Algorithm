#include <bits/stdc++.h>
#define maxn 10010
#define cl(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
ll N, K, res[maxn], ans, tot;
pair<ll,ll> cus[maxn];      // <arrT, costT>
ll read(ll x=0)             // 这人的码风可真是奇特啊...
{
	ll c, f=1;
	for(c=getchar(); !isdigit(c); c=getchar())  if(c=='-')f=-f;
	for(; isdigit(c); c=getchar())    x=x*10+c-48;
	return f*x;
}
void init()
{
	ll i;
	N=read(), K=read();
	for(i=1;i<=N;i++)
	{
		cus[i].first=read()*3600+read()*60+read(), cus[i].second=read()*60;     // 同从零累计
		if(cus[i].first<=61200)cus[++tot]=cus[i];
	}
	N=tot;
	sort(cus+1,cus+N+1);
}
void work()
{
	ll i, j, k, p=1;
	for(i=28800;i<=36028800 and p<=N;i++)   // 一秒一秒地遍历...我傻了...
	{
		for(j=1;j<=K;j++)
		{
			if(res[j]==0)   // 既表示窗口数，又表示该窗口的剩余时间！这个确实有意思！
			{
				if(cus[p].first<=i and p<=N)
				{
					res[j]=cus[p].second-1;
					ans+=i-cus[p].first;        // 在等待的同时就计算总等待数，减少循环次数
					p++;
				}
			}
			else res[j]--;
		}
	}
	if(p==1)printf("0.0");
	printf("%.1lf",ans/60.0/N);
}
int main()
{
	init();
	work();
	return 0;
}
