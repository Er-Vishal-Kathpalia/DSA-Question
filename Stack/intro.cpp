#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Stack{
private:
	vector<T> s;
public:
	
	void push(T data){
		s.push_back(data);
		return;
	}

	int length(){
		return s.size();
	}

	T top(){
		if(empty()){
			return -1;
		}
		int len = s.size();
		return s[len-1];
	}

	bool empty(){
		return s.size()==0;
	}

	void pop(){
		if(!s.empty()){
			s.pop_back();
		}
	}

};

int main(){
	Stack<char> stack;
	// stack.push(10);
	// stack.push(20);
	// stack.push(30);
	// stack.push(40);
	// stack.push(50);
	// stack.push(60);
	// stack.push(70);
	// stack.push(80);

	for(int i=80;i>=65;i--){
		stack.push(i);
	}
	cout<<stack.empty()<<endl;

	while(!stack.empty()){
		cout<<stack.top()<<" ";
		stack.pop();
	}

	// cout<<stack.length()<<endl;

	// cout<<stack.top()<<endl;

	// stack.pop();
	// stack.pop();

	// cout<<stack.top()<<endl;
	// cout<<stack.length()<<endl;

	return 0;
}


/*
1 2 3 4 5 6



*/