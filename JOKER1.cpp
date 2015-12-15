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
#define SIZE 10009
#define INF 10000000000.0

int t,n;
vi arr;

void solve(){
	ll ans = arr[0];
	reps(i,1,n)
		ans = ((ans - 1)*(arr[i]))%MOD;
	cout<<ans<<endl;
}

int main(){
	boost;
	cin>>t;
	while(t--){
		cin>>n;
		arr.resize(n);
		rep(i,n)
			cin>>arr[i];
		sort(all(arr));
		reverse(all(arr));
		solve();
	}
	cout<<"KILL BATMAN"<<endl;
	return 0;
}