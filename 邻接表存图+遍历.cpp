/*
* @Author: WZY
* @School: HPU
* @Date:   2018-11-02 18:22:38
* @Last Modified by:   WZY
* @Last Modified time: 2018-11-02 19:35:07
*/
#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
#define ms(a,b) memset(a,b,sizeof(a))
const int maxn=1e3+10;
using namespace std;
int n,m;
int DFS[maxn];
typedef struct Node
{
	int data;
	Node* Next;
}Edge;
Edge* Node[maxn];
Edge *s;
int vis[maxn];
// 递归
// 查找v的第一个邻接点
int Find_first(int v)
{
	if(Node[v]!=NULL)
		return Node[v]->data;
	return 0;
} 
// 查找v的相对于u的下一个邻接点
int Find_next(int v,int u)
{
	Edge *p=Node[v]; 
	while(p!=NULL)
	{
		if(p->data==u)
			break;
		p=p->Next;
	}
	if(p==NULL)
		return 0;
	p=p->Next;
	if(p!=NULL)
		return p->data;
	return 0;
}
void dfs1(int v,int flag)
{
	if(v>n)
		return ;
	if(flag)
		cout<<"->";
	cout<<v;
	vis[v]=1;	
	flag++;
	int res=Find_first(v);
	while(res)
	{
		if(!vis[res])
			dfs1(res,flag);
		res=Find_next(v,res);
	}
}
// 非递归
void dfs2(int v,int flag)
{
	int temp,w;
	stack<int>s;
	cout<<v;
	vis[v]=1;
	vis[0]=1;
	s.push(v);
	while(!s.empty())
	{
		temp=s.top();  
		w=Find_first(temp);  
		if(!vis[w])
		{
			cout<<"->"<<w;  
			vis[w]=1;
			s.push(w);
		} 
		else
		{       
			w=Find_next(temp,w);  
			while(w)
			{
				if(!vis[w])
				{
					cout<<"->"<<w;
					vis[w]=1;
					s.push(w);
					break;
				} 
				else
					w=Find_next(temp,w);
			}
			if(w==0)  
				s.pop();			
		}	 	
	}
	cout<<endl;
}
void bfs(int v)
{
	queue<int>q;
	vis[v]=1;
	cout<<v;
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
			u=Find_next(res,u);
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
inline void add(int x,int y)
{
	s=(Edge*)malloc(sizeof(Edge));
	s->data=y;
	s->Next=Node[x];
	Node[x]=s;
}
inline void init()
{
	for(int i=1;i<maxn;i++)
		Node[i]=NULL;
}
int main(int argc, char const *argv[])
{
	init();
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
