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

int N,M,tmp,total,tmp2,len;
map<int, bool> mymap;
bool A[100001];
int main(){
	csl;
	cin>>N;
	memset(A,false,sizeof(A));
	while(N--){
		cin>>tmp;
		mymap[tmp]=true;
		cin>>tmp;
		while(tmp--){
			cin>>tmp2;
			A[tmp2]=true;
		}
	}
	total=0;
	rep(i,100001){
		if(A[i] && !mymap[i])
			++total;
	}
	
	cout<<total<<endl;
	return 0;
}