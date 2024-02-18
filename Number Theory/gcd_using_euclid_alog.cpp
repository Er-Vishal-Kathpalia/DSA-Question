#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	return b==0?a:gcd(b,a%b);
}

int main(){

	int a,b;
	cin>>a>>b;

	int greatest_common_divisor = gcd(a,b);
	int least_common_multiple = (a*b)/greatest_common_divisor;
	cout<<"GCD "<<greatest_common_divisor<<endl;
	cout<<"LCM "<<least_common_multiple<<endl;
	return 0;
}