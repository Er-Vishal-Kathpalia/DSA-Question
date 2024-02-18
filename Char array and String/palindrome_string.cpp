#include<bits/stdc++.h>
using namespace std;


bool palindrome_string(char a[]){
	int start=0;
	int end=strlen(a)-1;
	while(start<=end){
		if(a[start] != a[end]){
			return false;
		}
		start++;
		end--;
	}
	return true;
}

int main(){

	char a[1000];
	cin>>a;
	cout<<palindrome_string( a )<<endl;
	return 0;
}