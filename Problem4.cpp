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

ll dp[40][40][2];
int t,n;
vll arr;
// int recur(int start, int end){
// 	if(dp[start][end] != -1)
// 		return dp[start][end];
// 	if(start == end)
// 		return dp[start][end] = arr[start];
// 	if(end == (start + 1))
// 		return dp[start][end] = max(arr[start],arr[end]); 
	
// 	int sub[4];
// 	sub[0] = arr[start] + recur(start+1,end-1);
// 	sub[1] = arr[start] + recur(start+2,end);
// 	sub[2] = arr[end] + recur(start+1,end-1);
// 	sub[3] = arr[end] + recur(start,end-2);

// 	cout<<arr[start]<<" "<<arr[end]<<endl;
// 	cout<<arr[start + 1]<<" "<<arr[end - 1]<<endl;
// 	rep(i,4){
		
// 		cout<<i<<" : "<<sub[i]<<endl;
// 	}
// 	rep(i,4)
// 		dp[start][end] = max(dp[start][end],sub[i]);
// 	return dp[start][end];

// }

// int optimal(int start,int end, bool turn){
// 	if(dp[start][end] != -1)
// 		return dp[start][end];
// 	if(start == end)
// 		return dp[start][end] = arr[start];
// 	if(end == (start + 1))
// 		return dp[start][end] = max(arr[start],arr[end]);
	
// 	return dp[start][end] = max(arr[start] + optimal(start+1,end,!turn),arr[end]+optimal(start,end-1,!turn));
	
// }
int main(){
	csl;
	cin>>t;
	while(t--){
		cin>>n;
		arr.resize(n+1);
		reps(i,1,n+1)
			cin>>arr[i];
		
		
		memset(dp,0,sizeof(dp));

		reps(i,1,n+1){
			dp[i][i][0] = arr[i];
			dp[i][i][1] = arr[i];
			
			if((i+1)<=n){
				dp[i][i+1][0] = max(arr[i],arr[i+1]);
				dp[i][i+1][1] = max(arr[i],arr[i+1]);
			}

		}

		for(int j=2;j<=n-1;++j){
			for(int i=1;(i+j)<=n;++i){
				dp[i][i+j][0] = max(arr[i] + dp[i+1][i+j][1],arr[i+j] + dp[i][i+j-1][1]);
				dp[i][i+j][1] = max(dp[i+1][i+j][0],dp[i][i+j-1][0]);
			}
		}

		cout<<dp[1][n][0]<<" ";

		reps(i,1,n+1){
			dp[i][i][0] = arr[i];
			dp[i][i][1] = arr[i];
			
			if((i+1)<=n){
				dp[i][i+1][0] = max(arr[i],arr[i+1]);
				dp[i][i+1][1] = min(arr[i],arr[i+1]);
			}

		}

		for(int j=2;j<=n-1;++j){
			for(int i=1;(i+j)<=n;++i){
				dp[i][i+j][0] = max(arr[i] + dp[i+1][i+j][1],arr[i+j] + dp[i][i+j-1][1]);
				dp[i][i+j][1] = min(dp[i+1][i+j][0],dp[i][i+j-1][0]);
			}
		}

		cout<<dp[1][n][0]<<endl;

	}
	return 0;
}