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
#define mod 1000000007
#define SIZE 1<<31+10001
vi A[10000000000];
int main(){
	int N,M,count=1,tmp;
	char ch;
	scanf("%d %d",&N,&M);
	rep(i,0,N){
		scanf("%d",&tmp);
		A[tmp].push_back(count++);
	}
	while(M--){
		scanf(" %c %d",&ch,&tmp);
		if(ch=='I'){
			A[tmp].push_back(count++);
			printf("%d\n",count-1);
		}
		else if(ch=='S'){
			if(A[tmp].size()!=0)
				printf("%d\n",A[tmp][0]);
			else
				printf("NONE\n");
		}
		else{// D
			if(A[tmp].size()!=0){
				printf("%d\n",A[tmp][0]);
				A[tmp].erase(A[tmp].begin());
			}
			else
				printf("NONE\n");
		}
	}

	return 0;
}