#include <iostream>
using namespace std;

// Complexity = O(N^2)
// void matrix_search(int m, int n, int arr[][1000], int key ){
// 	for(int i=0;i<=m-1;i++){
// 		for(int j=0;j<=n-1;j++){
// 			if(arr[i][j] == key){
// 				cout<<"Row: "<<i<<"Col: "<<j<<endl;
// 			}
// 		}
// 	}
// }


// int binary_search(int n, int arr[][1000], int key, int row){
// 	int s = 0;
// 	int e = n-1;
// 	while(s<=e){
// 		int mid = (s+e)/2;
// 		if( key == arr[row][mid] ){
// 			return mid;
// 		} else if( arr[row][mid] > key ){
// 			e = mid - 1;
// 		} else {
// 			s = mid + 1;
// 		}
// 	}
// 	return -1;
// }

// Complexity = O(N* Log(N))
// void matrix_search(int m, int n, int arr[][1000], int key ){
// 	int ansRow = -1;
// 	int ansCol = -1;
// 	for(int row=0;row<=m-1;row++){
// 		int col = binary_search(n, arr, key, row);
// 		if( arr[row][col] == key && col != -1 ){
// 			ansRow = row;
// 			ansCol = col;
// 		}
// 	}
// 	cout<<"("<<ansRow<<", "<<ansCol<<")"<<endl;
// }

// Complexity = O(Log(N)* Log(m))
void matrix_search(int m, int n, int arr[][1000], int key ){
	
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
	int key;
	cin>>key;
	matrix_search(m, n, arr, key);
	return 0;
}


/*
4 4 
1 2 3 4
5 6 7 8         
9 10 11 12
13 14 15 16

11

*/