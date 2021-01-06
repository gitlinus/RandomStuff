#include "stdc++.h"
using namespace std;

#define SIZE 1000 + 5
int bit[SIZE];
int arr[SIZE];
int n;
void u(int x, int val){for(;x<=n;x+=x&-x)bit[x]+=val;}
int q(int x){int s=0; for(;x;x-=x&-x)s+=bit[x];return s;}
int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		u(i, arr[i]);
	}
	//cout << q(5);

	for(int i=1; i<=n; i++)
		cout << i << " ";
	cout << endl;
	for(int i=1; i<=n+10; i++)
		cout << bit[i] << " ";

	return 0;
}
