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
vi a,b,result,dp;
vpi endPoints;

bool compare1(pii x, pii y) {
	return x.first <= y.first;
}


bool compare2(pii x, pii y) {
	return x.second <= y.second;
}

void reset(){
	a.clear();
	a.resize(n);
	b.clear();
	b.resize(n);
	endPoints.clear();
	endPoints.resize(n);
	result.clear();
	result.resize(n);
	dp.clear();
	dp.resize(n);
}

int lis(){
	rep(i,n)
		dp[i]=1;
	reps(i,1,n){
		rep(j,i){
			if(result[i] >= result[j]){
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	int ans = INT_MIN;

	rep(i,n)
		ans = max(ans,dp[i]);

	return ans;
}

int lis2(){
	rep(i,n)
		dp[i]=1;
	reps(i,1,n){
		rep(j,i){
			if(result[i] <= result[j]){
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	int ans = INT_MIN;

	rep(i,n)
		ans = max(ans,dp[i]);

	return ans;
}

int main(){
	csl;
	cin>>t;
	while(t--){
		cin>>n;
		reset();

		rep(i,n)
			cin>>a[i];
		rep(i,n)
			cin>>b[i];
		rep(i,n)
			endPoints[i]=make_pair(a[i],b[i]);

		sort(all(endPoints),compare2);

		sort(all(endPoints),compare1);

		rep(i,n)
			result[i] = endPoints[i].second;

		cout<<max(lis(),lis2())<<endl;

	}
	return 0;
}