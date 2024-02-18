#include<iostream>
using namespace std;


int main(){

	char a[] = {'h','e','l','l','o'}; // It will contain garbage values
	char b[100] = {'h','e','l','l','o'};
	cout<<a<<endl;
	cout<<b<<endl;
	

	char c[] = {'h','e','l','l','o','\0'}; // It is recommed to put \0 at last
	cout<<c<<" "<<sizeof(c)<<endl; // -6

	char d[] = "hello";
	cout<<d<<" "<<sizeof(d)<<endl;// -6 It will automatically add \0 at last


	// char arr[1000];
	// cin>>arr;
	// cout<<arr; // It will print only first word by default it will exit the \n char.

	// char arr2[1000];
	// // cin.get(arr2, 1); -- It will not take any input bcz it will consider last \0 as first character.
	// cin.get(arr2, 2); // -- It will take only first char as input.
	// cout<<arr2<<endl;


	// char arr3[1000];
	// cin.getline(arr3, 1000, '$');
	// cout<<arr3<<endl;



	return 0;
}