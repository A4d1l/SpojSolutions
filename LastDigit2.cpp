#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;
#define rep(i,a,N) for(int i=a;i<N;++i)


 long long pow_( int base, long long exp){
  long long  ret=1;
   base%=10;
   while(exp)
   {
     if(exp&1)
      {
       ret*=base;
       ret%=10;
      }
      base*=base;
      base%=10;
      exp>>=1;
    }
   return ret%10;
 }

 int main(){
  int T;
  char str[1001];
  unsigned long long b;
  int a;
  scanf("%d",&T);
  while(T--){
    scanf(" %s %llu",str,&b);
    //printf("input = %s %llu\n",str,b);
    a=str[strlen(str)-1]-'0';
    //printf("%llu\n",a );
    if(a==0)
      printf("0\n");

    else
    printf("%llu\n",pow_(a,b) );
  }
  return 0;
 }