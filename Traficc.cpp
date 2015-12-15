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
#define MOD 1000000007
#define SIZE 5000009
#define INF 1000000000000000

ll n,m,a,b,c,s,t,k;
vll dist;
vvpll graph;
map<pair<ll,ll>,bool> check;
void dijkstra(){
	// first is weight, second is index
	priority_queue<pll,vpll,greater<pll> > pq;

	pq.push(make_pair(0LL,s));
	dist[s] = 0LL;
	while(!pq.empty()){
		pll top = pq.top(); pq.pop();
		ll w = top.first, u = top.second;
		if(w == dist[u]){
			for(ll i = 0; i < graph[u].size();++i){
				ll v = graph[u][i].first, weight = graph[u][i].second;
				if(weight + dist[u] < dist[v]){
					dist[v] = weight + dist[u];
					pq.push(make_pair(dist[v],v));
				}
 			}
		}
	}
}

void solve(){
	dist.clear();
	dist.resize(n+1,INF);

	dijkstra();
	ll ans = dist[t];
	rep(i,k){
		cin>>a>>b>>c;
	}
}

int main(){
	csl;
	int test;
	cin>>test;
	while(test--){
		cin>>n>>m>>k>>s>>t;
		graph.clear();
		graph.resize(n+1);
		rep(i,m){
			cin>>a>>b>>c;
			graph[a].push_back(make_pair(b,c));
		}
		solve();
	}
	return 0;
}