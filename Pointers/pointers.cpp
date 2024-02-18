#include<bits/stdc++.h>
using namespace std;



int main(){

	int a = 10;
	cout<<a<<endl; //10
	cout<<&a<<endl; //1000

	float b = 10.5;
	cout<<b<<endl; //10.5
	cout<<&b<<endl; //100000

	char ch = 'A';
	//Pointers will not work for char variable
	cout<<ch<<endl; //-- A
	cout<<&ch<<endl; // -- A

	//Explicit type casting of char array
	cout<<(void *)&ch<<endl; //-- address of ch

	int *ptr = &a;
	//int* ptr = &a; //both int* ptr and int *ptr are same
	cout<<ptr<<endl;  //1000
	cout<<&ptr<<endl; //2000
	cout<<*ptr<<endl; //10
	cout<<&(*ptr)<<endl; //1000
	cout<<ptr[0]<<endl; //10

	cout<<*(&ptr)<<endl; //1000
	return 0;
}
