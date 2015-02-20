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
#define rep(i,a,N) for(int i=a;i<N;++i)

string NextPalindrome(string result){
	int start=0,end=result.size()-1;
	string str=result;
	bool incr=false;
	int index1=0,index2;
	while(start<end){
		if(str.at(end)<str.at(start)){
			
		//	if(start<=index1){
			if(!incr){
				index1=start;
				index2=end;
				incr=true;
			}
		}
		str.at(end)=str.at(start);
		++start;
		--end;
	}
	if(!incr){
		if(start>end){//even condition
			while(start>=0 && str.at(start)=='9')
				--start;
			if(start==-1){//all 9's
				rep(i,1,str.size()-1)
					str.at(i)='0';
				str.at(0)='0';
				str.at(str.size()-1)='1';
				str="1"+str;
				//str+="1";
				return str;
			}
			++str.at(start);
			end=str.size()-start-1;
			str.at(end)=str.at(start);
			for(int i=start+1;i<end;++i)
				str.at(i)='0';
		}
		else{//odd condition
			while(start>=0 && str.at(start)=='9')
				--start;
			if(start==-1){//all 9's
				rep(i,1,str.size()-1)
					str.at(i)='0';
				str.at(0)='0';
				str.at(str.size()-1)='1';
				str="1"+str;
				//str+="1";
				return str;
			}
			++str.at(start);//=(char)((int)(str.at(start)-47));//increment the middle one
			end=str.size()-start-1;
			str.at(end)=str.at(start);
			for(int i=start+1;i<end;++i)
				str.at(i)='0';
		}
	}
	else{
		for(int i=index1+1;i<=index2-1;++i)
			str.at(i)='0';
	}
	return str;
}

int main(){
	int T;
	string str;
	scanf("%d",&T);
	while(T--){
		cin>>str;
		cout<<NextPalindrome(str)<<endl;
	}
	return 0;
}