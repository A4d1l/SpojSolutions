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
#define SIZE 1<<31+10001

int main(){
	int T;
	ll Ans,Ans2;
	char ch;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&Ans);
			scanf(" %c",&ch);
			//printf("%lld %c\n",Ans,ch);
			while(ch!='='){
				scanf("%lld",&Ans2);
				if(ch=='*')
					Ans*=Ans2;
				else if(ch=='+')
					Ans+=Ans2;
				else if(ch=='-')
					Ans-=Ans2;
				else
					Ans/=Ans2;
				scanf(" %c",&ch);
			//	printf("%lld %c\n",Ans2,ch);
			}
		printf("%lld\n",Ans );

	}
	return 0;
}