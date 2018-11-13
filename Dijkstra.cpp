/*
* @Author: WZY
* @School: HPU
* @Date:   2018-11-13 15:23:05
* @Last Modified by:   WZY
* @Last Modified time: 2018-11-13 15:24:39
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 0x7f7f7f7f
const int maxn=1e3+10;
int edge[maxn][maxn];
int flag[maxn];	//flag[i]��ǽڵ�i�Ƿ񱻲�ѯ
int dis[maxn];	//dis[i]��ʾ�ڵ�i������ʼ�ڵ����̾���
int n,m;		//n���㣬m����
void Dijkstra()
{
	memset(flag,0,sizeof(flag));
	int ans,x;
	for(int i=1;i<=n;i++) 
		dis[i]=edge[1][i];
	dis[1]=0;
	flag[1]=1;
	for(int i=1;i<=n;i++)
	{
		ans=INF;
		for(int j=1;j<=n;j++)
		{
			if(ans>dis[j]&&!flag[j])
			{
				ans=dis[j];
				x=j;
			}
		}
		flag[x]=1;
		for(int j=1;j<=n;j++)
			if(!flag[j])
				dis[j]=min(dis[j],dis[x]+edge[x][j]);
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			edge[i][j]=INF;
	memset(dis,INF,sizeof(dis));
	int x,y,z;
	while(m--)
	{
		cin>>x>>y>>z;
		edge[x][y]=z;
		// edge[y][x]=z;
	}
	Dijkstra();
	for(int i=1;i<=n;i++)
		cout<<"�ڵ� "<<i<<" ��������̾���Ϊ��"<<(dis[i]==INF?-1:dis[i])<<endl;
	return 0;
}