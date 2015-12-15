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

vi dp;
map<char,int> order;
string str;

bool isInSet(char ch){
	if(ch == '1' || ch == '0' || ch == '8' || ch == '7')
		return true;
	return false;
}
void solve(){
	order['1'] = 1;
	order['8'] = 2;
	order['0'] = 3;
	order['7'] = 4;
	int len = str.size();
	dp.resize(len);
	rep(i,len)
		if(str[i] == '1' || str[i] == '0' || str[i] == '8' || str[i] == '7')
			dp[i] = 1;
	reps(i,1,len){
		rep(j,i){
			if(isInSet(str[i]) && isInSet(str[j])){
				if(order[str[j]] <= order[str[i]])
					dp[i] = max(dp[i],1+dp[j]);
			}
		}
	}
	int ans = 0;
	rep(i,len){
	//	cout<<dp[i]<<" ";
		ans = max(dp[i],ans);
	}
	//cout<<endl;

	cout<<ans<<endl;

}

int main(){
	csl;
	cin>>str;
	solve();
	return 0;
}