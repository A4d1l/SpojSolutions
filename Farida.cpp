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

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> ADJ;
typedef map<string, int> msi;

#define rep(i,a,N) for(int i=a;i<N;++i)
#define TRvii(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)
#define TR(c, it) for(typeof(c) it=(c).begin();it!=(c).end();++it )
#define mod 100000007
#define SIZE 10009

vector<ull> DP(SIZE);


int main(){
	int T,N;
	scanf("%d",&T);
	rep(k,1,T+1){
		scanf("%d",&N);
		if(N){
			DP.resize(N+4,0LL);
			rep(i,0,N)
				scanf("%llu",&DP[i]);
			if(N==1)
				printf("Case %d: %llu\n",k,DP[0]);
			else{
				DP[N-2]=max(DP[N-2],DP[N-1]);
				if(N>2){
					for(int i=N-3;i>=0;--i)
						DP[i]=max(DP[i+1],DP[i]+DP[i+2]);
					}
				printf("Case %d: %llu\n",k,DP[0]);
					}
			}
		else
			printf("Case %d: 0\n",k);
		}

	
	return 0;
}