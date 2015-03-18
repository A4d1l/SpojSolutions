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

int k,len1,len2;
ll DP[2001][2001];
string str1,str2;
int main(){
	csl;
	cin>>str1>>str2;
	cin>>k;
	len1=str1.size();
	len2=str2.size();
	rep(i,len1+1)
		DP[i][0]=i*k;
	rep(i,len2+1)
		DP[0][i]=i*k;
	//memset(DP,0,sizeof(DP));
	for(int i=1;i<=len1;++i)
		for(int j=1;j<=len2;++j)
			DP[i][j]=min(DP[i-1][j-1]+abs(str1[i-1]-str2[j-1]),min((DP[i-1][j]+k),(DP[i][j-1]+k)));
	cout<<DP[len1][len2]<<endl;
	return 0;
}