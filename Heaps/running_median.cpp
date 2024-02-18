#include <bits/stdc++.h>
#include <queue>
using namespace std;

/*
Problem Statement: Find the running median while adding an element.
*/

int main(){

	//max heap by default
	priority_queue<int> leftHeap;

	//min heap
	priority_queue<int, vector<int>, greater<int> > rightHeap;

	int d;
	cin>>d;
	leftHeap.push(d);

	float mid = d;
	cout<<"Median is "<<mid<<endl;
	cin>>d;

	while(d!=-1){
		//logic
		if(leftHeap.size() > rightHeap.size()){
			if(d<mid){
				rightHeap.push(leftHeap.top());
				leftHeap.pop();
				leftHeap.push(d);
			} else{
				rightHeap.push(d);
			}
			mid = (leftHeap.top()+rightHeap.top())/2.0;
		} 
		else if( leftHeap.size() == rightHeap.size() ){
			if(d<mid){
				leftHeap.push(d);
				mid = leftHeap.top();
			} else{
				rightHeap.push(d);
				mid = rightHeap.top();
			}
		}
		else{
			if(d<mid){
				leftHeap.push(d);
			} else{
				leftHeap.push(rightHeap.top());
				rightHeap.pop();
				rightHeap.push(d);
			}
			mid = (leftHeap.top()+rightHeap.top())/2.0;
		}
		cout<<"Median is "<<mid<<endl;
		cin>>d;
	}

	return 0;
}