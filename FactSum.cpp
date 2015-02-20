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
#define ull unsigned long long
#define SIZE 100000000
vector<int> Primes;
int len;
bool isPrime(ull N){
	//printf("checking prime=%d\n",N );
	if(N<=1)
		return false;
	if(N==2)
		return true;
	if (N%2==0)
		return false;
	for(ull i=3;i<=sqrt(N);i+=2)
		if((N%i)==0)
			return false;
	return true;
}

void GeneratePrime(){
	Primes.push_back(2);
	printf("2\n");
	for(int i=3;i<=10000000000;i+=2)
		if(isPrime(i)){
			Primes.push_back(i);
			printf("%d\n",i);
		}
}


int main(){
	GeneratePrime();
	/*
	int T;
	ull N,M;
	
	scanf("%d",&T);
	while(T--){
		scanf("%llu %llu",&N,&M);
		PrintPrimes(N,M);
		printf("\n");
	}
	*/
	return 0;
}