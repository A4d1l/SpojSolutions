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
//#define INF 100000000000000

int t,m,n;
vs arr;
long long dp[105][105];
const long long INF = INT_MAX;
void solve(){
	rep(i,m)
		rep(j,n)
			dp[i][j] = INF;
	dp[0][0] = 0;
	rep(i,m){
		rep(j,n){
			if(arr[i][j] != '#'){
				if(((j+1) < n) && arr[i][j+1] != '#')
					dp[i][j+1] = min(dp[i][j+1],1+dp[i][j]);
				if(((i+1) < m) && arr[i+1][j] != '#')
					dp[i+1][j] = min(dp[i+1][j],1+dp[i][j]);
				if(((j + 1 + arr[i][j] - '0') < n) && arr[i][j + 1 + arr[i][j] - '0'] != '#')
					dp[i][j + 1 + arr[i][j] - '0'] = min(dp[i][j + 1 + arr[i][j] - '0'],1+dp[i][j]);
				if(((i + 1 + arr[i][j] - '0') < m) && arr[i + 1 + arr[i][j] - '0'][j] != '#')
					dp[i + 1 + arr[i][j] - '0'][j] = min(dp[i + 1 + arr[i][j] - '0'][j],1+dp[i][j]);
			}
		}
	}
	
	if(dp[m-1][n-1] == INF)
		dp[m-1][n-1] = -1;

	cout<<dp[m-1][n-1]<<endl;
}
int main(){
	boost;
	cin>>t;
	while(t--){
		cin>>m>>n;
		arr.resize(m);
		rep(i,m)
			cin>>arr[i];
		solve();
	}
	return 0;
}