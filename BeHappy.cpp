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

int T,N,M,DP[21][101],A[21],B[21];
int main(){
	csl;
	cin>>M>>N;
	while(N && M){
		reps(i,1,M+1)
			cin>>A[i]>>B[i];
		memset(DP,0,sizeof(DP));
		reps(i,1,M+1)
			for(int j=0;j<=N;++j)
				for(int k=A[i];k<=B[i] && j-k>=0;k++)
					DP[i][j]=DP[i-1][j-k]+2;
		cout<<DP[M][N]<<endl;

		cin>>M>>N;
	}
	return 0;
}