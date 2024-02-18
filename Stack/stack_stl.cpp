#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<int> s;

	for(int i=1;i<10;i++){
		s.push(i);
	}

	cout<<s.empty()<<endl;

	while(!s.empty()){
		cout<<s.top()<<", ";
		s.pop();
	}
	cout<<endl;

	return 0;
}