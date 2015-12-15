#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define INF 100000000009

int dp[20][100],n,k,t;
void init(){
	rep(i,20)
		dp[i][0] = 1;
	rep(i,100)
		dp[0][i] = 0;
	for(int i=1;i<20;++i){
		for(int j=1;j<100;++j){
			dp[i][j] = 0;
			for(int k=0;k<=j && k<i;++k)
				dp[i][j]+=dp[i-1][j-k];
		}
	}
}
int main(){
	csl;
	init();
	cin>>t;
	while(t--){
		cin>>n>>k;
		cout<<dp[n][k]<<endl;
	}
	return 0;
}