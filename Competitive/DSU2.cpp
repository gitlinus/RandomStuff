#include "stdc++.h"
using namespace std;
int a[1001],b[1001];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        b[i]=1;
    }
}

int root(int x)
{
    int m=x;
    while(a[m]!=m)
    {
        a[m]=a[a[m]];
        m=a[m];
    }
    return m;
}

void u(int x,int y)
{
    int m=root(x);
    int v=root(y);
    if(m==v)
        return;
    if(b[m]>b[v])
    {
        a[v]=m;
        b[m]=b[m]+b[v];
        b[v]=0;
    }
    else
    {
        a[m]=v;
        b[v]=b[m]+b[v];
        b[m]=0;
    }
}

int main()
{
    int n,m,i,j,x,y;
    cin >> n >> m;
    j=m;
    init(n);
    while(j--)
    {
        cin >> x >> y;
        u(x,y);
        vector<int> c;
        for(i=1;i<=n;i++)
            c.push_back(b[i]);
        sort(c.begin(),c.end());
        for(i=1;i<=n;i++)
        {
            if(c[i]!=0)
                printf("%d ",c[i]);
        }
        cout << "\n";
    }
    return 0;
}