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
#define SIZE 100009
#define INF 100000000

ll dp[SIZE][6];
ll arr[5];
int n,t;

void solve(){
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = 6;
	arr[3] = 7;
	arr[4] = 8;

	rep(i,SIZE)
		rep(j,5)
			dp[i][j] = 0;
	reps(i,1,5)
		dp[0][i] = 1;

	reps(i,1,SIZE){
		reps(j,1,6){
			dp[i][j] = dp[i][j-1];
			if(i >= arr[j-1])
				dp[i][j] += dp[i - arr[j-1]][j];
		}
	}
}
int main(){
	csl;
	solve();
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[n][5]<<endl;
	}
	return 0;
}