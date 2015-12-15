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
#define SIZE 10000009
#define INF 10000000000000

int t,n,m,tmp;
vi a,b,arr;

int lds(vi &x){
	//cout<<"array "<<endl;
	int len = x.size();
	// rep(i,len)
	// 	cout<<x[i]<<" ";
	// cout<<endl;
	int dp[len];
	rep(i,len)
		dp[i] = 1;
	
	reps(i,1,len){
		rep(j,i){
			if(x[i]<x[j])
				dp[i] = max(dp[i],dp[j] + 1);
		}
	}
	// rep(i,len)
	// 	cout<<dp[i]<<" ";
	// cout<<endl;
	// cout<<"returning "<<dp[len-1]<<" for "<<len<<endl;
	return dp[len-1];
}
int lds2(vi &x){
	//cout<<"array "<<endl;
	int len = x.size();
	// rep(i,len)
	// 	cout<<x[i]<<" ";
	// cout<<endl;
	int dp[len];
	rep(i,len)
		dp[i] = 1;
	
	reps(i,1,len){
		rep(j,i){
			if(x[i]<x[j])
				dp[i] = max(dp[i],dp[j] + 1);
		}
	}
	// rep(i,len)
	// 	cout<<dp[i]<<" ";
	// cout<<endl;
	// cout<<"returning "<<dp[len-1]<<" for "<<len<<endl;
	int ans = 1;
	rep(i,len)
		ans = max(ans,dp[i]);
	return ans;
}

void solve(){
	int ans1 = lds(a) + lds2(b);
	int ans2 = lds2(arr); 
	cout<<max(ans1,ans2)<<endl;
}
int main(){
	csl;
	cin>>t;
	while(t--){
		cin>>n>>m;
		arr.clear();
		a.clear();
		b.clear();

		rep(i,m+1){
			cin>>tmp;
			a.push_back(tmp);
			arr.push_back(tmp);
		}
		rep(i,n-m-1){
			cin>>tmp;
			b.push_back(tmp);
			arr.push_back(tmp);
		}
		
		solve();

	}
	return 0;
}