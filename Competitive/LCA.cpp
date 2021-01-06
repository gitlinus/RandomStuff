#include "stdc++.h"
using namespace std;
const int NUM = 1e5+5;
int parent[NUM], level[NUM], P[NUM];
vector<int> tree[NUM];
bool vis[NUM];
void dfs(int u){
	vis[u] = true;
	for(int i=0; i<tree[u].size(); i++)
		if(!vis[tree[u][i]]){
			level[tree[u][i]] = level[u] + 1;
			parent[tree[u][i]] = u;
			dfs(tree[u][i]);
		}
}

void traverse(int node, int head, int prev_section){
	int current_section = sqrt(level[node]) + 1;
	if(current_section==1) P[node] = 1;
	else{
		if(current_section == prev_section + 1){
			P[node] = parent[node];
			head = node;
		}
		else P[node] = parent[head];
	}
	for(int i=0; i<tree[node].size(); ++i)
		if(tree[node][i] != parent[node]) traverse(tree[node][i], head, current_section);
}

int LCA(int u, int v){
	while(P[u] != P[v]){
		if(level[u] > level[v]) u = P[u];
		else v = P[v];
	}
	while(u!=v){
		if(level[u] > level[v]) u = parent[u];
		else v = parent[v];
	}
	return u;
}

int main(){
	int N, M, Q, x, y;
	cin >> N >> M >> Q;

	for(int i=0; i<M; i++){
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	dfs(1);
	traverse(1,1,0);
	
	for(int i=0; i<Q; i++){
		cin >> x >> y;
		cout << LCA(x,y) << endl;
	}

	//for(int i=1; i<=N; i++) cout << level[i] << " ";

	//for(int i=0; i<N; i++) cout << traversal[i] << " ";
	//cout << endl;
}