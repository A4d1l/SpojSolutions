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
#define mod 1000007

int T,len;
string str;
int DP[6101][6101];

ll Recur(int start,int end){
	if(start>end)
		return 0LL;
	if(DP[start][end])
		return DP[start][end];
	if(str[start]==str[end])
		return DP[start][end]=Recur(start+1,end-1);
	return DP[start][end]=1+min(Recur(start+1,end),Recur(start,end-1));
}
int main(){
	csl;
	cin>>T;
	while(T--){
		cin>>str;
		len=str.size();
		memset(DP,0,sizeof(DP));
		
		/*
		rep(i,len)
			DP[i][i]=0;
		reps(i,1,len){
			if(str[i]==str[0])
				DP[0][i]=DP[0][i-1];
			else
				DP[0][i]=1+DP[1][i];
		}
		rep(i,len-1){
			if(str[i]==str[len-1])
				DP[i][len-1]=DP[1][len-1];
			else
				DP[i][len-1]=1+DP[i][len-2];
		}
		//rep(j,len)
		//	DP[0][j]=0;
		rep(i,len){
			rep(j,len){
				if(str[i]==str[j])
					DP[i][j]=DP[i-1][j-1];
				else
					DP[i][j]=1+min(DP[i-1][j],DP[i][j-1]);
				
			}
		}*/
		cout<<Recur(0,len-1)<<endl;
	}
	return 0;
}