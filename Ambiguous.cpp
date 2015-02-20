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
#define INF 60

int N;
vii A(1000001);
bool flag;
int main(){
	cin>>N;
	while(N){
		flag=false;
		reps(i,1,N+1)
			cin>>A[i];
		reps(i,1,N+1)
			if(A[A[i]]!=i){
				cout<<"not ambiguous"<<endl;
				flag=true;
				break;
			}
		if(!flag)
			cout<<"ambiguous"<<endl;
		cin>>N;
	}
	return 0;
}