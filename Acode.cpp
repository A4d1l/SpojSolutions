#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define s(n) cin >> n
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define INF 60

int len;
string str;
vector<ull> DP(5010);

void Calc(){
	len=str.size();
	DP.resize(len);
	DP[0]=1;
	reps(i,1,len){
		if(str[i]=='0'){
			if(str[i-1]<='2' && str[i-1]!='0')
				DP[i]=DP[i-1]+1;
			else
				DP[i]=DP[i-1];
		}
		else if(str[i]<='6' && (str[i-1]<='2' && str[i-1]>='1'))
			DP[i]=DP[i-1]+2;
		else
			DP[i]=DP[i-1]+1;
	}
	rep(i,len)
		cout<<DP[i]<<" ";
	cout<<endl;
	cout<<DP[len-1]<<endl;
}
int main(){
	cin>>str;
	while(str!="0"){
		Calc();
		cin>>str;
	}
	return 0;
}