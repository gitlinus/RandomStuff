#include "stdc++.h"
using namespace std;

const int MAX = 101;
int prime[MAX];

void init()
{
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i < int(pow(MAX, 0.5))+ 1; i++)
        if (prime[i]==0)
            for (int j = pow(i,2); j < MAX; j = j+i)
                prime[j] = 1;
}

int N, a, b;
int main()
{
    init();
    /*
    // code for Third Cellar
    int counter = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        for(int j=a+1; j<b; j++)
            if(prime[j]==0)
                counter++;
        cout << counter << endl;
        counter = 0;
    }   
    */

    for(int i=1; i<MAX; i++){
        if(prime[i]==0)
            cout << i << " prime" << endl;
        else
            cout << i << " composite" << endl;
    }
        
    return 0;
}