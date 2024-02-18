#include<bits/stdc++.h>
using namespace std;


void dnf_sort(int a[], int n){

	int lo = 0;
	int hi = n-1;
	int mid = 0;

	while(mid<=hi){

		if(a[mid] == 0){
			swap(a[lo],a[mid]);
			mid++;
			lo++;
		} else if(a[mid] == 1){
			mid++;
		} else if(a[mid] == 2){
			swap(a[mid],a[hi]);
			hi--;
		}
	}

}


int main(){

	int arr[] = {2,1,0,2,0,1,0,0,2,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);

	dnf_sort(arr, n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}

/*

*/