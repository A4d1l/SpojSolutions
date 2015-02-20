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

ll N,total;
ll Break(ll x){
	ll sum=0;
	while(x){
		sum+=((x%10)*(x%10));
		x/=10;
	}
	return sum;
}
int main(){
	csl;
	cin>>N;
	total=0;
	while(N!=1){
		N=Break(N);
		++total;
		if((N<9&&N>0) && (N!=7))
			break;
	}
	if(N==1)
		cout<<total<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}