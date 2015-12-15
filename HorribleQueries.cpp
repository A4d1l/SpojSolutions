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
#define SIZE 100009
#define INF 10000000000.0

ll arr[SIZE],tree[4*SIZE],lazy[4*SIZE];
ll t,n,p,q,v,tmp,c;


int left(int x){
	return x<<1;
} 

int right(int x){
	return ((x<<1) + 1);
}

void build_tree(int node,int tl,int tr){
	if(tl == tr){
		tree[node] = arr[tl];
		lazy[node] = tree[node];
	} else{
		int tm = (tl + tr)/2;
		build_tree(left(node),tl,tm);
		build_tree(right(node),tm+1,tr);
		tree[node] = tree[left(node)] + tree[right(node)];
		lazy[node] = tree[node];
	}
}

void update(int node,int tl,int tr,int l,int r,ll value){
	//cout<<"upadating "<<tl<<" "<<tr<<" : "<<l<<" "<<r<<" with "<<value<<endl;
	if(lazy[node] != 0){
		tree[node] += (tr - tl +1)*lazy[node];
	//	cout<<"updating lazy node "<<tl<<" : "<<tr<<" "<<tree[node]<<endl;
		if(tl != tr){
			lazy[left(node)] += lazy[node];	// pushing the value down
			lazy[right(node)] += lazy[node];
		}
		lazy[node] = 0; // reseting the value
	}

	if(l>r){
		return;
	}

	if((l == tl) && (r == tr)){
		tree[node] += (r - l + 1)*value;
		if(tl != tr){
			lazy[left(node)] += value;
			lazy[right(node)] += value; 
		}
	} else{
		int tm = (tl + tr)/2;

		update(left(node),tl,tm,l,min(tm,r),value);
		update(right(node),tm+1,tr,max(tm+1,l),r,value);
		tree[node] = (tree[left(node)] + tree[right(node)]);
	}
}

ll query(int node,int tl,int tr,int l,int r){
	
	if(lazy[node] != 0){
		tree[node] += (tr - tl + 1)*lazy[node];
		if(tl != tr){
			lazy[left(node)] += lazy[node];	// pushing the value down
			lazy[right(node)] += lazy[node];
		}
		lazy[node] = 0; // reseting the value
	}

	if(l>r){
//		cout<<"retunring 0"<<endl;
		return 0;
	}
	if((l == tl) && (r == tr)){
//		cout<<"lazy "<<lazy[node]<<endl;
//		cout<<"returning "<<tree[node]<<endl;
		return tree[node];
	} else{
		int tm = (tl + tr)/2;
		ll ret = query(left(node),tl,tm,l,min(r,tm)) + query(right(node),tm+1,tr,max(tm+1,l),r);
//		cout<<"returning "<<ret<<endl; 
		return ret;
	}
}

void update(int l,int r,ll value){
	update(1,1,n,l,r,value);
}

ll query(int l,int r){
	return query(1,1,n,l,r);
}


int main(){
	csl;
	cin>>t;
	while(t--){
		cin>>n>>c;
		memset(arr,0,sizeof(arr));
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		build_tree(1,1,n);
		while(c--){
			cin>>tmp;
			if(tmp == 0){
				cin>>p>>q>>v;
				update(p,q,v);
			} else{
				cin>>p>>q;
				//cout<<"checking for "<<p<<" "<<q<<endl;
				cout<<query(p,q)<<endl;
			}
		}
	}
	return 0;
}