#include "stdc++.h"
using namespace std;
typedef long long ll;
ll matrix[500][500];
int N;
ll mod = 1000000007;
ll modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
      return 0;
    if(a<0)a+=m;
    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
        // Update y and x
        y = x - q * y;
        x = t;
    }
    // Make x positive
    if (x < 0)
       x += m0;
    return x;
}

ll gaussian_elimination()
{
    ll idk, idek, divlater=1, temp;
    	for(int i=0; i<N-1; i++){
        idk = matrix[i][i];
        /*
	if(idk==0){
            for(int m=i+1; m<N; m++){
                if(matrix[m][i]!=0){
                    for(int l=0; l<N; l++){
                        temp = matrix[i][l];
                        matrix[i][l] = matrix[m][l];
                        matrix[m][l] = temp;
                    }
                    idk = matrix[i][i];
                    divlater *= -1;
                    break;
                }
            }
        }*/
        for(int j=i+1; j<N; j++){
            divlater *= matrix[i][i];
            divlater %= mod;
            idek = matrix[j][i];
            for(int k=0; k<N; k++){
                matrix[j][k] *= idk;
                matrix[j][k] -= idek * matrix[i][k];
                matrix[j][k] %= mod;     
            }
        }
    }
    ll det=1;
    for(int i=0; i<N; i++){
        //cout<<matrix[i][i]<<"\n";
        det *= matrix[i][i];
        det %= mod;
    }
    
    //cout << modInverse(divlater, mod) << endl;
    det *= modInverse(divlater, mod);
    det %= mod;
    if(det<0)det+=mod;
    return det;
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%lld",&matrix[i][j]);
    //gaussian_elimination();
    cout << gaussian_elimination();
}
