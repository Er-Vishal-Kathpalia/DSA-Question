#include <bits/stdc++.h>
using namespace std;

/*
//Debugging with static array
int* fun(){
	int a[] = {1,2,3,4};
	cout<<a<<endl; //ref of a[0] -- 10000

	cout<<a[0]<<endl; // -- 1

	return a;
}


int main(){

	int *ptr = fun();
	cout<<ptr<<endl; //-- ref of a[0] -- 10000

	cout<<ptr[0]<<endl; // --  Not element 1 bcz statis memory will delete in fun() so it will be any random number.
	return 0;
}
*/

//Debugging with Dynamic array
int* fun(){
	int *a = new int[10];

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;

	cout<<a<<endl; //ref of a[0] -- 10000

	cout<<a[0]<<endl; // -- 1

	return a;
}


int main(){

	int *ptr = fun();
	cout<<ptr<<endl; //-- ref of a[0] -- 10000

	cout<<ptr[0]<<endl; // -- 1

	delete [] ptr;
	return 0;
}
