#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <sstream>
#include <vector>
using namespace std;
#define rep(i,a,N) for(int i=a;i<N;++i)

string Fact[101];

string RemoveZero(string str){
	int i=0;
	while(str.at(i)=='0')
		++i;
	return str.substr(i,str.size()-1);
}
string ToString(int x){
	stringstream ss;
	ss << x;
	string str = ss.str();
	return str;
}
string Reverse(string str){
	int start=0,end=str.size()-1;
	while(start<end){
		swap(str[start],str[end]);
		++start;
		--end;
	}
	return str;
}
string Mult(int x,string str){
	string result="";
	int tmp=0,n;
	for(int i=str.size()-1;i>=0;--i){
	//	printf("in for\n");
		n=x*(str.at(i)-48)+tmp;
		result+=ToString(n%10);
		tmp=n/10;
	}
	//printf("after for\n");

	result+=Reverse(ToString(tmp));
	return Reverse(result);
}

void Init(){
	Fact[0]="1";
	Fact[1]="1";
	Fact[2]="2";
	rep(i,3,101)
		Fact[i]=Mult(i,Fact[i-1]);
	rep(i,1,101)
		Fact[i]=RemoveZero(Fact[i]);
}
/*
unsigned long long DP[101];
void Init(){
	DP[0]=1;
	DP[1]=1;
	rep(i,2,101)
		DP[i]=DP[i-1]*i;
}
*/
int main(){
	Init();
	//rep(i,0,101)
	//	cout<<Fact[i]<<endl;
	int T,N;
	
	scanf("%d",&T);
	
	while(T--){
		scanf("%d",&N);
		//cin>>str;
	//	printf("%llu\n",DP[N]);
		cout<<Fact[N]<<endl;
	}
	//*/
	return 0;
}