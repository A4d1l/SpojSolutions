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

ll DP[5020];
string str;
int ln;
int main(){
	csl;
	
	while(true){
		cin>>str;
		if(str.size()==1 && str[0]=='0')
			break;
		if(str.size()==1){
			cout<<"1"<<endl;
			continue;
		}
		ln=str.size();
		DP[0]=1;
		if(str[1]=='0')
			DP[1]=1;
		else if((str[1]<='6' && str[0]=='2') || str[0]=='1')
			DP[1]=DP[0]+1;
		else
			DP[1]=DP[0];
		reps(i,2,ln){
			if(str[i]=='0'){
				DP[i]=DP[i-2];
				continue;
			}
			else
				DP[i]=DP[i-1];
			if((str[i]<='6' && str[i-1]=='2')||str[i-1]=='1')
				DP[i]=DP[i-1]+DP[i-2];
		}
	//	rep(i,len)
	//		cout<<DP[i]<<" ";
		cout<<DP[ln-1]<<endl;
		//cin>>str;
	}
	return 0;
}