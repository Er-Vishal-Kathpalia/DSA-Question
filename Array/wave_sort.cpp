#include<bits/stdc++.h>
using namespace std;

// void wave_sort(int arr[], int n){

// 	for(int i=1;i<n;i+=2){
// 		if(i-2>0 && arr[i-2] > arr[i-1]){
// 			swap(arr[i-2],arr[i-1]);
// 		}
// 		if(arr[i-1]<=arr[i]){
// 			swap(arr[i-1],arr[i]);
// 		}
// 	}

// }

void wave_sort(int arr[], int n){

	for(int i=0;i<n;i+=2){
		//Prev Element
		if(i!=0 && arr[i]<arr[i-1]){
			swap(arr[i],arr[i-1]);
		}

		//Next Element
		if(i!= n-1 && arr[i] < arr[i+1]){
			swap(arr[i],arr[i+1]);
		}
	}

}

int main(){

	int arr[] = {1,3,4,2,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);

	wave_sort(arr, n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}

/*
0 1 2 3 4 5 6 7
1 5 8 3 9 2 0 1
5 1 8 3 9 0 2 1
5 1 8 3 9 0 2 1
H L H L H L H L

H L..
0 1 2 3 4 5 6 7
1 5 3 8 9 2 0 1
5 1 3 8 9 2 0 1

5 3 8 1 9 2 0 1
5 3 8 1 9 0 2 1
H L H L H L H L
*/