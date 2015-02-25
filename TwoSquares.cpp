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
ll N;
int T;

bool isSquare(ll X){
	ll tmp=sqrt(X);
	tmp=tmp*tmp;
	if(tmp==X)
		return true;
	return false;
}
bool Check(ll N){
	if(N==1||N==0||N==2)
		return true;
	ll len=sqrt(N);
	for(ll i=1;i<=len;++i){
		ll tmp=i*i;
		if(isSquare(N-tmp))
			return true;
	}
	return false;
}
int main(){
	csl;
	cin>>T;
	while(T--){
		cin>>N;
		if(Check(N))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}