#include <bits/stdc++.h>
using namespace std;

int fibo(int n){
	if(n==0 or n==1){
		return n;
	}

	return fibo(n-1)+fibo(n-2);
}


int main(){

	int n;
	cin>>n;

	cout<<fibo(n)<<endl;
	return 0;
}


/*
0 1 2 3 4 5 6 7  8  9  10 11
0 1 1 2 3 5 8 13 21 34 55 89..... 
*/