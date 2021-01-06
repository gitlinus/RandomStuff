//detect cycle in a graph
#include<iostream>
#include <vector>
using namespace std;
#define SIZE 1000

vector<int> adj[SIZE];
bool vis[SIZE];
bool recStack[SIZE];
bool cycle = false;
 
// Returns true if the graph contains a cycle, else false.
void dfsIsCyclic(int s)
{
    vis[s] = true;
    recStack[s] = true;
    
    for(int i=0; i<adj[s].size(); i++)
    {
        if(!vis[adj[s][i]])
        {
            dfsIsCyclic(adj[s][i]);
        }
        else if(vis[adj[s][i]]&&recStack[adj[s][i]]){
            //cout << "CYCLE!";
            cycle = true;
        }
    }
    recStack[s] = false;
}
 
int main()
{
    // Create a graph given in the above diagram
    int n; cin >> n; //num
    int m; cin >> m; //Roads
    int a, b;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // Mark all the vertices as not visited and not part of recursion
    for(int i = 0; i < SIZE; i++)
    {
        vis[i] = false;
        recStack[i] = false;
    }

    cycle = false;
    dfsIsCyclic(1); //im assuming 1 is root

    if(cycle)
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}