#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < pii > vpi; 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007

int t,n;
string str;
vi dp;

void lis(){
	rep(i,n)
		dp[i] = 1;

	reps(i,1,n)
		rep(j,i)
		 if(str[i] >= str[j])
		 	dp[i] = max(dp[i],1 + dp[j]);
}

void solve(){
	lis();

	rep(i,n)
		cout<<dp[i]<<" ";
	cout<<endl;
}

int main(){
	csl;
	cin>>t;
	while(t--){
		cin>>str;
		n = str.size();
		dp.resize(n);
		solve();
	}
	return 0;
}