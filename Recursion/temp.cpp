#include<bits/stdc++.h>
using namespace std;


int main(){

	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(int);

	for(int i=1;i<=n;i+=2){
		cout<<arr[i]<<" ";
	}
	return 0;
}