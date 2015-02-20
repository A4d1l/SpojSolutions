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

int Common(int a,int b,int c,int d){
	if(a==c || a==d)
		return a;
	if(b==c|| b==d)
		return b;
	return -1;
}
int main(){
	int T,X,Y,a,b,c,d;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&X,&Y);
		if(X%2){
			a=2*X-1;
			b=2*X-3;
		}
		else{
			a=2*X;
			b=2*X-2;
		}
		if(Y%2){
			c=2*Y-1;
			d=2*Y+1;
		}
		else{
			c=2*Y;
			d=2*Y+2;
		}
		if(Common(a,b,c,d)!=-1)
			printf("%d\n",Common(a,b,c,d));
		else
			printf("No Number\n");
	}
	return 0;
}