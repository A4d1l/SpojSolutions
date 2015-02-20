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
#define ll long long
#define ull unsigned long long
//ull DP[10001];

void Init(ull N){
	ull sum=0,tmp;
	for(int i=1;i<=N;i++){
		tmp=0;
		for(int j=1;j*j<=i;j++)
			if(i%j==0)
				tmp++;
		sum+=tmp;
		//DP[i]=sum;
	
	}
		printf("%llu\n",sum);
}
int main(){
	
	ull N;
	scanf("%llu",&N);
	Init(N);
	//printf("%llu\n",sum);
}