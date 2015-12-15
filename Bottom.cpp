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
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 10009
#define INF 10000000000.0

vvi graph,trans;
int a,b,v,e;
stack<int> st;
bool visited[5009];
void transpose(){
	reps(i,1,v+1){
		rep(j,graph[i].size()){
			int v = graph[i][j];
			trans[v].push_back(i);
		}
	}
}

void fill_stack(int idx){
	visited[idx] = true;
	for(int i = 0;i<graph[idx].size();++i){
		if(!visited[graph[idx][i]])
			fill_stack(graph[idx][i]);
	}
	st.push(idx);
}

void dfs(int idx){
	visited[idx] = true;
	cout<<idx<<" ";
	for(int i = 0;i<trans[idx].size();++i){
		if(!visited[trans[idx][i]])
			dfs(trans[idx][i]);
	}
}
void solve(){
	memset(visited,false,sizeof(visited));
	fill_stack(1);
	transpose();
	memset(visited,false,sizeof(visited));

	while(!(st.empty())){
		int u = st.top(); st.pop();
		if(!visited[u]){
			dfs(u);
			cout<<endl;
		}
	}

}

int main(){
	boost;
	while(true){
		cin>>v;
		if(!v)
			return 0;
		cin>>e;
		graph.clear();
		graph.resize(v+1);
		trans.clear();
		trans.resize(v+1);
		rep(i,e){
			cin>>a>>b;
			graph[a].push_back(b);
		}
		solve();
	}

	return 0;
}