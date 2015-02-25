#include <iostream>
using namespace std;
int t,n,DP[101][101],i,j;
#define f(i,j) for(j=0;j<=i;++j)
main(){cin>>t;while(t--){cin>>n;for(i=0;i<n;++i)f(i,j)cin>>DP[i][j];for(i=n-2;i>=0;--i)f(i,j)DP[i][j]+=max(DP[i+1][j],DP[i+1][j+1]);cout<<DP[0][0]<<'\n';}}