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
#define INF 1000009

ll n,m;
vll arr;

void solve(){
	ll max_so_far = max_ending = 0;
	int start = 0,end = 0;
	while(end < n){
		/*include some until it exceeds M*/
		while(end<n && max_ending <= M){
			max_ending += arr[end];
			++end;
		}
		/* count by excluding the current element*/
		max_so_far = max(max_so_far,max_ending-arr[end]);
		while(max_ending>=M){
			max_ending - =arr[start];
			++start;
		}
		max_ending = 0;
	}
}
int main(){
	csl;
	cin>>n>>m;
	arr.resize(n);
	rep(i,n)
		cin>>arr[i];
	solve();
	return 0;
}