#include <bits/stdc++.h>
#define random(x) (rand()%x)
const int maxn=1e5;
using namespace std;
int main()
{
	freopen("in2.txt","w",stdout);
	cout<<maxn<<endl;
	for(int i=1;i<=maxn;i++)
		cout<<random(1000)<<" ";
	cout<<endl;
}