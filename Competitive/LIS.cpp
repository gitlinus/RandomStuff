#include "stdc++.h"
using namespace std;
int a[1000];
int mem[1000];
int N;

int lis(int i) {
	if (mem[i] != -1) return mem[i];
	int res = 1;
	for (int j = 0; j < i; j++) if (a[j] < a[i]) res = max(res, 1 + lis(j));
	mem[i] = res;
	return res;
}

void init(){
	scanf("%d",&N);
	for(int i=0; i<N; i++) cin >> a[i];
	memset(mem, -1, sizeof(mem));
}

int main(){
	init();
	int mx = 0;
	for (int i = 0; i < N; i++) mx = max(mx, lis(i));
	printf("%d\n", mx);
}


