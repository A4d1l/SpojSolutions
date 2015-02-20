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

vll A;
ll Sum,N;
int T;
int main(){
	csl;
	cin>>T;
	while(T--){
		cin>>N;
		A.resize(N);
		Sum=0;
		rep(i,N){
			cin>>A[i];
			Sum=(Sum+A[i]%N)%N;
		}
		Sum=(Sum+N)%N;
		

		if(Sum==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}