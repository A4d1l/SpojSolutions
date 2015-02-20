#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()

int T,N;
vii A,B;
ll Ans;
int main(){
	csl;
	cin>>T;
	while(T--){
		cin>>N;
		A.resize(N);
		B.resize(N);
		rep(i,N)
			cin>>A[i];
		rep(i,N)
			cin>>B[i];
		sort(all(A));
		sort(all(B));
		Ans=0;
		rep(i,N)
			Ans+=A[i]*B[i];
		cout<<Ans<<endl;
	}
	return 0;
}