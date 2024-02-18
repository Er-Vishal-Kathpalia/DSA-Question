#include<bits/stdc++.h>
using namespace std;

int fact(int n){

	//base case
	if( n==0 ){
		return 1;
	}
	return n*fact(n-1);
}

// int small_fact = fact(n-1);
// return n*small_fact;

int main(){

	int n;
	cin>>n;


	cout<<fact(n)<<endl;
	return 0;cd
}