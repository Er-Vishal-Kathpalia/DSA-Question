#include<bits/stdc++.h>
using namespace std;


int allOccItr(int *arr, int i, int n, int key, int out[], int j){
	//base case
	if(i==n){
		return j;
	}
	if(arr[i] == key){
		out[j] = i;
		return allOccItr(arr,i+1,n,key,out,j+1);
	}
	return allOccItr(arr,i+1,n,key,out,j);

}

void allOcc(int *arr, int i, int n, int key){
	//base case
	if(i==n){
		return;
	}
	if(arr[i] == key){
		cout<<i<<" ";	
	}
	allOcc(arr, i+1, n, key);

}


int lastOcc(int *arr, int n, int key){
	if(n==0){
		return -1;
	}
	int i = lastOcc(arr+1, n-1, key);
	if(i == -1){
		if(arr[0] == key){
			return 0;
		} else{
			return -1;
		}
	}
	return i+1;
}


int firstOcc(int *arr, int n, int key){
	if(n==0){
		return -1;
	}
	if(arr[0] == key){
		return 0;
	}

	int i = firstOcc(arr+1,n-1, key);
	if(i==-1){
		return -1;
	}
	return i+1;
}


int firstOccItr(int *arr, int i, int n, int key){
	//base case
	if(i == n){
		return -1;
	}

	if(arr[i] == key){
		return i;
	}

	return firstOccItr(arr,i+1, n, key);
}

int main(){

	int arr[] = {1,4,8,6,7,8,9,7,12};
	int n = sizeof(arr)/sizeof(arr[0]);

	int key;
	cin>>key;
	cout<<firstOcc(arr,n,key)<<endl;

	cout<<firstOccItr(arr,0,n,key)<<endl;

	cout<<lastOcc(arr,n,key)<<endl;

	allOcc(arr,0,n,key);
	cout<<endl;

	int out[1000];

	int itr = allOccItr(arr,0,n,key,out,0);
	cout<<itr<<endl;
	for(int i=0;i<itr;i++){
		cout<<out[i]<<" ";
	}
	cout<<endl;
	return 0;
}

/*
arr[] = 1 2 3 4 5 4



*/