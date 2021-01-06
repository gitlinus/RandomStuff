#include "stdc++.h"
using namespace std;

#define SIZE 1000 + 1

int Arr[SIZE];
int size[SIZE];

void initialize()
{
    for(int i=0; i<SIZE; i++)
    {
        Arr[i] = i;
        size[i] = 1;
    }
}

int root(int i) //path compression
{
    while(Arr[i]!=i)
    {
        Arr[i] = Arr[Arr[i]];
        i = Arr[i];
    }
    return i;
}

void _union(int A, int B)
{
    int root_A = root(A);       
    int root_B = root(B);  
    Arr[root_A] = root_B; 
}

void weightedunion(int A, int B) //union by rank :poggers:
{
    int root_A = root(A);
    int root_B = root(B);

    if(root_A == root_B)
        return;

    if(size[root_A] > size[root_B])
    {
        Arr[root_B] = root_A;
        size[root_A] += size[root_B];
        size[root_B] = 0;
    }

    else
    {
        Arr[root_A] = root_B;
        size[root_B] += size[root_A];
        size[root_A] = 0;
    }
}

bool find(int A, int B)
{
    if(root(A)==root(B))
        return true;
    else
        return false;
}

int main()
{
    initialize();

    int N, M, x, y;
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        cin >> x >> y;
        weightedunion(x, y);
        vector<int> v;
        for(int j=1; j<=N; j++)
            v.push_back(size[j]);
        sort(v.begin(), v.end());
        for(int j=1; j<=N; j++)
        {
            if(v[j]!=0)
                printf("%d ", v[j]);
        }
        cout << endl;
    }
    return 0;
}