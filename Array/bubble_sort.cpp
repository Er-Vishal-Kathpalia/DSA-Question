#include<iostream>
using namespace std;


void bubble_sort( int n, int arr[] ){ 
	
	for(int itr=1;itr<=n-1;itr++){
		for(int j=0;j<=(n-itr-1);j++){
			if(arr[j] > arr[j+1] ){
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
	
	bubble_sort(n, arr);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<", ";
	}
	return 0;
}



/*
n=5
itr =1
j=0;
loop = n-itr-1
5 - 1 -1 = 3
5 4 3 2 1
4 5 3 2 1
4 3 5 2 1
4 3 2 5 1
4 3 2 1 5


itr=2
4 3 2 1 5
3 4 2 1 5
3 2 4 1 5
3 2 1 4 5

itr=3
3 2 1 4 5
2 3 1 4 5
2 1 3 4 5

itr=4
2 1 3 4 5
1 2 3 4 5

*/