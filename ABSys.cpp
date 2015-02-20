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

int T;
string s1,s2,s3;
char c1,c2;
int main(){
	csl;
	cin>>T;
	while(T--){
	
		cin>>s1>>c1>>s2>>c2>>s3;

		std::string::size_type pos = s1.find("machula");
		if (pos != std::string::npos){
			cout<<(atoi(s3.c_str())-atoi(s2.c_str()))<<" + "<<s2<<" = "<<s3<<endl;
		}
		else{
			std::string::size_type pos = s2.find("machula");
			if (pos != std::string::npos)
				cout<<s1<<" + "<<(atoi(s3.c_str())-atoi(s1.c_str()))<<" = "<<s3<<endl;
			else
				cout<<s1<<" + "<<s2<<" = "<<(atoi(s2.c_str())+atoi(s1.c_str()))<<endl;
		}
	}
	return 0;
}