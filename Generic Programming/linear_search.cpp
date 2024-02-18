#include<bits/stdc++.h>
using namespace std;

template<typename T>
int linear_search(T arr[], int n, T key){

	for(int i=0;i<n;i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;

}

int main(){

	float arr[] = {1.2,1.4,1.9,2.3};
	int n = sizeof(arr)/sizeof(arr[0]);
	float key = 1.9;

	cout<<linear_search(arr,n,key)<<endl;
	return 0;
}