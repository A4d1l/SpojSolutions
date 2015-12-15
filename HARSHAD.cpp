#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector < long long > vll;

typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vpii > vvpii;
typedef vector<vpll > vvpll;
typedef vector<string> vs;

#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define traverse(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 1000999
#define INF 100000000000000

bool devlali[SIZE],isprime[SIZE];
ll cumulate[SIZE];

int calc(int x){
	int total = x;
	while(x){
		total += x%10;
		x /= 10;
	}
	return total;
}
void pre_processing(){
	memset(devlali,true,sizeof(devlali));
	memset(isprime,true,sizeof(isprime));
	devlali[0] = isprime[0] = false;
	isprime[1] = false;
	reps(i,1,SIZE){
		int tmp = calc(i);
		if(tmp < SIZE)
			devlali[tmp] = false;
	}
	
	int len = sqrt(SIZE);
	reps(i,2,len+1)
		if(isprime[i])
			for(int j = i;j*i < SIZE;++j)
				isprime[i*j] = false;

	// rep(i,SIZE)
	// 	if(devlali[i] && isprime[i])
	// 		cout<<i<<endl;	
	cumulate[0] = cumulate[1] = 0;
	reps(i,2,SIZE)
		cumulate[i] = cumulate[i-1] + (isprime[i] && devlali[i]);

}
int main(){
	boost;
	pre_processing();
	int q,a,b;
	cin>>q;
	while(q--){
		cin>>a>>b;
		if(a > 0)
			--a;
		cout<<(cumulate[b] - cumulate[a])<<endl;
	}
	return 0;
}