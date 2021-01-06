#include "stdc++.h"
using namespace std;

vector <int> adj[1000];
bool vis[1000];
int subtree[1000];

void dfs(int s, int e){
  subtree[s] = 1;
  for(auto u : adj[s]){
    if(u==e) continue;
    dfs(u, s);
    subtree[s] += subtree[u];
  }
}

void dfs(int s){
  vis[s] = true;
  subtree[s] = 1;
  for(auto u : adj[s]){
    if(!vis[u]) dfs(u);
    else continue;
    subtree[s] += subtree[u];
  }
}

int main(){
  int n, m, x, y;
  cin >> n;
  cin >> m;
  for(auto i=0; i<m; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0);
  for(auto i=0; i<n; i++)
    cout << subtree[i] << " ";
}
