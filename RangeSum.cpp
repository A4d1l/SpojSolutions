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

int N,Q,tmp,a,b,n;
vii A,t;

void init(int nn){
	n=n;
	t.resize(n,0);
}
void inc (int i, int delta){
	for (; i <n; i = (i | (i + 1)))
		t [i]+= delta;
}

ll Sum(int r){
	ll result = 0;
	for (;r >= 0; r = (r & (r + 1)) - 1)
		result+= t [r];
	return result;
}

ll Sum (int l, int r){
	return Sum (r) - Sum (l-1);
}

void init (){
	printf("sd\n");
	init (A.size());
	for (int i = 0; i<A.size();i++)
		inc(i,A[i]);
	printf("incsdf\n");
}

int main(){
	csl;
	cin>>N;
	A.resize(N);
	rep(i,N)
		cin>>A[i];
	init();
	cin>>Q;
	while(Q--){
		printf("weeeee\n");
		cin>>tmp;
		if(tmp==2){
			cin>>a;
			A.insert(A.begin(),a);
			init();
		}
		else{
			printf("else %d\n",tmp);
			cin>>a>>b;
			cout<<a<<b;
			cout<<Sum(a,b)<<endl;
		}
	}
	return 0;
}