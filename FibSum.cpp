#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <queue>
#include <iomanip>
#include <string>
#include <math.h>
#include <limits>
#include <map>
#include <float.h>
#include <limits.h>
#include <string.h>
using namespace std;
#define mod 1000000007
#define rep(i,a,N) for(int i=a;i<N;++i)
typedef long long ll;
 
//void multiply(int F[2][2], int M[2][2]);
 
//void power(int F[2][2], int n);

void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  (F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod;
  ll y =  (F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod;
  ll z =  (F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod;
  ll w =  (F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod;
 
  F[0][0] = x%mod;
  F[0][1] = y%mod;
  F[1][0] = z%mod;
  F[1][1] = w%mod;
}
 
 /* Optimized version of power() in method 4 */
void power(ll F[2][2], ll n)
{
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
/* function that returns nth Fibonacci number */
ll fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  if(n==1 || n==2)
    return 1;
  power(F, n-1);
  return F[0][0];
}
 

 
/* Driver program to test above function */
int main()
{
  int T,N,M;
  //ll Sum;
  scanf("%d",&T);
  while(T--){
    scanf("%lld",&N);
    printf("%lld\n", ((fib(N+2)+mod)%mod));
  }
}