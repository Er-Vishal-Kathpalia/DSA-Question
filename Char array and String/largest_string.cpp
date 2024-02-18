#include<iostream>
#include<cstring>
using namespace std;


int main(){

	int n;
	cin>>n;

	char a[1000];
	char ans[1000];
	int maxlen = -1;

	while( n>=0 ){
		cin.getline(a, 1000);
		int currentlen = strlen(a);
		if( currentlen >= maxlen ){
			maxlen = currentlen;
			strcpy( ans, a );
		}
		n--;
	}
	cout<<ans<<endl;
	cout<<"maxlength is "<<maxlen<<endl;

	return 0;
}