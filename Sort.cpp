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
// 希尔排序
void ShellInsert(Sqlist &L,int dk)
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
void ShellSort(Sqlist &L,int dt[],int t)
{
	int k,dk;
	for(k=0;k<t;++k)
		ShellInsert(L,dt[k]);	 
}
// 折半插入
void Binsertsort(Sqlist &L)
{
	int low,high,m;
	for(int i=2;i<=L.len;i++)
	{
		L.r[0]=L.r[i];
		low=1;
		high=i-1;
		while(low<=high)
		{
			m=(low+high)/2;
			if(L.r[0].key<L.r[m].key)
				high=m-1;
			else
				low=m+1;
		}
		for(int j=i-1;j>=high+1;j--)
			L.r[j+1]=L.r[j];
		L.r[high+1]=L.r[0];
	}
}
void insertsort(Sqlist &L)
{
	int j;
	for(int i=2;i<=L.len;i++)
		if(L.r[i].key<L.r[i-1].key)
		{
			L.r[0]=L.r[i];
			L.r[i]=L.r[i-1];
			for(j=i-2;L.r[0].key<L.r[j].key;j--)
				L.r[j+1]=L.r[j];
			L.r[j+1]=L.r[0];
		}
}
int main()
{
	freopen("in1.txt","r",stdin);
	freopen("Sort.txt","w",stdout);
	Sqlist L1,L2,L3;
	L1.r=new RedType[maxn];
	L2.r=new RedType[maxn];
	L3.r=new RedType[maxn];
	int n;
	scanf("%d",&n);
	L1.len=n;
	L2.len=n;
	L3.len=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		L1.r[i].key=a[i];
		L2.r[i].key=a[i];
		L3.r[i].key=a[i];
		// scanf("%d",&L.r[i].key);
	}
	double _begin_time1 = clock();
	insertsort(L1);
	long _end_time1 = clock();
	printf("------------InsertSort time = %lf ms.------------------------\n", _end_time1 - _begin_time1);

	double _begin_time2 = clock();
	Binsertsort(L2);
	long _end_time2 = clock();
	printf("------------BInsertSort time = %lf ms.------------------------\n", _end_time2 - _begin_time2);

	double _begin_time3 = clock();
	ShellSort(L3,a,n);
	long _end_time3 = clock();
	printf("------------ShellSort time = %lf ms.------------------------\n", _end_time3 - _begin_time3);
	for(int i=1;i<=n;i++)
		printf("%d ",L1.r[i].key);
	printf("\n");
	return 0;
}