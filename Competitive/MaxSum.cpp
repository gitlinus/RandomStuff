// Maximum sum over an interval
#include "stdc++.h"
using namespace std;
int *arr, *mem;
bool *comp;

void init(int MAX){
    arr = new int[MAX];
    mem = new int[MAX];
    comp = new bool[MAX];
    for(int i=0; i<MAX; i++){
        scanf("%d",&arr[i]);
        comp[i] = 0;
    }
}

int max_sum(int i) {
    if (i == 0) {
        mem[i] = arr[i];
        return arr[i];
    }
    if (comp[i]) {
        return mem[i];
    }
    int res = max(arr[i], arr[i] + max_sum(i - 1));
    cout << arr[i] << " " << arr[i] + max_sum(i - 1) << " : " << res << endl;
    mem[i] = res;
    comp[i] = true;
    return res;
}

void update(int x, int y){
    arr[x] = y;
}

int main()
{
    int N;
    cin >> N;
    init(N);
    max_sum(N);
    int maxsum = mem[0];
    for(int i=0; i<N; i++){
        maxsum = max(maxsum, mem[i]);
        cout << "MAX from " << 0 << " to " << i << ": " << maxsum << endl;
    }
    return 0;
}