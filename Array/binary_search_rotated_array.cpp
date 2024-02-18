#include<iostream>
using namespace std;


int find_key(int arr[], int n, int key){
	int s = 0;
	int e = n-1;
	while(s<=e){
		int mid = (s+e)/2;
		if(arr[mid] == key){
			return mid;
		} else if( arr[s]<=arr[mid] ){
			//mid point lie in option 1
			if( arr[s]<=key && arr[mid]>key ){
				e = mid - 1;
			} else {
				s = mid + 1;
			}

		} else if( arr[e]>=arr[mid] ){
			//mid point will lie in option 2
			if( arr[mid]<key && arr[e]>=key ){
				s = mid + 1;
			} else {
				e = mid - 1;
			}
		}
	}
	return -1;
}

/*
7
s	  m     e
1 2 3 4 5 6 7

3
6 7 1 2 3 4 5

3 4 5

3 4 5 6 7 1 2

*/

int main(){
	int n;
	cin>>n;
	int arr[n];
	for( int i=0;i<n;i++ ){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	cout<<find_key(arr, n, key);
	return 0;	
}
