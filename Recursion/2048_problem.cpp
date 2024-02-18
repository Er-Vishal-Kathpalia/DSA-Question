#include<bits/stdc++.h>
using namespace std;

char words[][10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};


void printSpellings(int n){
	//base case
	if(n<=0){
		return;
	}

	printSpellings(n/10);
	int digit = n%10;
	cout<<words[digit]<<" ";
}


int main(){

	int n;
	cin>>n;

	printSpellings(n);
	cout<<endl;
	return 0;
}


/*

2048 -> Two Zero Four Eight
2048 = 2048%10 = 8
n = n/10;


*/