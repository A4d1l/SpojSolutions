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

vii A;
ll Sum,Ans,tmp,N;

int main(){
	while(true){
		cin>>N;
		if(N==-1)
			break;
		A.resize(N);
		rep(i,N)
			cin>>A[i];
		sort(all(A));
		Sum=accumulate(A.begin(),A.end(),0);
		Ans=0;
		if(Sum%N==0){
			tmp=Sum/N;
			rep(i,N)
				Ans+=max(0LL,A[i]-tmp);
		}
		else
			Ans=-1;
		cout<<Ans<<endl;
	}
	return 0;
}