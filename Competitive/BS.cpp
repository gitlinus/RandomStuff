#include "stdc++.h"
using namespace std;

int arr[1000];

int bs(int low, int high, int target){
	if(low > high)
		return -1;
	int k = (low+high)/2;
	if(arr[k]==target)
		return k;
	if(arr[k] > target) high = k-1;
	else low = k+1;
	return bs(low, high, target);
}

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> arr[i];
	sort(arr, arr+N);
	cout << bs(0, N, 10);

}