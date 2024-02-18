#include<iostream>
using namespace std;


void insertion_sort( int n, int arr[] ){ 
	for(int i=1;i<=n-1;i++){
		int e = arr[i];
		int j = i-1;
		while( j>=0 && arr[j] >= e ){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = e;
	}
}

// void insertion_sort( int n, int arr[] ){ 
// 	for(int i=1;i<=n-1;i++){
// 		int var = arr[i];
// 		int j = i-1;
// 		for(;j>=0;j--){
// 			if(arr[j]>=var){
// 				arr[j+1] = arr[j];
// 			}
// 		}
// 		arr[j+1] = var;
// 	}
// }


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	insertion_sort(n, arr);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<", ";
	}
	return 0;
}



/*
n=5
5 4 1 3 2

4 5 1 3 2





*/