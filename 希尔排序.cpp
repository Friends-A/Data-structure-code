#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
typedef struct 
{
	int key;
}RedType;
typedef struct 
{
	RedType *r;
	int len;
}Sqlist;
int dt[100];
int n,k;
inline void get_dt(int n)
{
	k=0;
	while(n)
	{
		dt[k++]=n/2;
		n/=2;
	}
}
inline void ShellInsert(Sqlist &L,int dk)
{
	int i,j;
	for(i=dk+1;i<=L.len;++i)
		if(L.r[i].key<L.r[i-dk].key) 
		{
			L.r[0]=L.r[i];
			for(j=i-dk;j>0&&L.r[0].key<L.r[j].key;j-=dk)
				L.r[j+dk]=L.r[j];
			L.r[j+dk]=L.r[0];
		}
}
inline ShellSort(Sqlist &L,int dt[],int t)
{
	int k,dk;
	for(k=0;k<t;++k)
		ShellInsert(L,dt[k]);	 
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("1Shell.txt","w",stdout);
	Sqlist L;
	L.r=new RedType[maxn];
	scanf("%d",&n);
	get_dt(n);
	L.len=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&L.r[i].key);
		a[i]=L.r[i].key;
	}
	double _begin_time = clock();
	ShellSort(L,dt,k);
	long _end_time = clock();
	printf("------------time = %lf ms.------------------------\n", _end_time - _begin_time);
	for(int i=1;i<=n;i++)
		printf("%d ",L.r[i].key);
	printf("\n");
	return 0;
}
