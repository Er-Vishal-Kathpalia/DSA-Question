#include<bits/stdc++.h>
using namespace std;


void bubble_sort_rec2(int arr[], int j, int n){

	//base case
	if(n == 1){
		return;
	}
	if(j==n-1){
		return bubble_sort_rec2(arr,0,n-1);
	}
	if(arr[j]>arr[j+1]){
		swap(arr[j],arr[j+1]);
	}
	bubble_sort_rec2(arr,j+1,n);

}


void bubble_sort_rec(int arr[],int i, int j, int n){

	//base case
	if(i==n){
		return;
	}
	if(j != n){
		if(arr[j-1]>arr[j]){
			swap(arr[j-1],arr[j]);
		}
		bubble_sort_rec(arr,i,j+1,n);
	}
	bubble_sort_rec(arr,i+1,j,n);

}


void bubble_sort(int *arr, int n){

	if(n==1){
		return;
	}

	for(int j=0;j<n-1;j++){
		if(arr[j]>arr[j+1]){
			swap(arr[j],arr[j+1]);
		}
	}

	bubble_sort(arr,n-1);

}

int main(){

	int arr[] = {4,2,3,4,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i=0;
	int j=0;

	//bubble_sort_rec(arr,0,j+1,n);

	bubble_sort_rec2(arr,j+1,n);

	// bubble_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" "; 
	}
	cout<<endl;
	return 0;
}

/*
arr[] = 5 4 3 2 1


*/