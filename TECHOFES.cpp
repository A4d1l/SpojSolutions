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
#define SIZE 200099
#define INF 100000000000000

int t,n,m;
vpii arr;
int dp[24][20008];

void solve(){
	memset(dp,0,sizeof(dp));
	reps(i,1,n+1){
		rep(j,m+1){
			dp[i][j] = dp[i-1][j];
			if(j >= arr[i-1].first)
				dp[i][j] = max(dp[i][j],dp[i-1][j-arr[i-1].first] + arr[i-1].second);
		}
	}
	cout<<dp[n][m]<<endl;
}
int main(){
	boost;
	cin>>t;
	while(t--){
		cin>>n>>m;
		arr.resize(n);
		rep(i,n)
			cin>>arr[i].first>>arr[i].second;
		solve();
	}
	return 0;
}