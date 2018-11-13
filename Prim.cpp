/*
* @Author: WZY
* @School: HPU
* @Date:   2018-11-13 15:16:16
* @Last Modified by:   WZY
* @Last Modified time: 2018-11-13 15:18:58
*/
#include<bits/stdc++.h>
using namespace std;
int f[110];
struct node{
    int first,second;
    int Length;
};
bool cmp(node u,node v)
{
    return u.Length<v.Length;
}
int find(int x)
{
    if(x!=f[x]) 
    	f[x]=find(f[x]);
    return f[x];
}
bool join(int x,int y)
{
    int dx=find(x);
    int dy=find(y);
    if(dx!=dy)
    {
        f[dx]=dy;
        //dy=f[dx];
        return true;
    }
    return false;
}
int main()
{
    int n,m;
    node W;
    vector<node>d;
    while(~scanf("%d",&n)&&n)
    {
        d.clear();
        m=n*(n-1)/2;
        for(int i=1;i<=n;i++) 
        	f[i]=i;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&W.first,&W.second,&W.Length);
            d.push_back(W);
        }
        sort(d.begin(),d.end(),cmp);
        int sum=0;
        int way=0;
        for(int i=0;i<d.size();i++)
        {
            if(join(d[i].first,d[i].second)==true)
            {
                sum+=d[i].Length;
                way++;
            }
            if(way==n-1) 
            	break;
        }
        printf("%d\n",sum);
    }
    return 0;
}