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
#define SIZE 1000999
#define INF 100000000000000

ll n,k,m;

void solve(){
	ll ans = 1;
	ll tmp = n*k;
	while(tmp < m){
		++ans;
		tmp = (tmp*k);
	}
	if(tmp > m)
		--ans;
	printf("%lld\n", ans);
}
int main(){
	//boost;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld %lld",&n,&k,&m);
		solve();
	}
	return 0;
}