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
#define SIZE 10001
//Adj List(1000);
int Parent[SIZE],Rank[SIZE];
bool Flag;
int FindSet(int a){
	if(a==Parent[a])
		return a;
	return FindSet(Parent[a]);
}
void MakeSet(int a){
	Parent[a]=a;
	Rank[a]=0;
}
void Union(int a,int b){
	a=FindSet(a);
	b=FindSet(b);
	if(a!=b){
		if(Rank[a]<Rank[b])
			swap(a,b);
		Parent[b]=a;
		if(Rank[a]==Rank[b])
			++Rank[a];
	}
	else
		Flag=true;
	
}
/*
bool isCyclic(int i,bool Visited[]){
	if(Visited[i])
		return true;
	Visited[i]=true;
	//printf("%d->",i );
	TRvii(List[i],it){
		if(*it!=i)
			if(!Visited[*it] && isCyclic(*it,Visited))
				return true;

	}
	return false;
	printf("\n");
}
*/
int main(){
	int N,M,a,b;
	scanf("%d %d",&N,&M);
	if(N!=M+1)
		printf("NO\n");
	else{
		rep(i,1,N+1)
			MakeSet(i);
		Flag=false;
		//List.resize(N+1);
		//bool Visited[N+1];
		//memset(Visited,false,sizeof(Visited));
		while(M--){
			scanf("%d %d",&a,&b);
			Union(a,b);	
		}
		if(Flag)
			printf("NO\n");
		else
			printf("YES\n");
	}











/*
	if(isCyclic(1,Visited))
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
*/

	return 0;
}