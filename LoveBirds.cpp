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
#define MOD 1908
#define INF 1000009

int t,n;
int dp[1002];
void init(){
	dp[0] = 1;
	dp[1] = 1;
	reps(i,2,1002){
		dp[i] = 0;
		reps(j,1,i+1){
			dp[i] = (dp[i] + dp[i-j]*dp[j-1])%MOD;
		}
	}
}
int main(){
	csl;
	init();
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}