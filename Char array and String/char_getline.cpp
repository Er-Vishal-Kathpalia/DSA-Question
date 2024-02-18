#include<iostream>
using namespace std;


void getline(char a[], int maxlen, char del){

	int i = 0;
	char ch = cin.get();
	while( ch != del ){
		a[i] = ch;
		i++;
		if(i == (maxlen - 1)){
			break;
		}
		ch = cin.get();
	}
	a[i] = '\0';
	return;
}

int main(){

	char a[1000];
	getline( a, 1000, '$' );
	cout<<a<<endl;
	return 0;
}