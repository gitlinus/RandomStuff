#include "stdc++.h"
using namespace std;
//0-1 Knapsack problem
int main(){
	int N, W;
	cin >> N >> W;
	int v[N], w[N], ks[N+1][W+1];
	for(int i=0; i<N; i++)
		cin >> v[i] >> w[i];
	
	for(int i=0; i<=N; i++){
		for(int j=0; j<=W; j++){
			if(i==0||j==0) ks[i][j] = 0;
			else if(w[i-1]<=j) ks[i][j] = max(ks[i-1][j],v[i-1]+ks[i-1][j-w[i-1]]);
			else ks[i][j] = ks[i-1][j];
		}
	}
	/*
	for(int i=0; i<N+1; i++){
		for(int j=0; j<W+1; j++){
			cout << ks[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << ks[N][W] << endl;
}