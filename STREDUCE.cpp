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

string str;
map<string,string> dp;
string rec(string inp){
	if(dp[inp] != "")
		return dp[inp];
	int len = inp.size();
	if(len <= 2)
		return dp[inp] = inp;
	string ans = inp;
	for(int i = 1;i<(len-1);++i){
		if(inp[i-1] == inp[i+1]){
			string tmp = rec(inp.substr(0,i-1) + inp [i] + inp.substr(i+2,len - i));
			ans = tmp.size() < ans.size() ? tmp : ans;
		}
	}
	return dp[inp] = ans;
}

void solve(){
	string ret = rec(str);
	cout<<ret.size()<<endl;
}

int main(int argc, char const *argv[]){
	boost;
	cin>>str;
	solve();	
	return 0;
}