#include <bits/stdc++.h>
const int maxn=1e6+10;
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Stack;
Stack *s;
void init()
{
    s=NULL;
}
bool Empty()
{
    if(s==NULL)
        return true;
    else
        return false;
}
void Push(int element)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data=element;
    p->next=s;
    s=p;             
}
void Pop()
{
    s=s->next;
}
int Top()
{
    return s->data;
}
void Destroy()
{
    free(s);
    s=NULL;
}
int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n)
	{
		init();
		if(n<0)
		{
			cout<<"-";
			n*=-1;
		}
		while(n)
		{
			Push(n&1);
			n>>=1;
		}
		while(!Empty())
		{
			cout<<Top();
			Pop();
		}
		cout<<endl;
	}
	return 0;
}