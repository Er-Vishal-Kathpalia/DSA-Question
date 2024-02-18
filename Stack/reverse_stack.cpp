#include<bits/stdc++.h>
using namespace std;

// void reverse(stack<int> &s){
// 	int len = s.size()-1;
// 	stack<int> temp;

// 	while(len>=0){
// 		int top_element =  s.top();
// 		s.pop();

// 		for(int j=0;j<len;j++){
// 			int t = s.top();
// 			temp.push(t);
// 			s.pop();
// 		}

// 		s.push(top_element);
		
// 		while(!temp.empty()){
// 			int temp_pop = temp.top();
// 			s.push(temp_pop);
// 			temp.pop();
// 		}		
// 		len--;
// 	}
// 	return;
// }


void transfer(stack<int> &s1, stack<int> &s2, int n){

	for(int i=0;i<n;i++){
		s2.push(s1.top());
		s1.pop();
	}
	return;
}

void reverseStack(stack<int> &s1){
	int n = s1.size();
	stack<int> s2;
	for(int i=0;i<n;i++){
		int x = s1.top();
		s1.pop();
		//transfer the elements n-i-1 from stack s1 to s2
		transfer(s1,s2,n-i-1);
		//put the element x into the stack s1
		s1.push(x);
		//transfer the elements n-i-1 from stack s2 to s1 back
		transfer(s2,s1, n-i-1); 
	}
	return;
}


int main(){
	int n;
	cin>>n;

	stack<int> s;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		s.push(data);
	}

	reverseStack(s);

	while(!s.empty()){
		cout<<s.top()<<", ";
		s.pop();
	}
	cout<<endl;
	return 0;
}