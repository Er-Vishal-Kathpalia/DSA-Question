#include<bits/stdc++.h>
using namespace std;

/*
Given N, friends who want to go to a party on bikes. Each guy can go as single, or as a couple. 
Find the Number of ways in which N friends can go to the party.
N=3
Ways = 4
Solution is formula based
*/

int noOfWaysToGoAtParty(int n){

	//base case
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	if(n>0 && n<=2){
		return n;
	}

	int firstWay = noOfWaysToGoAtParty(n-1);
	int secondWay = noOfWaysToGoAtParty(n-2);
	return 1*firstWay+(n-1)*secondWay;
}

int main(){

	int n;
	cin>>n;

	cout<<noOfWaysToGoAtParty(n)<<endl;

	return 0;
}


/*

*/