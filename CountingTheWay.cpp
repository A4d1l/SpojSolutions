#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < pii > vpi; 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 100000

int n;
ll dp[205][205];

char opening[] = "({[";
char closing[] = ")}]";
char brackets[206];

ll mod(ll x){
	if(x > MOD)	
		return MOD + x%MOD;
	return x;
}
ll rec(int start, int end){
	if(start>end)
		return 1;
	if(dp[start][end] != -1)
		return dp[start][end];
	ll ret = 0;

	for(int mid = start + 1; mid<=end; mid+=2){
		for(int br_no = 0; br_no < 3; ++br_no){
			if(brackets[start] == '?' || brackets[start] == opening[br_no]){
				if(brackets[mid] == '?' || brackets[mid] == closing[br_no]){
					ret = mod(ret + rec(start+1,mid-1)*rec(mid+1,end));
				}
			}
		}
	}

	return dp[start][end] = ret;
}

int main(){
	scanf("%d",&n);
	scanf("%s",brackets);
	memset(dp,-1,sizeof(dp));
	ll ret = rec(0,n-1);
	if(ret < MOD) 
		printf("%lld\n",ret);
	else{
		printf("%05lld\n",ret-MOD );
	}
	return 0;
}