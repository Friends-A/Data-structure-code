/*
* @Author: WZY
* @School: HPU
* @Date:   2018-11-02 18:35:27
* @Last Modified by:   WZY
* @Last Modified time: 2018-11-02 19:48:06
*/
#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
#define ms(a,b) memset(a,b,sizeof(a))
const int maxn=1e3+10;
using namespace std;
int edge[maxn][maxn];
int vis[maxn];
int DFS[maxn];
int n,m;
inline void add(int x,int y) 
{
	edge[x][y]=1;
}
// 递归DFS
void dfs1(int v,int flag)
{
	if(v>n)
		return ;
	if(flag)
		cout<<"->";
	cout<<v;
	vis[v]=1;	
	flag++;
	for(int i=1;i<=n;i++)
		if((!vis[i])&&edge[v][i])
			dfs1(i,flag);
}
// 非递归DFS
void dfs2(int v,int flag)
{
	ms(vis,0);
	ms(DFS,0);
	int top=1;
	DFS[top]=v;
	while(top)
	{
		int res=DFS[top];
		if(!vis[res])
		{
			vis[res]=1;
			if(flag)
				cout<<"->";
			flag++;
			cout<<res;
			for(int i=n;i>=1;i--)
				if((!vis[i])&&edge[res][i])
					DFS[++top]=i;
		}
		else
			top--;
	}
	cout<<endl;
}
// 查找v的第一个邻接点
int Find_first(int v)
{
	for(int i=1;i<=n;i++)
		if(edge[v][i])
			return i;
	return 0;
}
// 查找v的相对于u的下一个邻接点
int Fint_next(int v,int u)
{
	int i;
	int _=0;
	for(i=1;i<=n;i++)
	{
		if(edge[v][i]&&i==u)
			_=1;
		else if(_==1&&edge[v][i])
			break;
	}
	if(i>n)
		return 0;
	return i;
}
// 非递归
void bfs(int v)
{
	queue<int>q;
	cout<<v;
	vis[v]=1;
	q.push(v);
	while(!q.empty())
	{
		int res=q.front();
		q.pop();
		int u=Find_first(res);
		while(u)
		{
			if(!vis[u])
			{
				cout<<"->"<<u;
				vis[u]=1;
				q.push(u);
			}
			u=Fint_next(res,u);
		}
	}
	cout<<endl;
}
inline void print()
{
	cout<<"建图完成，请输入遍历开始的起点：";
	int v;
	cin>>v;
	cout<<"请选择需要的遍历方式（输入0停止）："<<endl;
	cout<<"1.DFS递归遍历\n2.DFS非递归遍历\n3.BFS非递归遍历"<<endl;
	int __;
	while(cin>>__&&__)
	{
		ms(vis,0);
		if(__==1)
		{
			dfs1(v,0);
			cout<<endl;
		}
		if(__==2)
			dfs2(v,0);
		if(__==3)
			bfs(v);	
	}
}
int main(int argc, char const *argv[])
{
	cout<<"请选择：\n1.有向图\n2.无向图"<<endl;
	int _;
	cin>>_;
	if(_==1)
	{
		cout<<"请输入点的个数及边的个数（用空格隔开）：";
		cin>>n>>m;
		int x,y;//两条边+权值
		// 有向图
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			add(x,y);
		}
		print();	
	}
	else
	{
		cout<<"请输入点的个数及边的个数（用空格隔开）：";
		cin>>n>>m;
		int x,y;//两条边+权值
		// 无向图
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		print();	
	}
	return 0;
}
