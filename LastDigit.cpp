#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <sstream>
#include <vector>
using namespace std;
#define rep(i,a,N) for(int i=a;i<N;++i)


 long long pow_( long long base, long long exp, long long  m){
  long long  ret=1;
   base%=m;
   while(exp)
   {
     if(exp&1)
      {
       ret*=base;
       ret%=m;
      }
      base*=base;
      base%=m;
      exp>>=1;
    }
   return ret%m;
 }

 int main(){
 	int T;
 	unsigned long long a,b;
 	scanf("%d",&T);
 	while(T--){
 		scanf("%llu %llu",&a,&b);
 		printf("%llu\n",pow_(a,b,10) );
 	}
 	return 0;
 }