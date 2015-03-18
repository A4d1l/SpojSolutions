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
#define mod 1000000007

ll DP[2001][2001];//size,price
int S,N,Price[2001],Value[2001];
int main(){
	csl;
	cin>>S>>N;
	rep(i,N)
		cin>>Price[i]>>Value[i];
	rep(i,N+1){
		DP[0][i]=0;
	}
	rep(i,S+1)
		DP[0][i]=0;
	for(int i=1;i<=N;++i){
		for(int j=0;j<=S;++j)
			if((j-Price[i-1])>=0)
				DP[i][j]=max(DP[i-1][j],DP[i-1][j-Price[i-1]]+Value[i-1]);
			else 
				DP[i][j]=DP[i-1][j];
	}
	cout<<DP[N][S]<<endl;


	return 0;
}