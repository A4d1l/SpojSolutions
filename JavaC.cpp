#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <queue>
#include <iomanip>
#include <string>
#include <math.h>
#include <limits>
#include <map>
#include <float.h>
#include <limits.h>
#include <string.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
//typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> Adj;
typedef map<string, int> msi;

#define rep(i,a,N) for(int i=a;i<N;++i)
#define TRvii(c,it) for(vi::iterator it=(c).begin();it!=(c).end();it++)
#define TR(c, it) for(typeof(c) it=(c).begin();it!=(c).end();++it )
#define mod 1000000007
#define SIZE 100001

bool isCpp(string str){
	int len=str.size();
	rep(i,0,len)
		if(!( (str.at(i)<='z' && str.at(i)>='a') || (str.at(i)=='_')))
			return false;
	return true;
}

bool isJava(string str){
	int len=str.size();
	if(!(str.at(0)<='a' && str.at(0)>='z'))
		return false;
	rep(i,0,len)
		if(!( (str.at(i)<='z' && str.at(i)>='a') || (str.at(i)<='Z' && str.at(i)>='A') ))
			return false;
	return true;
}

string CppToJava(string str){
	string result="";
	int len=str.size();
	rep(i,0,len){
		if(str.at(i)=='_')
			result+=
	}
}