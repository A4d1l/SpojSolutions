#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define s(n) cin >> n
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define wt while(true)
#define all(x) x.begin(),x.end()
#define pb push_back
#define ls(x) ((2*(x)) + 1)
#define rs(x) ((ls(x)) + 1)
#define md(a,b) (((a) + (b))/2)
#define INF (1e9 + 7)


ll DP[2001];
int T,tmp,N;
bool flag;
int main(){
	csl;
	cin>>T;
	while(T--){
		cin>>N;
		memset(DP,0,sizeof(DP));
		rep(i,N){
			cin>>tmp;
			++DP[(tmp+1000)];
		}
		tmp=N/2;
		flag=false;
		rep(i,2001){
			if(DP[i]>tmp){
				cout<<"YES "<<(i-1000)<<endl;
				flag=true;
				break;
			}
		}
		if(!flag)
			cout<<"NO"<<endl;

	}
	return 0;
}