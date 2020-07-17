# 1002 Business

## ref sol 1    20/1/19

我吐了，原来top是顶级的意思，advanced才是甲级

动态规划做就完了。本题的关键因素在于每个任务的deadline。因此，之前需要对所有任务按deadline排序。动态规划的vdp[i][j]应当表示第j天在考虑到第i个任务时所能得到的最大收益。状态转移方程如下：vdp[i][j]=max(vdp[i-1][j],vdp[i-1][t]+v[i-1].p)，在这里，t表示第i个任务完成之前，完成i-1个任务至多所需要的天数。

> business.cpp

```
#include<bits/stdc++.h>
using namespace std;
struct task
{
	int p,l,d;
	bool operator< (const task et) const
	{return d<et.d;}
};
int main()
{
//	freopen("data.txt","r",stdin);
	int n,m=0;
	scanf("%d",&n);
	vector<task> v(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&v[i].p,&v[i].l,&v[i].d);
		m=max(v[i].d,m);
	}
	sort(v.begin(),v.end());
	vector<int> vdp((n+1)*(m+1),0);
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			int t=min(j,v[i-1].d)-v[i-1].l;
			if(t>=0) vdp[i*(m+1)+j]=max(vdp[(i-1)*(m+1)+j],vdp[(i-1)*(m+1)+t]+v[i-1].p);
			else vdp[i*(m+1)+j]=vdp[(i-1)*(m+1)+j];
		}
	}
	printf("%d",vdp[n*m+n+m]);
	return 0;
}
```