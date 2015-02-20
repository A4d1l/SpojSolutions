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
#define SIZE 3200
int Primes[SIZE];
int len;
bool isPrime(int N){
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
	ull max=sqrt(5000)
	for(ull i=2;i<=max;++i)
		if(isPrime(i))
			Primes[len++]=i;
}

bool Process(ull N){
	//printf("called len=%d\n",len);
	int i;
	for(i=0;(i<len)&&(Primes[i]<=sqrt(N));++i){
	//	printf("N=%ull and Primes[%llu]=%llu\n",N,i,Primes[i]);
		if(!(N%Primes[i])){

			return false;
		}
	}
	return true;
}

void PrintPrimes(ull N,ull M){
	if(N==1)
		++N;
	for(ull i=N;i<=M;++i){
		if(Process(i))
			printf("%llu\n",i);
	}
}
int main(){
	len=0;
	GeneratePrime();
	//rep(i,0,20)
	//	printf("%llu\n",Primes[i]);
	int T;
	ull N,M;
	
	scanf("%d",&T);
	while(T--){
		scanf("%llu %llu",&N,&M);
		PrintPrimes(N,M);
		printf("\n");
	}
	return 0;
}