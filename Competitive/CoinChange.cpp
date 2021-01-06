#include "stdc++.h"
using namespace std;
const int INF = 1e9;
const int MAX = 1e6;
int VAL; //value to sum up to
int NUM_COINS; //number of coins
vector<int> coins; //coins
int combo[MAX]; //combinations
int mem[10][10000]; //mem[NUM_COINS][VAL];

void numberOfWays(){
	combo[0] = 1;
	int cur;
	for(int i=0; i<coins.size(); i++){
		cur = coins[i];
		for(int j=1; j<=VAL; j++) if(j>=cur) combo[j] += combo[j-cur];
	}
}

int minWays(int i, int x){ //i is denominations from index 0 to i, x is value
	if(x<0) return INF;
	if(x==0) return 0;
	if(i==-1) return INF;

	//if(mem[i][x] != -1) return mem[i][x];
	
	int res = INF;
	res = min(res, 1 + minWays(i, x-coins[i]));
	res = min(res, minWays(i-1, x));
	
	//mem[i][x] = res;
	return res;
}

int main(){
	scanf("%d%d",&VAL,&NUM_COINS);
	int c;
	for(int i=0; i<NUM_COINS; i++){
		scanf("%d",&c);
		coins.push_back(c);
	}
	
	numberOfWays();
	for(int i=0; i<=VAL; i++)
		cout << combo[i] << " ";
	cout << endl;
	memset(mem, -1, sizeof(mem));
	cout << "Mininum coins needed: " << minWays(NUM_COINS-1, VAL) << endl;
	
	return 0;
}
