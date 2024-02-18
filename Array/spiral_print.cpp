#include <iostream>
using namespace std;

void spiral_print(int m, int n, int arr[][1000] ){

	int startRow = 0;
	int startCol = 0;
	int endRow = m-1;
	int endCol = n-1;

	while(startRow<=endRow && startCol<=endCol){
		for(int i=startCol;i<=endCol;i++){
			cout<<arr[startRow][i]<<" ";
		}
		startRow++;
		for(int i=startRow;i<=endRow;i++){
			cout<<arr[i][endCol]<<" "; 
		}
		endCol--;
		if( startCol<=endCol ){
			for(int i=endCol;i>=startCol;i--){
				cout<<arr[endRow][i]<<" ";
			}
			endRow--;
		}
		if(startRow<=endRow){
			for(int i=endRow;i>=startRow;i--){
				cout<<arr[i][startCol]<<" ";
			}
			startCol++;
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
	spiral_print(m, n, arr);
	return 0;
}


/*
4 4 
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16


1 2 3 4, 8 12 16, 15 14 13, 9 5, 6 7, 11, 10 


*/