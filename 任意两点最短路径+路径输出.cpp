#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x7f7f7f7f
const int maxn=1e3+10;
using namespace std;
int edge[maxn][maxn];
int dis[maxn];
int vis[maxn];
int n,m;
int way[maxn];
int tol;
int pri[maxn];
inline void dijkstra(int start)
{
	ms(vis,0);
	ms(dis,INF);
	vis[start]=1;dis[start]=0;
	int ans=INF,res;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(edge[start][j]!=INF&&!vis[j])
			{
				if(dis[j]>dis[start]+edge[start][j])
				{
					way[j]=start;
					dis[j]=dis[start]+edge[start][j];
				}
				if(ans>dis[j]&&!vis[j])
				{
					ans=dis[j];
					res=j;
				}
			}
		}
		vis[res]=1;
		start=res;
		ans=INF;
	}
}
int main(int argc, char const *argv[])
{
	while(cout<<"请输入点的个数和边的个数：",cin>>n>>m&&n&&m)
	{
		cout<<"请输入相连的两点即两点间的权值（用空格隔开）："<<endl;
		ms(pri,0);
		tol=0;
		ms(edge,INF);
		int u,v,w;
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>w;
			edge[u][v]=edge[v][u]=w;
		}
		cout<<"输出邻接矩阵为："<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					printf("0\t");
				else if(edge[i][j]==INF)
					printf("INF\t");
				else
					printf("%d\t",edge[i][j]);
			}
			printf("\n");
		}
		cout<<"请输入起点和终点：";
		int start,end;
		cin>>start>>end;
		dijkstra(start);
		cout<<dis[end]<<endl;
		cout<<"最短路的路径为：";
		int r=end;
		int s=start;
		int _=0;
		pri[_++]=end;
		while(r!=s)
		{
			pri[_++]=way[r];
			r=way[r];	
		}
		for(int i=_-1;i>=0;i--)
		{
			if(i!=_-1)
				cout<<"->";
			cout<<pri[i];
		}
		cout<<endl;
	}
	return 0;
}

