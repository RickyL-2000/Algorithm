#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>

using namespace std;
typedef long long ll;
const int MOD = 10000007;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 1010;
struct Node{
	int id;	//结点编号 
	int layer;	//结点层号 
}; 

vector<Node> Adj[maxn];	//邻接表 
bool inq[maxn] = {false};	//顶点是否已被加入过队列 

int BFS(int s, int L)	//s为起始结点，L为层数上限 
{
	int numForward = 0;	//转发数 
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);	//将起点编号压入队列 
	inq[start.id] = true;
	while(!q.empty())
	{
		Node topNode = q.front();	//取出队首结点 
		q.pop();
		int u = topNode.id;	//队首结点的编号 
		for(int i=0; i<Adj[u].size(); i++)
		{
			Node next = Adj[u][i];	//next为从u出发能到达的结点 
			next.layer = topNode.layer + 1;	//next的层号等于当前结点层号加 1 
			//如果next的编号为被加入过队列，且next的层次不超过上限L 
			if(inq[next.id]==false&&next.layer<=L)
			{
				q.push(next);	//将next入队 
				inq[next.id] = true;
				numForward++;	//转发数加 1 
			}
		}
	}
	return numForward;
}
 

int main()
{
	int n, L;	//结点个数、层数上限
	scanf("%d%d",&n,&L);	//结点个数、层数上限
	Node user;
	int numFollow, idFollow;	//该用户关注的人数，该用户关注的用户编号 
	for(int i=1; i<=n; i++)
	{
		user.id = i;	//用户编号为i
		scanf("%d",&numFollow);		//i号用户关注的人数 
		for(int j=0;j<numFollow;j++)
		{
			scanf("%d",&idFollow);	//i号用户关注的用户编号 
			Adj[idFollow].push_back(user);	//边idFollow->i 
		} 
	} 
	
	int numQuery, s;
	scanf("%d",&numQuery);	//查询个数 
	for(int i=0;i<numQuery;i++)
	{
		memset(inq, false, sizeof(inq));	//inq数组初始化 
		scanf("%d",&s);
		int numForward = BFS(s, L);
		printf("%d\n",numForward);
	}
	return 0;
}

