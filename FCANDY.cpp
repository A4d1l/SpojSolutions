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
#define INF 100000000000000

int n;
vpii arr;
int dp[105][100005];
int total;
void solve(){
	int sum = ((total >> 1) + (total & 1));
	
	for(int i = 1;i <= n; ++i){
		for(int k = 0;k <= sum;++k){
			dp[i][k] = dp[i-1][k];
			for(int j = 0;j <= arr[i-1].first; ++j){
				if(k >= arr[i-1].second * j)
					dp[i][k] = max(dp[i-1][k - arr[i-1].second*j] + arr[i-1].second*j , dp[i][k]);
			}
		}
	}
	//cout<<total<<endl;
	cout<<abs(total -  2*dp[n][sum])<<endl;
}
int main(){
	boost;
	cin>>n;
	arr.resize(n);
	rep(i,n){
		cin>>arr[i].first>>arr[i].second;
		total += arr[i].first * arr[i].second;
	}
	solve();
	return 0;
}