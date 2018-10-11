int a[20];
// 递归写法
int fib1(int n)
{
	if(n==1||n==2)
		return 1;
	return fib1(n-1)+fib1(n-2);
}
// 非递归
int fib2(int n)
{
	a[1]=a[2]=1;
	for(int i=3;i<=n;i++)
		a[i]=a[i-1]+a[i-2];
	return a[n];
}