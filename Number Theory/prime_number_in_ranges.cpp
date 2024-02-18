#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> prime_sieve(vector<ll> sieve){
	for(ll i=3;i<=sieve.size();i+=2){
		sieve[i] = 1;
	}

	for(ll i=3;i<=sieve.size();i+=2){
		if(sieve[i] == 1){
			for(ll j=i*i;j<=sieve.size();j+=i){
				sieve[j] = 0;
			}
		}
	}
	sieve[0] = sieve[1] = 0;
	sieve[2] = 1;
	return sieve;
}



int main(){

	vector<ll> sieve(1000005, 0);

	vector<ll> ans = prime_sieve(sieve);

	vector<ll> comm_sum(1000005,0);

	for(ll i=0;i<=ans.size();i++){
		comm_sum[i] = ans[i]+comm_sum[i-1];
	}
	for(ll i=0;i<=200;i++){
		cout<<ans[i]<<" ";
	}

	ll q,a,b;
	cin>>q;
	while(q--){
		cin>>a>>b;
		cout<<comm_sum[b]-comm_sum[a-1]<<endl;
	}
	cout<<endl;
	return 0;
}