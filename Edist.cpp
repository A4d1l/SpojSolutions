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
#define INSERT 1
#define DELETE 1
#define REPLACE 1

int T,DP[2001][2001];
string s1,s2;

int Solve(){
	int len1=s1.size(),len2=s2.size();
	rep(i,len1+1)
		DP[i][0]=i*INSERT;
	rep(i,len2+1)
		DP[0][i]=i*INSERT;
	reps(i,1,len1+1)
		reps(j,1,len2+1)
			DP[i][j]=s1[i-1]!=s2[j-1]?min(INSERT+DP[i-1][j],min(DELETE+DP[i][j-1],REPLACE+DP[i-1][j-1])):DP[i-1][j-1];
	return DP[len1][len2];
}

int main(){
	csl;
	cin>>T;
	while(T--){
		cin>>s1;
		cin>>s2;
		cout<<Solve()<<endl;
	}
	return 0;
}