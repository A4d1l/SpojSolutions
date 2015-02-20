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

int main(){
	int N;
	while(1){
		scanf("%d",&N);
		if(N==0)
			break;
		printf("%d\n",(N*(N+1)*(2*N+1))/6 );
	}
	return 0;
}