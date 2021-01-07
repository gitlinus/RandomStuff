#include "stdc++.h"
using namespace std;
typedef long long ll;
const int MAX = 20000001;
ll N, M;
bitset <20000001> isPrime;
bitset <20000001> check;
vector <ll> primes;

void build_sieve()
{
    //build sieve up to root M
    isPrime[0] = 1;
    isPrime[1] = 1;
    ll SIZE = (int)sqrt(M) + 1;
    
    for(int i=2; i<SIZE; i++)
        if(isPrime[i]==0){
            primes.push_back(i);
            for(int j=i*2; j<SIZE; j+=i)
                isPrime[j] = 1;
        }
    
    ll num;
    for(int i=0; i<primes.size(); i++){
        if(N<=primes[i]) num = pow(primes[i], 2);
        else num = N/primes[i] * primes[i];
        if(num < N)
            num += primes[i];
        for(int j=num-N; j<M-N; j+= primes[i])
            check[j] = 1;
    }
    
    //code for Torture Chamber
    ll counter = 0;
    for(int i=0; i<M-N; i++)
        if(check[i]==0)
            counter++;
    if(N==1)
        counter-=1;
    cout << counter;
}

int main()
{
    scanf("%lld%lld",&N,&M);
    build_sieve();
}