#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define INF 1000009

int dp[1001][22][81];
int oxyVol,nitroVol,t,n;
int nitrogen[1001],oxygen[1001],weight[1001];
void solve(){

	rep(j,22)
		rep(k,81)
			dp[0][j][k] = INF;

	rep(i,1001)
		dp[i][0][0] = 0;

	for(int i=1;i<=n;++i){
		for(int j=0;j<=21;++j){
			for(int k=0;k<=80;++k){
				dp[i][j][k] = min(dp[i-1][j][k],dp[i-1][j>=oxygen[i-1]?j-oxygen[i-1]:0][k>=nitrogen[i-1] ? k-nitrogen[i-1] : 0] + weight[i-1]);
			}
		}
	}

	cout<<dp[n][oxyVol][nitroVol]<<endl;
}
int main(){
	csl;
	cin>>t;
	while(t--){
		cin>>oxyVol>>nitroVol;
		cin>>n;
		rep(i,n)
			cin>>oxygen[i]>>nitrogen[i]>>weight[i];
		solve();
	}
	return 0;
}