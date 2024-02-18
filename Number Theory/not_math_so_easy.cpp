#include<bits/stdc++.h>
#define ll long long  
using namespace std;

int main(){
	ll t;
	cin>>t;
	ll primes[] = {2,3,5,7,11,13,17,19};


	while(t--){
		ll n;
		cin>>n;
		ll ans=0;

		ll subsets = (1<<8)-1;

		for(ll i=1;i<=subsets;i++){
			ll denom = 1ll;
			ll setBits = __builtin_popcount(i);
		
			for(int j=0;j<=7;j++){
				if(i&(1<<j)){
					denom = denom*primes[j];
				}
			}

			if(setBits&1){
				//odd
				ans += n/denom;
			} else{
				//even
				ans -= n/denom;
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
Input:
5
5
10
12
15
18


Output:
4
9
11
14
17
*/
