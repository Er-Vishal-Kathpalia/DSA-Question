#include <iostream>
using namespace std;

void rotate_image(int m, int n, int arr[][1000] ){

	for(int row=0;row<=m-1;row++){
		int startCol = 0;
		int endCol = n-1;
		while(startCol<=endCol){
			swap( arr[row][startCol], arr[row][endCol] );
			startCol++;
			endCol --;
		}
	}
	for(int row=0;row<=m-1;row++){
		for(int col=0;col<=n-1;col++){
			if(row<col){
				swap(arr[row][col], arr[col][row]);
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
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
	rotate_image(m, n, arr);
	return 0;
}


/*
4 4 
1 2 3 4
5 6 7 8         
9 10 11 12
13 14 15 16

4 8 12 16
3 7 11 15
2 6 10 14
1 5 9  13


*/