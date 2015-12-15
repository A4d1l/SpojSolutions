
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
#define SIZE 1000009
#define INF 10000000000.0

int total;
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  reps(i,1,n-1)
    if(P[i] == maxLen)
      ++total;
  delete[] P;
  
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

int count_size(string s){
  int ret = 0,len = s.size();
  rep(i,len)
    if(s[i] != '#' && s[i] != '$')
      ++ret;
  return ret;
}
int main(){
  boost;
  int t;
  string s;
  cin>>t;
  while(t--){
    total = 0;
    cin>>s;
    int len = count_size(longestPalindrome(s));
    cout<<len<<" "<<total<<endl;
  }
}