#include <bits/stdc++.h>
using namespace std;

long long int reverse(long long int ans){

	long long int n = 0;
	while(ans > 0){
		long long int digit = ans%10;
		n = (n*10)+digit;
		ans=ans/10;
	}
	return n;
}


int main(){

	long long int n;
	cin>>n;
	long long int ans = 0;
	while(n > 0){
		long long int digit = n%10;
		if(digit > 4){
			digit = (9-digit);
		}
		ans = (ans*10)+digit;
		n = n/10;
	}

	cout<<ans<<endl;

	if(ans%10 == 0){
		ans = ans+9;
	}

	cout<<reverse(ans)<<endl;

	return 0;
}