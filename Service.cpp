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

int t,n,l;
vvi cost;
vi service;

/* calculate the minimum cost for service_no done by man
	man can have value 1,2,3
*/
int recur(int service_no,int man,int locations[]){
	if(service_no>n)
		return 0;
	/*store current location of the man. it should be restored later*/
	int current_location = locations[man];
	/*get the location for the next request*/
	int final_location = service[service_no];
	/*calculate total cost for travelling from current location to destination location*/
	int total_cost = cost[current_location][final_location];

	/* update the location of the man */
	locations[man] = final_location;
	int ret = total_cost + min(recur(service_no+1,1,locations),min( recur(service_no+1,2,locations),recur(service_no+1,3,locations) ) );
	/*restore the location of the man*/
	locations[man] = current_location;
	return ret;

}

void solve(){
	int locations[4];
	reps(i,1,4)
		locations[i] = i;
	cout<<(min(recur(1,1,locations),min(recur(1,2,locations),recur(1,3,locations))))<<endl;
}
int main(){
	csl;
	cin>>t;
	while(t--){
		cin>>l>>n;

		service.resize(n+1);
		cost.resize(l+1);
		
		reps(i,1,l+1)
			cost[i].resize(l+1);

		reps(i,1,l+1)
			reps(j,1,l+1)
				cin>>cost[i][j];

		reps(i,1,n+1)
			cin>>service[i];

		solve();
		
	}
	return 0;
}