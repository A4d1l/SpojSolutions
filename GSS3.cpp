#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define s(n) cin >> n
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)


int T,N,Q,a,b,tmp,A[50000];
struct Node{
	int L,R,Sum;
}Tree[400004];

int Left(int x){
	return 2*x;
}

int Right(int x){
	return 2*x+1;
}

void MakeTree(int l,int r,int A[],int node){
	printf("MakeTree [%d %d]\n",l,r);
	if(l==r){
		//printf("l==r\n");
		Tree[node].L=l;
		Tree[node].R=r;
		Tree[node].Sum=A[l];
	}
	else{
		int mid=(l+r)/2;
		MakeTree(l,mid,A,Left(node));
		MakeTree(mid+1,r,A,Right(node));
		Tree[node].L=l;
		Tree[node].R=r;
		Tree[node].Sum=max(Tree[Left(node)].Sum+Tree[Right(node)].Sum,max(Tree[Right(node)].Sum,Tree[Left(node)].Sum));

	}
	printf("make tree complete for [%d %d]\n",l,r);
}

int Query(int l,int r,int node){
	//printf("query with [%d %d]\n",l,r);
	if(l==Tree[node].L && r==Tree[node].R){
	//	printf("base case\n");
		return Tree[node].Sum;
	}
	int mid=(Tree[node].L+Tree[node].R)/2;
	if(r<=mid){
	//	printf("left side\n");
		return Query(l,r,Left(node));
	}
	if(l>mid){
	//	printf("right side\n");
		return Query(l,r,Right(node));
	}
	//printf("overlap\n");
	int a,b,c;
	a=Query(l,mid,Left(node));
	b=Query(mid+1,r,Right(node));
	return max(a+b,max(a,b));
}

void Update(int index,int value,int node){

	if(index==Tree[node].L && index==Tree[node].R)
		Tree[node].Sum=value;
	if(index<Tree[node].L || index>Tree[node].R)
		return;
	Update(index,value,Left(node));
	Update(index,value,Right(node));
}
int main(){
	csl;	
	cin>>N;
	rep(i,N)
		cin>>A[i];

	MakeTree(1,N,A,1);
	cin>>Q;
	while(Q--){
		cin>>tmp>>a>>b;
		if(tmp)//tmp=1
			cout<<Query(a,b,1)<<endl;
		else
			Update(a,b,1);
	}
	return 0;
}