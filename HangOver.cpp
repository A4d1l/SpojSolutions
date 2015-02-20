#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vii;
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()

float DP[501],N;

void Init(){
	DP[1]=0.5f;
	reps(i,2,501)
		DP[i]=DP[i-1]+(float)1/(i+1);
}

int T;
int BinarySearch(int start,int end,float key){
	if(start==end){
		if(DP[start]<key)
			return start+1;
		return start;
	}
	int mid=(start+end)/2;
	if(DP[mid]==key)
		return mid;
	if(DP[mid]>key)
		return BinarySearch(start,mid,key);
	return BinarySearch(mid+1,end,key);
}

int main(){
	csl;
	Init();
	while(true){
		cin>>N;
		if(N==0.0)
			break;
		if(N<=0.5)
			cout<<"1"<<" card(s)"<<endl;
		else
			cout<<BinarySearch(0,500,N)<<" card(s)"<<endl;
	}
	return 0;
}