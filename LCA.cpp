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
#define fill(x,y) memset(x,y,sizeof(x))
#define MOD 1000000007
#define SIZE 2000009
#define INF 100000000

int n,q,lg,timer;
vi tin,tout,depth;
vvi graph;
vvi dp;

void dfs(int u,int parent = 1){
	tin[u] = ++timer;
	dp[u][0] = parent;
	//cout<<"dp[ "<<u<<"][0] "<<parent<<endl;
	reps(i,1,lg+1)
		dp[u][i] = dp[dp[u][i-1]][i-1];

	rep(i,graph[u].size()){
		int v = graph[u][i];
		if(v != parent){
			depth[v] = depth[u] + 1;
			dfs(v,u);
		}
	}
	tout[u] = ++timer;
}

bool is_ancestor(int a,int b){
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}

int lca(int u,int v){
	if(is_ancestor(u,v)) return u;
	if(is_ancestor(v,u)) return v;
	//cout<<"calculating lca for "<<u<<" "<<v<<endl;
	for(int i = lg;i >= 0; --i){
		if(!is_ancestor(dp[u][i],v))
			u = dp[u][i];
	}
	//cout<<"returning "<<u<<" 0"<<dp[u][0]<<endl;
	return dp[u][0];
}

int calc(int u,int v){
	int x = lca(u,v);
	return depth[u] + depth[v] - 2*depth[x];
}
void solve(int u,int v){
	cout<<lca(u,v)<<endl;
	// //cout<<"solving "<<endl;
	// int a,b,c,x,y,z;
	// a = lca(u,v);
	// b = lca(r,v);
	// c = lca(r,u);
	// x = calc(a,u) + calc(a,v) + calc(a,r);
	// y = calc(b,u) + calc(b,v) + calc(b,r);
	// z = calc(c,u) + calc(c,v) + calc(c,r);
	// // cout<<a<<endl;
	// // cout<<b<<endl;
	// // cout<<c<<endl;
	// // cout<<x<<endl;
	// // cout<<y<<endl;
	// // cout<<z<<endl;
	// vpii tmp;
	// tmp.push_back(make_pair(x,a));
	// tmp.push_back(make_pair(y,b));
	// tmp.push_back(make_pair(z,c));	
	// sort(all(tmp));
	// cout<<tmp[0].second<<endl;
	
}
void init(){
	graph.clear();
	dp.clear();
	tin.clear();
	tout.clear();
	depth.clear();
	
	graph.resize(n+1);
	dp.resize(n+1);
	tin.resize(n+1);
	tout.resize(n+1);
	depth.resize(n+1,0);
	lg = 1;
	while((1<<lg) <= n) ++lg;
	rep(i,n+1){
		dp[i].resize(lg + 1);
	}
}
int main(){
	csl;
	int u,v,r,m,tmp,t;
	cin>>t;
	for(int test = 1;test<=t;++test){
		cout<<"Case "<<test<<":"<<endl;
		cin>>n;
		init();
		reps(i,1,n+1){
			cin>>m;
			while(m--){
				cin>>tmp;
				graph[i].push_back(tmp);
				graph[tmp].push_back(i);
			}
		}
		dfs(1);
		//cout<<"dfs done "<<endl;
		cin>>q;
		while(q--){
			cin>>u>>v;
			solve(u,v);
		}
	}
	return 0;
}