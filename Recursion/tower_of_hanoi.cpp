#include<bits/stdc++.h>
using namespace std;

void move(int n, char src, char helper, char dest){

	//base case
	if(n==0){
		return;
	}

	//recursive case
	move(n-1,src,dest,helper);
	cout<<"Shift "<<n<<" from "<<src<<" to "<<dest<<endl;
	move(n-1,helper,src,dest);
	return;
}


int main(){

	int n;
	cin>>n;

	move(n,'A','B','C');

	return 0;
}