// Range sum query
#include "stdc++.h" 
using namespace std;
const int SIZE = 1e6;
const int NUM_BLOCKS = 1e3; // (int) ceil(sqrt(SIZE));

int Arr[SIZE];
int Blocks[NUM_BLOCKS];
int blk_sz;
int blk_idx;

void update(int idx, int val){
	blk_idx = idx / blk_sz;
	Blocks[blk_idx] += val - Arr[idx];
	Arr[idx] = val;
}

int query(int l, int r){
	int sum = 0;
	while(l<r && l%blk_sz!=0 && l!=0){
		sum += Arr[l];
		l++;
	}
	while(l+blk_sz <= r){
		sum += Blocks[l/blk_sz];
		l += blk_sz;
	}
	while(l<=r){
		sum += Arr[l];
		l++;
	}
	return sum;
}

void preprocess(int N){
	blk_idx = -1;
	blk_sz = (int) sqrt(N);
	for(int i=0; i<N; i++){
		cin >> Arr[i];
		if(i%blk_sz==0)
			blk_idx++;
		Blocks[blk_idx] += Arr[i];
	}
}

int N, Q, n, l , r;
int main()
{
	cin >> N >> Q;
	preprocess(N);
	for(int i=0; i<Q; i++){
		cin >> n >> l >> r;
		if(n==1)
			cout << query(l, r) << endl;
		else
			update(l, r);
	}

	return 0;
}