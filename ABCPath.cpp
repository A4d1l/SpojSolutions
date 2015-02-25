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

int H,W;
int DP[51][51];
char Mat[51][51];
int main(){
	csl;
	cin>>H>>W;
	rep(i,H)
		rep(j,W)
			cin>>Mat[i][j];
	reps(i,1,H)
		if((Mat[i][0]==(Mat[i-1][0]+1)) && DP[])
	rep(i,H){
		rep(j,W){
			if(Mat[i][j]==)
		}
	}
	return 0;

}