#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
const int maxn=1e3+10;
using namespace std;
int n,m;
int edge[maxn][maxn];
//初始化
inline void init(int n)
{ 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) 
				edge[i][j]=0;
			else 
				edge[i][j]=edge[j][i]=INF;
		}
	}
}
// 建图
inline void add(int m)
{
	int u,v,val;
	while(m--)
	{
		cin>>u>>v>>val;
		// 双向图写这行
		edge[u][v]=edge[v][u]=min(edge[u][v],val); 
		// 单向图写这行
		//edge[u][v] = min(edge[u][v], val); 
		
	}
}
inline void floyd(int n)
{ 
	for(int k=1;k<=n;k++)
	{ 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	init(n);
	add(m);
	floyd(n);
	cout<<(edge[n][1]==INF?-1:edge[n][1])<<endl;
	return 0;
}
