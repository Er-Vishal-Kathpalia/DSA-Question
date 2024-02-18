#include<bits/stdc++.h>
using namespace std;

//pass by value
void pass_by_value(int a){
	a = a+1;
	cout<<a<<endl; // 1001
}


//pass by reference
void pass_by_reference( int *a ){
	*a = *a + 1;
	cout<<*a<<endl;
}

int main(){
	int a = 1000;
	// pass_by_value(a);
	pass_by_reference(&a);
	cout<<a<<endl; // 1001
	
	return 0;
}
