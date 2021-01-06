#include "stdc++.h"
#define INF 1e9
#define SIZE 100000
using namespace std;
long long int dist[SIZE];
bool visited[SIZE];
vector< pair<int,int> > v[SIZE];

void dijkstra(int x)
{
    for(int i=0;i<SIZE;++i)
        dist[i] = INF;
    
    memset(visited,false,SIZE);
    
    priority_queue< pair<int,int> ,vector< pair<int,int> > , greater< pair<int,int> > > q;
    pair <int,int> p;

    q.push(make_pair(0,x));
    dist[x] = 0;
    
    while(!q.empty())
    {
        p = q.top();
        q.pop();
        x = p.second;

        if(visited[x]) continue;

        visited[x]=true;

        for(int i=0;i<v[x].size();++i)
        {
            int e = v[x][i].second;
            int w = v[x][i].first;

            if(dist[e]>dist[x]+w)
            {
                dist[e] = dist[x]+w;
                q.push(make_pair(dist[e],e));
            }
        }
    }
}

int main()
{

    int n,m,a,b,w;

    scanf("%d%d",&n,&m);

    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d",&a,&b,&w);
        v[a].push_back(make_pair(w,b));
        //v[b].push_back(make_pair(w,a));
    }
    
    dijkstra(1);

    for(int i=2;i<=n;++i)
        printf("%lld ",dist[i]);
    
    return 0;
}