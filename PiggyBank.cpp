#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
typedef vector<string> vs; 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define all(x) x.begin(),x.end()
#define pb push_back
#define ls(x) ((2*(x)) + 1)
#define rs(x) ((ls(x)) + 1)

int T,Price[501],Cost[501],P,W,DP[501][50001],N;

int main(){
	cin>>T;
	while(T--){
		cin>>P>>W;
		cin>>N;
		W-=P;
		if(W==0)
			cout<<"0"<<endl;
		else if(W>0){
			cout<<"in else"<<endl;
			reps(i,1,N+1)
				cin>>Price[i]>>Cost[i];
			reps(i,1,N+1)
				cout<<Price[i]<<" "<<Cost[i]<<endl;

			memset(DP,0,sizeof(DP));
			DP[0][0]=0;
			printf("set\n");
			reps(i,1,N+1)
				reps(j,0,W+1)
					DP[i][j]=j-Cost[i]>=0? max(DP[i-1][j],DP[i-1][j-Cost[i]]+Price[i]) :DP[i-1][j];
			reps(i,1,N+1)
			cout<<DP[i][W]<<endl;

		}
		else
			cout<<"This is impossible."<<endl;
	}
	return 0;
}