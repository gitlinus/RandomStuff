//#include<bits/stdc++.h>
#include "stdc++.h"
using namespace std;
 
vector<vector<int> > g;
vector<int> h;
int n;
 
// finding height of each node.
// Argument p here is the parent of current node
int height(int curr, int p){
    for(auto it : g[curr]){
        if(it == p){
            continue;
        }
        h[curr] = max(h[curr], height(it, curr));
    }
    h[curr] +=  1;
    return h[curr];
}
 
// finding diameter
int diameter(int curr, int p){
    
    int mx1, mx2, mx_subtree;
    mx1 = mx2 = mx_subtree = INT_MIN;
    for(auto it : g[curr]){
        if(it == p){
            continue;
        }
        if(mx1 < h[it]){
            mx2 = mx1;
            mx1 = h[it];
        } else {
            mx2 = h[it];
        }
    }
    for(auto it : g[curr]){
        if(it == p){
            continue;
        }
        mx_subtree = max(mx_subtree, diameter(it, curr));
    }
 
// diameter will be max of diameter in the subtrees or if it passes
// through current node then it will be the sum of maximum heights
// of any two of its children + 1(1 for current node).
 
    return max(mx_subtree, mx1 + mx2 + 1);
}
 
int main(){
    cin >> n;
    g.resize(n+1);
    h.resize(n+1, 0);
    for(int i=0, u, v ; i<n-1 ; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
// choosing root to be 1.
    height(1, -1);
    cout << diameter(1, -1) ;
    return 0;
}
Algorithm - 2

Another way is to use to two DFS or BFS.


we choose an arbitrary node (x) and find the farthest node from (x), let it be (y) , then we do another traversal to find the farthest node from (y) , let it be (z).

Then diameter is the distance between (y) and (z).

Proof for this Algorithm - here (Exercise 9-1).

#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int> > g;
int n;
 
pair<int, int> bfs(int root){
    vector<int> dist(n+1, 0);
    dist[root] = 1;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int curr = q.front();
        for(auto it : g[curr]){
            if(dist[it] != 0){
                continue;
            }
            q.push(it);
            dist[it] = dist[curr] + 1;
        }
        q.pop();
    }
    int mx = INT_MIN, vertex = -1;
    for(int i=1 ; i<=n ; i++){
        if(mx < dist[i]){
            mx = dist[i];
            vertex = i;
        }
    }
    return make_pair(mx, vertex);
}
 
int diameter(int root){
    pair<int, int> p1 = bfs(root), p2;
    p2 = bfs(p1.second);
    return p2.first;
}
 
int main(){
    cin >> n;
    g.resize(n+1);
    for(int i=0, u, v ; i<n-1 ; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
// choosing arbitrary node to be 1.
    cout << diameter(1) ;
    return 0;
}