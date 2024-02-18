#include<iostream>
using namespace std;


void selecton_sort( int n, int arr[] ){ 
	for(int i=0;i<n-2;i++){
		int min_idx = i;
		for(int j=i+1;j<n;j++ ){
			if( arr[min_idx] > arr[j] ){
				min_idx = j;
			}
		}
		swap(arr[i], arr[min_idx]);
	}
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	selecton_sort(n, arr);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<", ";
	}
	return 0;
}



/*
n=5
i = 0 -> 5 4 1 3 2
arr[min_idx] = 1;
i = 1 -> 1 4 5 3 2
arr[min_idx] = 2;
i = 2 -> 1 2 5 3 4
arr[min_idx] = 3;
i = 3 -> 1 2 3 5 4
arr[min_idx] = 4;
i = 4 -> 1 2 3 4 5

*/