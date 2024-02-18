#include<iostream>
#include<queue>
using namespace std;

void transfer(queue<int> &q1,queue<int> &q2){
	while(!q1.empty()){
		int val = q1.front();
		q2.push(val);
		q1.pop();
	}
	return;
}

class Stack{
	queue<int> q1;
	queue<int> q2;

public:

	bool empty(){
		return q1.size() == 0;
	}

	void push(int data){
		if(q1.size() == 0){
			q1.push(data);
		} else{
			transfer(q1,q2);
			q1.push(data);
			transfer(q2,q1);
		}
	}

	void pop(){
		if(!q1.empty()){
			q1.pop();
		}
	}

	int top(){
		return q1.front();
	}
};


int main(){

	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	s.pop();
	s.pop();
	cout<<s.top()<<endl;
	return 0;
}


/*

q1 = [10 20 30]
q2 = [10 20]

Push - 50 40 30 20 10

*/