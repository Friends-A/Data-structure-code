#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef struct 
{
	int key;
}RedType;
typedef struct 
{
	RedType *r;
	int len;
}Sqlist;
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
	freopen("1insert.txt","w",stdout);
	Sqlist L;
	L.r=new RedType[maxn];
	int n;
	scanf("%d",&n);
	L.len=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&L.r[i].key);
	double _begin_time = clock();
	insertsort(L);
	long _end_time = clock();
	printf("------------time = %lf ms.------------------------\n", _end_time - _begin_time);
	for(int i=1;i<=n;i++)
		printf("%d ",L.r[i].key);
	printf("\n");
	return 0;
}