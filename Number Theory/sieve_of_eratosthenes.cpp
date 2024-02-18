#include<bits/stdc++.h>
using namespace std;
#define ll long long


//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
//TC - O(N)
bool isPrime(int n){
	if( n==0 || n==1 ){
		return false;
	}
	if( n==2 ){
		return true;
	}
	for(int i=2;i<n;i++){
		cout<<n<<" "<<i<<endl;
		if( n%i == 0 ){
			return false;
		}
	}
	return true;
}

//36
//O(root(n))
bool isPrimeOptimised(int n){
	if( n==0 || n==1 ){
		return false;
	}
	if( n==2 ){
		return true;
	}
	for(int i=2;i*i<n;i++){
		cout<<n<<" "<<i<<endl;
		if( n%i == 0 ){
			return false;
		}
	}
	return true;
}

void prime_sieve(int *p){
	//Odd are only prime..
	for(int i=3;i<=1000000;i+=2){
		p[i] = 1;
	}
	// odd false as non prime
	for(ll i=3;i<100000;i+=2){
		if( p[i] == 1){
			//mark all the multiples of i as non prime
			for(ll j=i*i;j<=100000;j=j+i){
				p[j] = 0;
			}
		}
	}
	p[0] = p[1] = 0;
	p[2] = 1;
}



int main(){
	int n;
	cin>>n;
	int p[1000005] = {0};

	prime_sieve(p);

	for(int i=0;i<=n;i++){
		if(p[i]==1){
			cout<<i<<" ";
		}
	}
	// cout<<isPrime(n)<<endl;
	// cout<<isPrimeOptimised(n)<<endl;
	return 0;
}


/*
0, 1 == Not Prime

2 == Prime

0 -- Prime
1 --  Not Prime

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ...
  1   1   1   1   1    1     1     1     1     1    ....
            0     0       0        0        0        0 ..





*/