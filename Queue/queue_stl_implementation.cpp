#include<iostream>
#include<queue>
using namespace std;

int main(){

	queue<int> q;

	for(int i=1;i<=10;i++){
		q.push(i);
	}

	q.pop();
	cout<<q.front()<<endl;
	
	q.pop();
	q.pop();

	cout<<q.front()<<endl;

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;

	return 0;
}




