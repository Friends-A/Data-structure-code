int a[20];
// 递归
int fact1(int n)
{
	return n?fact1(n-1)*n:1;
}
// 非递归
int fact2(int n)
{
	a[0]=a[1]=1;
	for(int i=2;i<=n;i++)
		a[i]=i*a[i-1];
	return a[n];
}
