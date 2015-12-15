#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < pii > vii;
typedef vector <vii> Adj; 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define s(n) cin >> n
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define INF 100000000

Adj adj;
int dist[1000001];
int t,n,m,src,dest,wt,s,e;

void PrintGraph(){
	reps(i,1,n+1){
		cout<<"from vertex "<<i<<" ";
		rep(j,adj[i].size())
			cout<<"("<<adj[i][j].first<<","<<adj[i][j].second<<") ";
		cout<<endl;
	}
}

class mycompare{
public:
	bool operator()(pii p1, pii p2){
		return p1.first<p2.first;
	}
};

void Dijkstra(int s){
	rep(i,n+1)
		dist[i]=INF;
	dist[s]=0;
	priority_queue<pii, vii, greater<pii> > pq;			//priority queue of dist,vertex
	pq.push(pii(0,s));
	while(!pq.empty()){
		pii top=pq.top();pq.pop();
		int d=top.first,u=top.second;
		if(d==dist[u]){							//there are multiple instances of a single vertex so we need to pick the optimal one so that queue can be emptied
			rep(i,adj[u].size()){
				int v=adj[u][i].first, weight=adj[u][i].second;
				if(dist[u]+weight<dist[v]){
					dist[v]=dist[u]+weight;
					pq.push(pii(dist[v],v));
				}
			}
		}
	}
	if(dist[e]==INF)
		printf("NONE\n");
	else
		printf("%d\n",dist[e]);
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d",&n,&m,&s,&e);//cin>>n>>m>>s>>e;
		adj.clear();
		adj.resize(n+1);
		rep(i,m){
			scanf("%d %d %d",&src,&dest,&wt);
			//cin>>src>>dest>>wt;
			adj[src].push_back(pii(dest,wt));
			adj[dest].push_back(pii(src,wt));
		}
		Dijkstra(s);
	}
	return 0;
}