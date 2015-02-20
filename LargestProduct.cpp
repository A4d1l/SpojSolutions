#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <sstream>
#include <vector>
using namespace std;
#define rep(i,a,N) for(int i=a;i<N;++i)
#define ll long long
#define ull unsigned long long

string ToString(int N){
	//cout<<"N="<<N<<endl;
	stringstream ss;
	ss<<N;
	//cout<<"returning="<<ss.str()<<endl;
	return ss.str();
}

int ToInt(char ch){
	return ch-'0';
}


ull LargestProduct(string str,int N){
	ull Max,P=1;
	rep(i,1,N+1)
		P*=ToInt(str.at(i));
	Max=P;
	rep(i,N+1,str.size()){
		P=(P*ToInt(str.at(i))) /ToInt(str.at(i-N+1));
		Max=max(Max,P);
	}
	return Max;
}

int main(){
	string str;
	ull T=95,Max=0,a=13;
	rep(i,0,T){
		cin>>str;
		if(str.size()>a){
			printf("checking for %d\n",i);
			Max=max(Max,LargestProduct(str,a));
		}
	}
	
	printf("%d\n",Max);
	return 0;
}