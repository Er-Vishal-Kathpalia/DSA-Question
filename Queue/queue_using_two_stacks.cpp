#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1,stack<int> &s2){
	while(!s1.empty()){
		int data = s1.top();
		s2.push(data);
		s1.pop();
	}
	return;
}

class Queue{
	stack<int> s1;
	stack<int> s2;
public:

	bool empty(){
		return s1.size() == 0;
	}

	void push_front(int data){
		if(s1.empty()){
			s1.push(data);
		} else{
			transfer(s1,s2);
			s1.push(data);
			transfer(s2,s1);
		}
	}

	void pop(){
		s1.pop();
	}

	int front(){
		return s1.top();
	}

};


int main(){

	Queue q;
	q.push_front(10);
	q.push_front(20);
	q.push_front(30);
	q.push_front(40);
	q.push_front(50);

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	
	return 0;
}


/*

s1 = [10 20 30]
s2 = [20 10]

Push - 10 20 30 40 50

*/