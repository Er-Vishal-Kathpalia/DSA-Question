#include<bits/stdc++.h>
#include<string>
using namespace std;

int stringToInt(char *a, int len){
	//base case
	if(len == 0){
		return 0;
	}
	int digit = a[len-1]-'0';
	int small_ans = stringToInt(a,len-1);
	return small_ans*10 + digit;
}

int main(){
	
	char a[] = "4321";
	int len = strlen(a);

	cout<<stringToInt(a,len)<<endl;

	cout<<endl;
	return 0;
}


/*

"2048" -- 4

8*1 = 8
8+4*10 = 48
48+0*100 = 48
48+2*1000 = 2048



*/