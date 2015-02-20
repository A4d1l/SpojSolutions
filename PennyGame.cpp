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
int T,tmp,TTT,TTH,THT,THH,HTT,HTH,HHT,HHH;
string str;
void COunt(int x){
	if(str[x]=='T'){
		if(str[x+1]=='T'){
			if(str[x+2]=='T'){//TTT
				++TTT;
			}
			else{//TTH
				++TTH;
			}
		}
		else{//TH
			if(str[x+2]=='T'){//THT
				++THT;
			}
			else{//THH
				++THH;
			}
		}
	}
	else{//H
		if(str[x+1]=='T'){
			if(str[x+2]=='T'){//HTT
				++HTT;
			}
			else{//HTH
				++HTH;
			}
		}
		else{//H
			if(str[x+2]=='T'){//HHT
				++HHT;
			}
			else{//HHH
				++HHH;
			}
		}
	}
}
int main(){
	csl;
	cin>>T;
	while(T--){
		cin>>tmp;
		cin>>str;
		TTT=TTH=THT=THH=HTT=HTH=HHT=HHH=0;
		rep(i,str.size()-2){
			COunt(i);
		}
		cout<<tmp<<" "<<TTT<<" "<<TTH<<" "<<THT<<" "<<THH<<" "<<HTT<<" "<<HTH<<" "<<HHT<<" "<<HHH<<" "<<endl;
	}
	return 0;
}