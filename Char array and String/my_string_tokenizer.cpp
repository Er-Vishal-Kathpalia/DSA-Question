#include<bits/stdc++.h>
using namespace std;


char *mystrtok(char *s, char delim ){
	cout<<s.length()<<endl;

	return NULL;

}



int main(){

	char s[100] = "Today is the rainy day";

	char *ptr = mystrtok(s, ' ');
	cout<<ptr<<endl;

	while( ptr != NULL ){
		ptr = mystrtok(NULL, ' ');
		cout<<ptr<<endl;
	}

	return 0;
}