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
//#define ull unsigned long long
#define vi vector<int>
#define vl vector<long long>
typedef unsigned long long ull;
typedef long long ll;
#define SIZE 500001
struct Node{
	int L,R;
	ll Sum;
} Tree[SIZE];
ll Lazy[SIZE];
vi A(SIZE,0);
int Left(int x){
	return 2*x;
}
int Right(int x){
	return 2*x+1;
}
void BuildTree(int l,int r,int node){
	//printf("building [%d %d]\n",l,r );
	if(l==r){
		Tree[node].Sum=A[l];
		Tree[node].L=l;
		Tree[node].R=r;
	}
	else{
		int mid=(r+l)/2;
		BuildTree(l,mid,Left(node));
		BuildTree(mid+1,r,Right(node));
		Tree[node].L=l;
		Tree[node].R=r;
		Tree[node].Sum=Tree[Left(node)].Sum+Tree[Right(node)].Sum;
	}
}

void Update(int l,int r,int value,int node){
	//printf("update [%d %d]\n",l,r);
	if(Lazy[node]!=0){
		Tree[node].Sum+=Lazy[node];
		if(l!=r){
			Lazy[Left(node)]+=Lazy[node];//update left child
			Lazy[Right(node)]+=Lazy[node];//update right child
		}
		Lazy[node]=0;//reset
	}
	if(l==Tree[node].L && Tree[node].R==r){//exact interval
		Tree[node].Sum+=(r-l+1)*value;
		if(l!=r){
			int mid=(l+r)/2;
			Lazy[Left(node)]+=(mid-l+1)*value;
			Lazy[Right(node)]+=(r-mid)*value;
		}
		return;
	}
	if(l>r||l<Tree[node].L|| r>Tree[node].R)
		return;
	int mid=(Tree[node].L+Tree[node].R)/2;
	
	Update(l,mid,value,Left(node));
	Update(mid+1,r,value,Right(node));
	Tree[node].Sum=Tree[Left(node)].Sum+Tree[Right(node)].Sum;
}

ll Query(int l,int r,int node){
	if(Lazy[node]!=0){
		Tree[node].Sum+=Lazy[node];
		if(l!=r){

			Lazy[Left(node)]+=Lazy[node]/2;//update left child
			Lazy[Right(node)]+=(Lazy[node]-(ll)Lazy[node]/2);//update right child
		}
		Lazy[node]=0;//reset
	}
	if(l==Tree[node].L && Tree[node].R==r)//exact interval
		return Tree[node].Sum;//+=value;

	if(l>Tree[node].R || r<Tree[node].L)
		return 0;
	int mid=(Tree[node].L+Tree[node].R)/2;
	if(r<=mid)
		return Query(l,r,Left(node));
	if(l>mid)
		return Query(l,r,Right(node));
	return Query(l,mid,Left(node))+Query(mid+1,r,Right(node));
}
int main(){
	int T,N,M,p,q,v,tmp;
	scanf("%d",&T);
	while(T--){
		memset(Lazy,0,sizeof(Lazy));
		scanf("%d %d",&N,&M);
		//A.resize(N,0);
		BuildTree(1,N,1);
		//printf("done\n");
		while(M--){
			scanf("%d",&tmp);
			if(tmp){
				scanf("%d %d",&p,&q);
				printf("%lld\n",Query(p,q,1));
			}
			else{
				scanf("%d %d %d",&p,&q,&v);
				Update(p,q,v,1);
			}
		}
	}
	return 0;
}