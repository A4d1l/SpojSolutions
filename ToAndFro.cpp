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

string Decode(int index,int C,string Input){
	string result="";
	int K=index;
	while(K<Input.size()){
		result+=Input.at(K);
		K=2*C-1-index;
		if(K>=Input.size())
			break;
		result+=Input.at(K);
		K=2*C-index;
		C=K;
	}
	return result;
}

int main(){
	int C,R;
	string str,mystring;
	while(1){
		scanf("%d",&C);
		if(!C)
			break;
		cin>>str;
		R=str.size()/C;
		string Result[R];
		rep(i,0,R){
			Result[i]=Decode(i,C,str);
		}
		mystring="";
		rep(i,0,R)
			mystring+=Result[i];
		cout<<mystring<<endl;
	}
	return 0;
}