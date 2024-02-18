#include<bits/stdc++.h>
using namespace std;

//N is the number of ladders and person can jump 1 step, 2 step and 3 step.
//Jump - 1,2,3 == 3ways
//then find the number of ways to reach the nth step in k no of steps person can take.

int reachtop(int n, int k){

	//base case
	if(n == 0){
		return 1;
	}
	if(n < 0){
		return 0;
	}
	int ans = 0;

	for(int i=1;i<=k;i++){
		ans += reachtop(n-i,k);
	}
	return ans;
}


int reachtopIn3Steps(int n){

	//base case
	if(n == 0){
		return 1;
	}
	if(n < 0){
		return 0;
	}
	return reachtopIn3Steps(n-1)+reachtopIn3Steps(n-2)+reachtopIn3Steps(n-3);
}


int main(){

	int n,k;
	cin>>n>>k;

	cout<<reachtopIn3Steps(n)<<endl;

	cout<<reachtop(n,k);
	return 0;
}


/*
*/