#include "stdc++.h"
using namespace std;

#define SIZE 5000

int N, M;
const int unvis = -1;
vector<int> adj[SIZE];
int ids[SIZE], low[SIZE];
bool inStack[SIZE];
stack <int> st;
int id=0, scc_cnt=0; 

void dfs(int at){
    st.push(at);
    inStack[at] = true;
    ids[at] = low[at] = id++;
    for(int to : adj[at]){
        if(ids[to]==unvis) dfs(to);
        if(inStack[to]) low[at] = min(low[at], low[to]);
    }
    if(ids[at]==low[at]){
        int node;
        do{
            node = st.top();
            st.pop();
            inStack[node] = false;
            low[node] = scc_cnt;
        }while(node!=at);
        scc_cnt++;
    }
}

void tarjan(){
    for(int i=0; i<N; i++) ids[i] = unvis;
    for(int i=0; i<N; i++)
        if(ids[i]==unvis) dfs(i);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    tarjan();
    cout << scc_cnt << " strongly connected components" << endl;

    for(int i=1; i<=scc_cnt; i++){
        cout << "SCC " << i << ": ";
        for(int j=0; j<N; j++){
            if(low[j]==i-1)
                cout << j << " ";
        }
        cout << endl;
    }
}