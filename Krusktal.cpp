/*
* @Author: WZY
* @School: HPU
* @Date:   2018-11-13 14:41:58
* @Last Modified by:   WZY
* @Last Modified time: 2018-11-13 15:17:32
*/
#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
const int maxn=1e6+10;
using namespace std;
int F[maxn];
struct Edge
{
	int u,v,w;
}edge[maxn];
int tol;	//边数
inline void add(int u,int v,int w)
{
	edge[tol].u=u;
	edge[tol].v=v;
	edge[tol++].w=w;
}
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(F[x]==-1)
		return x;
	else
		return F[x]=find(F[x]);
}
inline int Kruskal(int n)
{
	ms(F,-1);
	sort(edge,edge+tol,cmp);
	int cnt=0;	//计算加入的边数
	int ans=0;
	for(int i=0;i<tol;i++)
	{
		int u=edge[i].u;
		int v=edge[i].v;
		int w=edge[i].w;
		int t1=find(u);
		int t2=find(v);
		if(t1!=t2)
		{
			ans+=w;
			F[t1]=t2;
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	// 不连通
	if(cnt<n-1)
		return -1;
	else
		return ans;
}
int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d",&n)&&n)
	{
		tol=0;
		int m=n*(n-1)/2;
		int x,y,z;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
		}
		printf("%d\n",Kruskal(n));
	}
	return 0;
}