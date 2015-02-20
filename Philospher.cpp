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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> ADJ;
typedef map<string, int> msi;

#define rep(i,a,N) for(int i=a;i<N;++i)
#define TRvii(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)
#define TR(c, it) for(typeof(c) it=(c).begin();it!=(c).end();++it )
#define mod 1000000007
#define SIZE 101
int W,H;
int Arr[SIZE][SIZE];
int DP[SIZE][SIZE];
int Calculate(int i,int j){
	if(DP[i][j]!=-1)
		return DP[i][j];
	if(i==W-1)
		return Arr[i][j];

	int a=0,b=0,c=0;
	if(j>0)
		a=Calculate(i+1,j-1);
	if(j<H-1)
		b=Calculate(i+1,j+1);
	c=Calculate(i+1,j);
	return DP[i][j]=(Arr[i][j]+max(a,max(b,c)));
}
int main(){
	int T,MAX;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&W,&H);
		memset(DP,-1,sizeof(DP));
		rep(i,0,W)
			rep(j,0,H)
				scanf("%d",&Arr[i][j]);
		MAX=0;
		rep(i,0,H)
			MAX=max(MAX,Calculate(0,i));
		printf("%d\n",MAX );
	}
	return 0;
}