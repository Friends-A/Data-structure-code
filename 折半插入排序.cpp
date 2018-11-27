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
int main()
{
	freopen("in1.txt","r",stdin);
	freopen("1Binstrt.txt","w",stdout);
	Sqlist L;
	L.r=new RedType[maxn];
	int n;
	scanf("%d",&n);
	L.len=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&L.r[i].key);
	double _begin_time = clock();
	Binsertsort(L);
	long _end_time = clock();
	printf("------------time = %lf ms.------------------------\n", _end_time - _begin_time);
	for(int i=1;i<=n;i++)
		printf("%d ",L.r[i].key);
	printf("\n");
	return 0;
}