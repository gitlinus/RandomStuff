#include "stdc++.h"
using namespace std;

#define SIZE 1000 + 5
int BIT[SIZE];
int a[SIZE];
int n;

//update: add val at index x
void update(int x, int val)
{
    for(;x<=n;x+=x&-x)
        BIT[x] += val;
}

//update2: change a[x] to val
void update2(int idx, int old, int val) {
    int add = val - old;
    a[idx] = val;
    for (int i = idx; i <= n; i += i & -i) {
        BIT[i] += add;
    }
}

int query(int x)
{
    int sum = 0;
    for(; x>0; x -= x&-x)
        sum += BIT[x];
    return sum;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    cout << query(5);
    return 0;
}