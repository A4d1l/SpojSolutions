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
//#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 200099
#define INF 100000000000000

ll dp[500][500],dp2[500][500];
vs arr;

ll calc_false(int ,int );
ll calc_true(int ,int );

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while(getline(ss, tok, delimiter))
		internal.push_back(tok);
	
  
  	return internal;
}

string input(){
	string str;
	getline(cin,str);
	return str;
}


ll calc_false(int start,int end){
	if(dp2[start][end] != -1)
		return dp2[start][end];

	if(start == end)
		return dp2[start][end] = (arr[start] ==  "F") ? 1 : 0;
	
	if(start == end - 2){
		if(arr[start + 1] == "and"){
			return dp2[start][end] = ((arr[start] == "F") || (arr[end] == "F")) ? 1 : 0;
		} else if(arr[start + 1] == "or"){
			return dp2[start][end] = ((arr[start] == "F") && (arr[end] == "F")) ? 1 : 0;
		} else if(arr[start + 1] == "xor"){
			return dp2[start][end] = (((arr[start] == "T") && (arr[end] == "T")) || ((arr[start] == "F") && (arr[end] == "F"))) ? 1 : 0;
		}
	}
	ll ans = 0;
	for(int i = start + 1;i < end; i += 2){
		if(arr[i] == "and"){
			ans += (calc_true(start,i - 1) * calc_false(i+1,end));
			ans += (calc_false(start,i - 1) * calc_true(i+1,end));
			ans += (calc_false(start,i - 1) * calc_false(i+1,end));
		}
		else if(arr[i] == "or"){
			ans += (calc_false(start,i - 1) * calc_false(i+1,end));
		} else if(arr[i] == "xor"){
			ans += (calc_true(start,i - 1) * calc_true(i+1,end));
			ans += (calc_false(start,i - 1) * calc_false(i+1,end));
		}
	}
	return dp2[start][end] = ans;
}

ll calc_true(int start,int end){
	if(dp[start][end] != -1)
		return dp[start][end];

	if(start == end)
		return dp[start][end] = (arr[start] ==  "T") ? 1 : 0;
	
	if(start == end - 2){
		if(arr[start + 1] == "and"){
			return dp[start][end] = ((arr[start] == "T") && (arr[end] == "T")) ? 1 : 0;
		} else if(arr[start + 1] == "or"){
			return dp[start][end] = ((arr[start] == "T") || (arr[end] == "T")) ? 1 : 0;
		} else if(arr[start + 1] == "xor"){
			if(arr[start] == "F" && arr[end] == "T")
				return dp[start][end] = 1;
			else if(arr[start] == "T" && arr[end] == "F")
				return dp[start][end] = 1;
			else 
				return dp[start][end] = 0;
		}
	}
	ll ans = 0;
	for(int i = start + 1;i < end; i += 2){
		if(arr[i] == "and")
			ans += (calc_true(start,i - 1) * calc_true(i+1,end));
		else if(arr[i] == "or"){
			ans += calc_true(start,i - 1)*calc_true(i+1,end);
			ans += calc_true(start,i - 1)*calc_false(i+1,end);
			ans += calc_false(start,i - 1)*calc_true(i+1,end);
		} else if(arr[i] == "xor"){
			//ans += calc_false(start,i - 1)*calc_false(i+1,end);
			ans += calc_true(start,i - 1)*calc_false(i+1,end);
			ans += calc_false(start,i - 1)*calc_true(i+1,end);
		}
	}
	return dp[start][end] = ans;
}

void solve(){
	arr.clear();
	arr = split(input(),' ');
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	cout<<calc_true(0,arr.size() - 1)<<endl;
	// rep(i,arr.size())
	// 	cout<<arr[i]<<endl;
}
int main(){
	int t;	
	cin>>t;
	getchar();

	while(t--){
		solve();	
	}

	return 0;
}