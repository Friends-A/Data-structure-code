#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b;
	char c;
	cin>>a>>c>>b;
	if(c=='+')
		cout<<a+b<<endl;
	if(c=='-')
		cout<<a-b<<endl;
	if(c=='*')
		cout<<a*b<<endl;
	if(c=='/')
		cout<<(double)a/b<<endl;
	if(c=='%')
		cout<<a%b<<endl;
	return 0;
}