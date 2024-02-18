#include <iostream>
#include <queue>
using namespace std;

int main(){	
	//max priority queue
	priority_queue<int> pq;

	//min priority Queue
	priority_queue<int, vector<int>, greater<int> > mpq;


	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		pq.push(no); //O(log(n))
		mpq.push(no);
	}


	while(!pq.empty()){
		cout<<pq.top()<<" "; //O(1)
		pq.pop();            //O(log(n))
	}
	cout<<endl;

	while(!mpq.empty()){
		cout<<mpq.top()<<" "; //O(1)
		mpq.pop();            //O(log(n))
	}
	cout<<endl;
	return 0;
}