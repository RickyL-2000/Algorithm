/**
 * @brief reference solution  
 */

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
