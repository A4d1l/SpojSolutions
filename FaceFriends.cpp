#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define traverse(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 1000001

int n,tmp;
set<string> friends;
string str;

int main(){
	csl;
	cin>>n;
	rep(i,n){
		cin>>str;
		friends.insert(str);
		cin>>tmp;
		rep(i,tmp){
			cin>>str;
			friends.insert(str);
		}
	}
	cout<<(friends.size()-n)<<endl;
	return 0;
}