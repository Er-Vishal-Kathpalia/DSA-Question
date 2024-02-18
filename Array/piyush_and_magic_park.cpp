#include <iostream>
using namespace std;


void magic_park(int m, int n, char arr[][1000], int s, int k){
	bool success = true;

	for(int row=0;row<=m-1;row++){
		for(int col=0;col<=n-1;col++){
			char ch = arr[row][col];
			if( s < k ){
				success = false;
				break;
			}
			if( ch == '.' ){
				s = s-2;
			} else if ( ch == '*' ){
				s = s+5;
			} else {
				break;
			}
			if(col != n-1){
				s = s - 1;
			}
		}
	}
	if(success){
		cout<<"Yes"<<endl;
		cout<<s<<endl;
	} else{
		cout<<"No"<<endl;
	}

}


int main(){

	int m,n,k,s;
	cin>>m>>n>>k>>s;
	
	char arr[1000][1000];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	magic_park(m, n, arr, s, k);
	
	return 0;
}


/*
4 4 5 20
. . * .
. # . .
* * . .
. # * *

*/