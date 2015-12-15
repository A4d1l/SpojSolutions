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
string str;
ll dp1[100005][3],dp2[100005][3];

void solve(){
	int len = str.size();
	rep(i,len){
		if(str[i] == 'M'){ // Meat
			dp[i] = 
		} else if(str[i] == 'B'){ // Beaf

		} else { // Fish

		}
	}
}

int main(){
	boost;
	cin>>n;
	cin>>str;
	solve();
	return 0;
}
