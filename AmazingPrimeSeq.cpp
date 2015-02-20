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
#define rep(i,a,N) for(int i=a;i<N;++i)
#define ull unsigned long long
#define vi vector<int>
#define vl vector<long long>
typedef long long ll;
#define SIZE 10000001
ll DP[SIZE];
int Fact(int N){
	int len=sqrt(N);
	rep(i,2,len+1)
		if(N%i==0)
			return i;
	return N;
}
void Init(){
	DP[0]=0;
	DP[1]=0;
	rep(i,2,SIZE)
		DP[i]=DP[i-1]+Fact(i);
}
int main(){
	Init();
	int T,N;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		printf("%lld\n",DP[N]);
	}
	return 0;
}