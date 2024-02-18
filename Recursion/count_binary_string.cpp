#include<bits/stdc++.h>
using namespace std;

/*
Count Binary Strings
5 Count Binary Strings of Length of N, which have No consecutive ones ?

Solution -- formula based
f(n) = f(n-1)+f(n-2)
*/

int binaryStrings(int n){
	if(n<=0){
		return 1;
	}

	return binaryStrings(n-1)+binaryStrings(n-2);

}


int main(){

	int n;
	cin>>n;

	cout<<binaryStrings(n)<<endl;

	return 0;
}