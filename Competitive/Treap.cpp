#include <stdio.h>
#include <iostream>
#include "stdc++.h"

using namespace std;

struct node{
    int key, prior;
    node *l, *r;
    node(int k) : key(k), prior(rand()), l(NULL), r(NULL) {}
} *root;

void split(node *t, int key, node * &l, node * &r){
    if(!t) l = r = NULL;
    else if(key < t -> key) split(t->l,key,l,t->l), r = t;
    else split (t->r, key, t->r, r), l = t;
}

void insert(node *&t, node *it){
    if(!t) t = it;
    else if(it->prior > t-> prior) split(t, it->key, it->l, it->r), t = it;
    else insert(it->key < t->key ? t->l : t->r, it);
}

void merge(node * &t, node *l, node *r){
    if(!l||!r) t = l ? l : r;
    else if(l-> prior > r->prior) merge(l->r,l->r,r), t=l;
    else merge(r->l,l,r->l), t=r;
}

void erase(node * &t, int key){
    if(t->key==key) merge(t,t->l,t->r);
    else erase(key<t->key? t->l : t->r, key);
}

node * unite(node *l, node *r){
    if(!l||!r) return l ? l : r;
    if(l->prior < r->prior) swap(l,r);
    node *lt, *rt;
    split(r,l->key, lt, rt);
    l->l = unite(l->l,lt);
    l->r = unite(l->r,rt);
    return l;
}

void bfs(node *n){
    queue<node*> q;
    q.push(n);
    while(!q.empty()){
        node *cur = q.front();
        q.pop();
        cout << cur->key << endl;
        cout << "Parent: " << cur-> key << endl;
        if(cur->l)q.push(cur->l),cout << "Left Child: " << cur->l->key << endl;
        if(cur->r)q.push(cur->r),cout << "Right Child: " << cur->r->key << endl;;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    int N, n;
    cin >> N; //>> r;
    //root = new node(r);
    for(int i=0; i<N; i++){
        cin >> n;
        merge(root, root, new node(n));
        //insert(root,new node(n));
    }
    cout << "DONE\n\n\n";
    bfs(root);
    //cout << root -> key << endl;
    //cout << root -> l -> key << endl;
    //cout << root -> r -> key << endl;
}