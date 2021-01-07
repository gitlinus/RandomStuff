#include "stdc++.h"
typedef unsigned long long ull;
#define div 1000000007
void multiply(ull F[2][2], ull M[2][2]);
 
void power(ull F[2][2], ull n);
 
/* function that returns nth Fibonacci number */
ull fib(ull n)
{
  ull F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 
/* Optimized version of power() in method 4 */
void power(ull F[2][2], ull n)
{
  if( n == 0 || n == 1)
      return;
  ull M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(ull F[2][2], ull M[2][2])
{
  ull x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  ull y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  ull z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  ull w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
  x %= div;
  y %= div;
  z %= div;
  w %= div;
  
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 
/* Driver program to test above function */
int main()
{
  ull n;
  scanf("%llu", &n);
  printf("%llu", fib(n));
  
  return 0;
}