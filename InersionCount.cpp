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

int n,t;
vi arr;
vi tree;
int get_sum(int idx){
	int ret = 0;
	while(idx){
		ret += tree[idx];
		idx -= (idx & (-idx));
	}
	return ret;
}

void update(int idx,int val){
	while(idx <= n){
		tree[idx] += val;
		idx += (idx & (-idx));
	}
}
void solve(){
	tree.clear();
	tree.resize(n+1,0);

	int ans = 0;
	for(int i = n;i >= 1; --i){
		ans += get_sum(arr[i] - 1);
		update(arr[i],1);
	}
	cout<<ans<<endl;
}

int main(){
	boost;
	vi a,b;
	cin>>t;
	while(t--){
		cin>>n;
		a.clear();
		a.resize(n);
		b.clear();
		b.resize(n);
		arr.clear();
		arr.resize(n+1);
		rep(i,n){
			cin>>a[i];
			b[i] = a[i];
		}
		sort(all(b));
		rep(i,n){
			int rank = (lower_bound(b.begin(),b.end(),a[i]) - b.begin()) + 1;
			arr[rank] = a[i]; 
		}
		reps(i,1,n+1)
			cout<<arr[i]<<" "<<endl;
		solve();

	}
	return 0;
}