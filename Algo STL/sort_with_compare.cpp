#include<iostream>
using namespace std;

bool cmp(int a, int b){
	return a<b;
}

void bubble_sort(int n, int arr[], bool (&cmp)(int a, int b) ){

	for(int itr = 0;itr<=n-1;itr++){

		for(int j=0;j<=n-2;j++){
			if( cmp(arr[j],arr[j+1]) ){
				swap(arr[j],arr[j+1]);
			}
		}
	}

}


int main(){
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	bubble_sort( n, arr, cmp );

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

}


/*
5
5 4 3 2 1




*/