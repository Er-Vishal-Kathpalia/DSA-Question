#include <bits/stdc++.h>
using namespace std;

void inc(int n){
	//base case
	if(n == 0){
		return;
	}
	inc(n-1);
	cout<<n<<" "; 
}


void dec(int n){
	//base case
	if(n == 0){
		return;
	}

	cout<<n<<" ";
	dec(n-1); 
}


int main(){

	int n;
	cin>>n;

	dec(n);
	cout<<endl;
	inc(n);
	cout<<endl;
	return 0;
}


/*
*/