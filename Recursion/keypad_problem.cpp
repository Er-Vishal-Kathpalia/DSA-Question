#include<bits/stdc++.h>
using namespace std;

char keypad[][100] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};


void generate_names(char *in, char *out, int i, int j){

	//base case
	if(in[i] == '\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}

	int digit = in[i] - '0';

	if(digit == 0 || digit == 1){
		generate_names(in,out,i+1,j);
	}

	for(int k=0;keypad[digit][k]!='\0';k++){
		out[j] = keypad[digit][k];
		generate_names(in,out,i+1,j+1);
	}

	return;
}

int main(){

	char in[1000];
	cin>>in;

	char out[1000];
	int i,j;
	i = j = 0;
	
	generate_names(in,out,i,j);

	return 0;
}