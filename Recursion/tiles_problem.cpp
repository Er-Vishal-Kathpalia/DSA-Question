#include<bits/stdc++.h>
using namespace std;
//Given a wall of size 4*n and tiles of size (4,1) or (1,4)/
//In how many ways you can build the wall?

int placeTiles(int n){

	//base case
	if(n<=3){
		return 1;
	}

	return placeTiles(n-1)+placeTiles(n-3);

}



int main(){

	int n;
	cin>>n;

	cout<<placeTiles(n)<<endl;
	return 0;
}


/*
*/