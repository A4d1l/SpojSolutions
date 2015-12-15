#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define traverse(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 5000009

ll dp[351];
int n;
void solve(){
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 4;i <= 301;i += 2){
		dp[i] = 0;
		for(int j = 2;j<=i;j += 2)
			dp[i] += (dp[i-j]*dp[j-2]);
	}
}
int main(){
	solve();
	while(scanf("%d",&n)){
		if(n == -1)
			break;
		cout<<dp[2*n]<<endl;
	}
	return 0;
}