#include <bits/stdc++.h>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> prime_sieve(int *p, int n){
	
	p[0] = p[1] = 0;
	p[2] = 1;

	//Mark all odd numbers as prime
	for(int i=3;i<=n;i+=2){
		p[i] = 1;
	}


	//Sieve login to mark non prime numbers as 0.
	//1. Optimisation : Iterate only on the odd numbers
	for(int i=3;i<=n;i+=2){
		if(p[i]){
			//Mark all the multiples of that number as non prime.
			//Optimisation : Take a jump of 2i starting from i*i
			for(int j=i*i;j<=n;j+=2*i){
				p[j] = 0;
			}
		}
	}
	vector<int> primes;
	primes.push_back(2);
	for(int i=3;i<=n;i++){
		if(p[i] == 1){
			primes.push_back(i);
		}
	}

	return primes;
}

//using permutation and combination formula
int countingDivisors(int m, vector<int> &primes){
	
	int ans = 1;

	int i=0;
	int p = primes[0];

	while(p*p<=m){
		if(m%p==0){
		int cnt = 0;		
			while(m%p==0){
				m=m/p;
				cnt++;
			}
			ans = ans*(cnt+1);
		}
		//go to next position
		i++;
		p = primes[i];
	}
	if(m!=1){
		ans = ans*2;
	}
	return ans;
}


int main(){
	int N = 1000005;
	int p[N];
	for(int i=0;i<1000005;i++){
		p[i] = 0;
	}

	vector<int> primes = prime_sieve(p, 10005);

	int t;
	cin>>t;

	while(t--){
		int no;
		cin>>no;
		int divisors = countingDivisors(no, primes);
		cout<<divisors<<endl;
	}

	return 0;
}