#include "stdc++.h"
using namespace std;
typedef long long ll;
#define SIZE 20000+5
#define INF 1e9

ll dist[SIZE];
vector< pair<ll, ll> > adj[SIZE];
priority_queue< pair<ll,ll> > pq;
ll N, M, A, B, L;

void dijkstra(ll start)
{
    for(int i=1; i<=N; i++)
        dist[i] = INF;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        pair<ll, ll> edge = pq.top();
        pq.pop();
        //cout << "NODE: " << edge.second << endl;
        //cout << "DISTANCE: " << edge.first << endl;
        if(dist[edge.second]==INF){
            dist[edge.second] = -edge.first;
            //cout << "UPDATED: DISTANCE TO NODE " << edge.second << " IS " << dist[edge.second] << endl;
            for(pair<ll, ll> edge2 : adj[edge.second])
                pq.push(make_pair(edge.first-edge2.first, edge2.second));
        }//else
            //cout << "ALREADY VISITED, NOT UPDATED" << endl;
    }
}

int main()
{
    scanf("%lld%lld",&N,&M);
    for(int i=0; i<M; i++){
        scanf("%lld%lld%lld",&A,&B,&L);
        adj[A].push_back(make_pair(L,B));
    }
    dijkstra(1);

    for(int i=1; i<=N; i++)
        cout << dist[i] << endl;
    return 0;
}