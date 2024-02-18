#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int start, int end, int mid, int key){

	if(start>end){
		return -2;
	}

	if(arr[mid] == key){
		return mid;
	} else if( arr[mid]> key){
		return binary_search(arr,start, mid-1, (start+end)/2, key);
	} else{
		return binary_search(arr,mid+1, end, (start+end)/2,key);
	}
	return -1;
}


int main(){

	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	// int arr[] = {2,5,9,11,13,19,21,34};
	// int n = sizeof(arr)/sizeof(arr[0]);

	int start = 0;
	int end = n-1;
	int key;
	cin>>key;

	cout<<binary_search(arr,start,end,(start+end)/2,key)<<endl;
	return 0;
}

/*

arr = 
 0 1 2 3  4  5  6  7
[2 5 9 11 13 19 21 34]
start = 4
end = 4
mid = 4
key = 13






*/

