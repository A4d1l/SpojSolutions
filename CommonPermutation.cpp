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

int A[26],B[26],tmp,len2,len1;
string str1,str2;
char ch;
int main(){
	csl;
	while(getline(cin,str1)){
		if(getline(cin,str2)){
			memset(A,0,sizeof(A));
			memset(B,0,sizeof(B));
			len1=str1.size();
			len2=str2.size();
			rep(i,len1)
				++A[str1[i]-'a'];
			rep(i,len2)
				++B[str2[i]-'a'];
			rep(i,26){
				tmp=min(A[i],B[i]);
				ch=i+'a';
				rep(j,tmp)
					cout<<ch;
			}

			cout<<endl;
		}
	}
	return 0;
}