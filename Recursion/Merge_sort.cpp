#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e){

	int mid = (s+e)/2;
	int i = s;
	int j = mid+1;
	int k = s;

	int temp[1000000];
	while(i<=mid && j<=e ){
		if( arr[i]<=arr[j] ){
			temp[k++] = arr[i++];
		} else{
			temp[k++] = arr[j++];
		}
	}

	//rest of the arrays
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}

	for(int z=s;z<=e;z++){
		arr[z] = temp[z];
	}
	return;
}


//Divide and conquer
void merge_sort(int *arr, int s, int e){

	//base case
	if(s>=e){
		return;
	}

	int mid = (s+e)/2;
	
	merge_sort(arr,0, mid);
	merge_sort(arr, mid+1, e);

	//Merge
	merge(arr, s, e);
}


int main(){

	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	merge_sort(arr, 0, n-1);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}