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

ll dp[1001][1001];
vll arr;
int n,k,t;
ll rec(int pos,int K){
	if(pos>=n)
		return 0;
	if(K<=0)
		return 0; 
	if(dp[pos][K] != -1)
		return dp[pos][K];
	ll exclude = rec(pos+1,K);
	ll include = K>=arr[pos] ? arr[pos] + rec(pos + 2,K-arr[pos]) : 0;

	return dp[pos][K] = max(include,exclude);
}

int main(){
	csl;
	cin>>t;
	for(int test = 1;test<=t;++test){
		cin>>n>>k;
		arr.resize(n);
		rep(i,n)
			cin>>arr[i];
		memset(dp,-1,sizeof(dp));
		cout<<"Scenario #"<<test<<": ";
		cout<<rec(0,k)<<endl;
	}
	return 0;
}