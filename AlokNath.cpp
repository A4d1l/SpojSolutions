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

string str1,str2;
int k,t;
ll ans;
ll dp[102][102],sum[102][102];
void solve(){
	int len1 = str1.size(),len2 = str2.size();
	ans = 0;

	rep(i,len1+1){
		rep(j,len2+1){
			dp[i][j] = 0;
			sum[i][j] = 0;
		}
	}
	
	reps(i,1,len1+1){
		reps(j,1,len2+1){
			if(str1[i] == str2[j]){
				sum[i][j] = str1[i] + sum[i-1][j-1];
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				sum[i][j] = max(sum[i-1][j],sum[i][j-1]);
			}
			if(dp[i][j] == k)
				ans = max(sum[i][j],ans);
			
		}
	}

	cout<<ans<<endl;
}

int main(){
	csl;
	cin>>t;
	while(t--){
		cin>>str1;
		cin>>str2;
		cin>>k;
		solve();
	}
	return 0;
}