#include "stdc++.h"
using namespace std;
//Range minimum / maximum query

#define INF 2e9 + 5
#define SIZE 1000000 + 5 // next power of 2 * 2 - 1
int Arr[SIZE];
int Tree[SIZE];

void build(int node, int start, int end)
{
    if(start==end)
        Tree[node] = Arr[start];
    else{
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        if(Tree[2*node]<Tree[2*node+1])
            Tree[node]=Tree[2*node];
        else
            Tree[node]=Tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start==end){
        Arr[idx] = val;
        Tree[node] = val;
    }
    else{
        int mid = (start + end)/2;
        if(idx >= start && idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        if(Tree[2*node]<Tree[2*node+1])
            Tree[node]=Tree[2*node];
        else
            Tree[node]=Tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(l > end || start > r)
        return INF;
    if(l <= start && r >= end)
        return Tree[node];
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    if(p1<p2)
        return p1;
    else
        return p2;
}

int N, Q;
int main()
{
    scanf("%d%d",&N,&Q);
    for(int i=1; i<=N; i++)
        scanf("%d",&Arr[i]);
    build(1,1,N);
    int l, r;
    char c;
    for(int i=0; i<Q; i++){
        cin >> c >> l >> r;
        if(c=='q')
            cout << query(1, 1, N, l, r) << endl;
        else
            update(1, 1, N, l, r);
    }
    return 0;
}