#include<bits/stdc++.h>
using namespace std;

class Queue{

	int *arr;
	int f,r,cs,ms;

public:

	Queue(int ds = 10){
		arr = new int[ds];
		cs = 0;
		ms = ds;
		f = 0;
		r = ms-1;
	}

	bool full(){
		return cs==ms;
	}

	void push(int data){
		if(!full()){
			r = (r+1)%ms;
			arr[r] = data;
			cs++;
		}
	}

	bool empty(){
		return cs==0;
	}

	void pop(){
		if(!empty()){
			f = (f+1)%ms;
			cs--; 
		}
	}

	int front(){
		return arr[f];
	}

	~Queue(){
		if(arr != NULL){
			delete [] arr;
			arr = NULL;
		}
	}

};


int main(){
	int n;
	cin>>n;
	Queue q;

	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		q.push(data);
	}

	cout<<q.front()<<endl; 

	q.pop();
	q.pop();
	q.pop();

	cout<<q.front()<<endl;

	q.push(100);
	q.push(200);
	q.push(300);

	q.pop();
	q.pop();
	
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	return 0;
}