#include<iostream>
#include <stack>
using namespace std;

bool isValidParanthesis(char *s){
	stack<char> temp;

	for(int i=0;s[i]!='\0';i++){
		char ch = s[i];
		if(ch == '('){
			temp.push(s[i]);
		}
		else if(s[i] == ')'){
			if( temp.empty() || temp.top() != '('){
				return false;
			}
			temp.pop();
		}
	}
	return temp.empty();
}

int main(){

	char s[] = "((((1+2)*4)-1+5-9/(4/9)))";
	if(isValidParanthesis(s)){
		cout<<"Valid"<<endl;
	} else{
		cout<<"Not Valid"<<endl;
	}
	return 0;
}