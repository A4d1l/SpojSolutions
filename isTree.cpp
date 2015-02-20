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
//typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> Adj;
typedef map<string, int> msi;

#define rep(i,a,N) for(int i=a;i<N;++i)
#define TRvii(c,it) for(vi::iterator it=(c).begin();it!=(c).end();it++)
#define TR(c, it) for(typeof(c) it=(c).begin();it!=(c).end();++it )
#define mod 1000000007
#define SIZE 100001
Adj List(10001);

bool isCyclic(int i,bool Visited[],int parent){
	if(Visited[i])
		return true;
	Visited[i]=true;
	//printf("%d->",i );
	TRvii(List[i],it){
		if(*it!=parent)
			if(isCyclic(*it,Visited,i))
				return true;

	}
	return false;
	//printf("\n");
}
int main(){
	int N,M,a,b;
	scanf("%d %d",&N,&M);
	List.resize(N+1);
	bool Visited[N+1];
	memset(Visited,false,sizeof(Visited));
	while(M--){
		scanf("%d %d",&a,&b);
		List[a].push_back(b);
		List[b].push_back(a);
	}
	if(isCyclic(1,Visited,-1))
		printf("NO\n");
	else{
	//	printf("else\n");
		rep(i,1,N+1)
			if(!Visited[i]){
				printf("NO\n");
				return 0;
			}
		printf("YES\n");
	}


	return 0;
}