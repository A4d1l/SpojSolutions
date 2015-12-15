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
#define INF 100000000009

int getMaxSum(vi arr){
	if(arr.size() == 1)
		return arr[0];
	if(arr.size() == 0)
		return 0;
	vi dp(arr.size(),0);
	int len = arr.size();
	dp[0] = arr[0];
	dp[1] = max(dp[0],arr[1]);
	reps(i,2,len)
		dp[i] = max(dp[i-1],dp[i-2] + arr[i]);
	return dp[len-1];
}
int main(){
	csl;
	int n,m;
	vi arr;
	vvi mat;
	while(true){
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		mat.clear();
		arr.clear();
		mat.resize(n);
		arr.resize(n);
		rep(i,n){
			mat[i].clear();
			mat[i].resize(m);
		}
		rep(i,n){
			rep(j,m){
				cin>>mat[i][j];
			}
			arr[i] = getMaxSum(mat[i]);
		}
		cout<<getMaxSum(arr)<<endl;
	}
	return 0;
}