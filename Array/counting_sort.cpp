#include<bits/stdc++.h>
using namespace std;


void counting_sort(int arr[], int n){

	//find the largest element in array, assuming size is not >0
	int largest = -1;
	for(int i=0;i<n;i++){
		largest = max(largest,arr[i]);
	}

	int* freq = new int[largest + 1];
    memset(freq, 0, sizeof(int) * (largest + 1));

	// int freq[largest+1];
	// for(int i=0;i<largest+1;i++){
	// 	freq[i] = 0;
	// }


	//Increase the frequency of freq array
	for(int i=0;i<n;i++){
		freq[arr[i]]++;
	}

	//Copy the Freq to original array
	int j=0;
	for(int i=0;i<largest+1;i++){
		while(freq[i]>0){
			arr[j] = i;
			freq[i]--;
			j++;
		}
	}

	delete[] freq; // Don't forget to free the allocated memory

}



int main(){

	int arr[] = {99,91,1,3,8,97,6,81,72,9,79,63,21,31,91,18,14,19,23,29,34};

	int n = sizeof(arr)/sizeof(arr[0]);

	counting_sort(arr, n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}

/*
arr = 5 5 6 1 1 4

freq = 0 2 0 0 1 2 1



*/




