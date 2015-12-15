#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector < long long > vll;

typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vpii > vvpii;
typedef vector<vpll > vvpll;
typedef vector<string> vs;

#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define traverse(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000009
#define SIZE 50569
#define INF 10000000000000000

struct tree_node{
	ll mx,sm;
};

tree_node tree[4*SIZE];
ll arr[SIZE],n,x,y,m;

int left(int x){
	return x<<1;
}
int right(int x){
	return (x<<1) + 1;
}
void build(int node,int tl,int tr){
	if(tr == tl){
		tree[node].mx = tree[node].sm = arr[tl];
	} else{
		int tm = (tl + tr) >> 1;
		build(left(node),tl,tm);
		build(right(node),tm+1,tr);
		tree[node].sm = tree[left(node)].sm + tree[right(node)].sm;
		tree[node].mx = max(tree[left(node)].mx,max(tree[right(node)].mx,max(tree[left(node)].sm,max(tree[right(node)].sm,max(tree[node].sm,max(tree[left(node)].mx + tree[right(node)].mx,max(tree[left(node)].mx+tree[right(node)].sm,tree[right(node)].mx+tree[left(node)].sm)))))));
 	}
}

ll query(int node,int tl,int tr,int l,int r){
	if(l>r){
		return LLONG_MIN;
	}
	if(tl == l && tr == r){
		return tree[node].mx;
	} else{
		int tm = (tl + tr) >> 1;
		return max(query(left(node),tl,tm,l,min(r,tm)),query(right(node),tm+1,tr,max(l,tm+1),r));
	}
}
int main(){
	csl;
	cin>>n;
	reps(i,1,n+1)
		cin>>arr[i];
	build(1,1,n);
	cin>>m;
	rep(i,m){
		cin>>x>>y;
		cout<<query(1,1,n,x,y)<<endl;
	}
	return 0;
}