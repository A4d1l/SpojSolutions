#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
typedef vector<string> vs;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define INF 1000009

int t,m,n;
vi x,y;
int dp[1001][1001];

void solve(){
	
	rep(i,1001)
		rep(j,1001)
			dp[i][j] = 0;

	reps(i,2,m+1)
		dp[1][i] = dp[1][i-1] + x[i-1];

	reps(i,2,n+1)
		dp[i][1] = dp[i-1][1] + y[i-1];
		
	reps(i,2,n+1)
		reps(j,2,n+1)
			dp[i][j] = min(dp[i][j-1] +  dp[i][1] + x[j-1],dp[i-1][j] + dp[1][j] + y[i-1]);

	cout<<dp[n][m]<<endl;
}

int main(){
	csl;
	cin>>t;
	while(t--){
		cin>>n>>m;
		x.resize(m);
		y.resize(n);
		//column
		reps(i,1,m){
			cin>>x[i];
		}
		//row
		reps(i,1,n)
			cin>>y[i];
		solve();
	}
	return 0;
}