#include<iostream>
#include<list>
using namespace std;

class Queue{
	int cs;
	list<int> q;

public:

	Queue(){
		cs = 0;
	}

	bool isEmpty(){
		return cs==0;
	}

	void push(int data){
		q.push_back(data);
		cs++;
	}

	void pop(){
		if(!isEmpty()){
			q.pop_front();
			cs--;
		}
	}

	int front(){
		return q.front();
	}
};


int main(){

	Queue q;

	for(int i=1;i<=10;i++){
		q.push(i);
	}

	q.pop();
	cout<<q.front()<<endl;
	
	q.pop();
	q.pop();

	cout<<q.front()<<endl;

	while(!q.isEmpty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;

	return 0;
}




