// Maximum sum over an interval
#include "stdc++.h"
using namespace std;

int arr[1000];
int mem[1000];
bool comp[1000];
int max_sum(int i) {
    if (i == 0) {
        return arr[i];
    }
    if (comp[i]) {
        return mem[i];
    }
    int res = max(arr[i], arr[i] + max_sum(i - 1));
    mem[i] = res;
    comp[i] = true;
    return res;
}

int main(){
    memset(comp, 0, sizeof(comp));
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    int maximum = 0, Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        maximum = max(maximum, max_sum(i));
    }
    printf("%d\n", maximum);
}