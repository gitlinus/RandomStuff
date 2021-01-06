//
// Created by Linus Chen on 2019-09-26.
//
#include "stdc++.h"
using namespace std;

#define SIZE 200005
int arr[SIZE];
int tree[3*SIZE];
int lazy[3*SIZE];

void init(int n, int s, int e){
    if(s==e)
        tree[n] = arr[s];
    else{
        int mid = (s+e)/2;
        init(2*n, s, mid);
        init(2*n+1, mid+1, e);
        tree[n] = tree[2*n] + tree[2*n+1];
    }
}

void update(int node, int start, int end, int l, int r, int val){
    if(lazy[node]!=0){
        tree[node] += (end-start+1) * lazy[node];
        if(start != end){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end || start > r || end < l) return;
    if(start >= l && end <= r){
        tree[node] += (end - start + 1) * val;
        if(start != end){
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    int mid  = (start + end)/2;
    update(2*node, start, mid, l, r, val);
    update(2*node+1, mid+1, end, l, r, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int start, int end, int l, int r){
    if(start > end || start > r || end < l) return 0;
    if(lazy[node]!=0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l && end <= r) return tree[node];
    int mid = (start + end)/2;
    int p1 = query(node*2, start, mid, l, r);
    int p2 = query(node*2+1, mid+1, end, l, r);
    return (p1+p2);
}

int main(){
    int N, Q;
    scanf("%d %d",&N,&Q);
    for(int i=1; i<=N; i++)
        scanf("%d",&arr[i]);
    init(1,1,N);

    int q, l, r, val;
    for(int i=0; i<Q; i++){
        scanf("%d",&q);
        if(q==1){
            scanf("%d%d%d",&l,&r,&val);
            update(1,1,N,l,r,val);
        }
        if(q==2){
            scanf("%d%d",&l,&r);
            printf("%d\n",query(1,1,N,l,r));
        }
    }
}
