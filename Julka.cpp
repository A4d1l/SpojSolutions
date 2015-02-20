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

string DivideByTwo(string str){
	string result="";
	int reminder=0,n;
	rep(i,0,str.size()){
		n=ToInt(str.at(i));
		n=10*reminder+n;
		if((n<2) && (i<(str.size()-1))){
			n=n*10+ToInt(str.at(++i));
			if(result!="")
				result+="0";
		}
		result+=ToString(n/2);
		reminder=n%2;
	}
	return result;
}

string AddOne(string str){
	int n;
	string result="";
	n=ToInt(str.at(str.size()-1))+1;
	if(n<10){
		str.at(str.size()-1)=n;
		return str;
	}
	else{
		
	}
}

int main(){
	string str;
	cin>>str;
	cout<<DivideByTwo(str)<<endl;
	return 0;
}