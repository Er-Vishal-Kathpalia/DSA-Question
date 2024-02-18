#include<bits/stdc++.h>
using namespace std;


void swap_col(int m,int n, int arr[][1000]){

	for(int col=0;col<n;col++){
		int start=0;
		int end = m-1;
		while(start<=end){
			swap(arr[start][col],arr[end][col]);
			start++;
			end--;
		}
	}
}

void swap_row(int m,int n, int arr[][1000]){

	for(int row=0;row<m;row++){
		int start=0;
		int end = n-1;
		while(start<=end){
			swap(arr[row][start],arr[row][end]);
			start++;
			end--;
		}
	}
}

void swap_matrix(int m,int n,int arr[][1000]){

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i<j){
				swap(arr[i][j],arr[j][i]);
			}
		}
	}

}


int main(){

	int m,n;
	cin>>m>>n;
	int arr[1000][1000];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	swap_col(m,n,arr);
	swap_row(m,n,arr);
	swap_matrix(m,n,arr);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}




/*

4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16


13 14 15 16
9 10 11 12
5 6 7 8
1 2 3 4


16 15 14 13
12 11 10 9
8 7 6 5 
4 3 2 1


16 12 8 4
15 11 7 3
14 10 6 2
13 9 5 1



4 3 2 1
8 7 6 5
12 11 10 9
16 15 14 13


16 12 8 4
15 11 7 3
14 10 6 2
13 9 5 1







*/