#include<bits/stdc++.h>
using namespace std;

int main(){

	char s[] = "Today is the rainy day";

	char *ptr = strtok( s, " " );
	cout<<ptr<<endl;

	// char *ptr1 = strtok( NULL, " " );
	// cout<<ptr1<<endl;

	while( ptr != NULL ){
		ptr = strtok( NULL, " ");
		cout<<ptr<<endl;
	}
	return 0;
}