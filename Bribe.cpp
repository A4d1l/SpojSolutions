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

ll t,n,m;
vll arr;
ll dp[10001][10001];
ll rec(int start,int end){
	if(dp[start][end] != -1)
		return dp[start][end];
	if(end < start){
		return dp[start][end] = 0;
	}
	int tmp = 0,ans = INT_MAX;
	for(int i = 1;i<=m;++i){
		if(arr[i]<=end && arr[i] >= start){
			tmp = end - start;
			if(start <= (arr[i] - 1))
				tmp += rec(start,arr[i] - 1);
			if((arr[i]+1) <= end)
				tmp += rec(arr[i] + 1,end);
		
			ans = min(tmp,ans);
		}
	}
	if(ans == INT_MAX)
		ans = 0;
	return dp[start][end] = ans;
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cout<<rec(1,n)<<endl;
}
int main(){
	csl;
	cin>>t;
	for(int test = 1;test<=t;++test){
		cout<<"Case #"<<test<<": ";
		cin>>n>>m;
		arr.resize(m+1);
		reps(i,1,m+1)
			cin>>arr[i];
		solve();
	}
	return 0;
}