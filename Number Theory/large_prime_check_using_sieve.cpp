#include<bits/stdc++.h>
#include<bitset>
using namespace std;

const int N = 1000005;
bitset<1000005> b;
vector<int> primes;

//sieve of 10^7
void sieve(){

	b.set(); //set all buts 1,1,1,1,1,..
	b[0] = b[1] = 0;

	//Iterate over all odds
	for(long long int i=2;i<=N;i++){
		if(b[i] == 1){
			primes.push_back(i);
			for(long long int j=i*i;j<=N;j+=i){
				b[j] = 0;
			}
		}
	}
}

bool large_prime_number(long long int no){

	if(no<=N){
		return (b[no]==1)?true:false;
	}

	for(long long int i=0;primes[i]*(long long)primes[i]<=no;i++){
		if( no %primes[i] == 0){
			return false;
		}
	}

	return true;
}



int main(){

	sieve();

	long long int no;
	cin>>no;

	if(large_prime_number(no)){
		cout<<"Yes "<<no<<" is prime"<<endl;
	} else{
		cout<<"No "<<no<<" is not prime"<<endl;
	}

	return 0;
}


/*2147483647*/