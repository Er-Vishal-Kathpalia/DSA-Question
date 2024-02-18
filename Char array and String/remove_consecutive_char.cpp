#include<iostream>
using namespace std;


void remove_consecutive_char(char a[]){

	int i = 0;
	int len = strlen(a) - 1;
	if( len<2 ){
		return;
	}
	for(int j=1;j<=len;j++){
		char ch = a[j];
		if( a[i] != ch ){
			i++;
			a[i] = ch;
		}
	}
	a[i+1] = '\0';
	return;

}

int main(){

	char a[1000];
	cin.getline(a, 1000);
	remove_consecutive_char(a);
	cout<<a<<endl;
	return 0;
}