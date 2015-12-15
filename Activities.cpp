#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
typedef vector<string> vs;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define INF 1000009

vpii interval;
vi dp,total;
int n,ans;
bool compare(pii p1,pii p2){
	return p1.second<=p2.second;
}

int binarySerach(int start,int end,int value){
	cout<<"searching in "<<start<<" : "<<end<<" for : "<<value<<endl;
	while(start<=end){
		cout<<"start : "<<start<<" end : "<<end<<endl;
		int mid = (start+end)/2;
		cout<<"mid : "<<mid<<endl;
		if(interval[mid].second < value)
			start = mid + 1;
		else if(interval[mid].second > value)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

void solve(){	
	total[1] = 1;
	dp[1] = 1;
	ans = 1;
	reps(i,2,n+1){
		int lastIndex = binarySerach(1,i-1,interval[i].first);
		cout<<"lastIndex = "<<lastIndex<<endl;
		if(lastIndex == -1){
			total[i] = 1;
			dp[i] = 1;
			ans += 1;
		} else{
			total[i] = total[lastIndex] + 1;
			dp[i] = pow(2,total[i]);
			ans = ans + dp[i] - dp[lastIndex];
		}
		cout<<"ans : "<<ans<<endl;
	}
	int tmp = 0;
	reps(i,1,n+1)
		if(total[i] == 1)
			++tmp;
	cout<<"ans berore "<<ans<<endl;
	//if(tmp>1)
		ans -= tmp;

	cout<<ans<<endl;
}

int main(){
	csl;
	cin>>n;

	interval.resize(n+1);
	total.resize(n+1);
	dp.resize(n+1);

	reps(i,1,n+1){
		cin>>interval[i].first>>interval[i].second;
	}
	sort(all(interval),compare);
	reps(i,1,n+1)
		cout<<interval[i].first<<" : "<<interval[i].second<<endl;
	solve();
	return 0;
}