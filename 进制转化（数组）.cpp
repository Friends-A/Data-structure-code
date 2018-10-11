/*
* @Author: WZY
* @School: HPU
* @Date:   2018-10-11 21:01:42
* @Last Modified by:   WZY
* @Last Modified time: 2018-10-11 21:03:07
*/
#include <bits/stdc++.h>
using namespace std;
int a[50];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	if(n<0)
	{
		cout<<"-";
		n*=-1;
	}
	int _=0;
	while(n)
	{
		a[_++]=n&1;
		n>>=1;
	}
	for(int i=_-1;~i;i--)
		cout<<a[i];
	cout<<endl;
	return 0;
}