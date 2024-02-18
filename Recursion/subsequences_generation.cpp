#include<bits/stdc++.h>
using namespace std;

void generate_subsequence(char *input, char *output,int i, int j){
	
	//base case
	if( input[i] == '\0' ){
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}

	//include the value of input i
	output[j] = input[i];
	generate_subsequence(input, output, i+1, j+1);

	//exclude the value of input i
	generate_subsequence(input, output, i+1, j);

}


int main(){
	char input[] = "abc";

	char output[1000];

	generate_subsequence(input, output,0,0);

	return 0;
}