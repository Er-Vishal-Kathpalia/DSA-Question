#include <bits/stdc++.h>
using namespace std;

class Heap{

	vector<int> heap;
	bool minHeap;

	bool compare(int a, int b){
		if( minHeap ){
			return a < b;
		}
		else{
			return a > b;
		}
	}

	void heapify(int idx){
		int left = 2*idx;
		int right = left +1;

		int min_idx = idx;
		int last = heap.size()-1;
		if(left <= last && compare(heap[left], heap[idx])){
			min_idx = left;
		}
		if(right <= last && compare(heap[right], heap[idx])){
			min_idx = right;
		}

		if(min_idx!=idx){
			swap(heap[idx], heap[min_idx]);
			heapify(min_idx);
		}
	}

public:

	Heap(int default_size = 10, bool type = true){
		heap.reserve(default_size);
		heap.push_back(-1);
		minHeap = type;
	}

	bool empty(){
		return heap.size() == 1;
	}

	void push(int data) {
		
		heap.push_back(data);
		int idx = heap.size()-1;
		int parent = idx/2;
		
		while(idx > 1 and compare(heap[idx],heap[parent])){
			swap(heap[idx],heap[parent]);
			idx = parent;
			parent = parent/2;
		}
	}

	int top(){
		return heap[1];
	}

	void pop(){
		//swap the first and last element of vector
		int last = heap.size()-1;
		swap(heap[1],heap[last]);
		//remove the last element;
		heap.pop_back();
		//heapify
		heapify(1);

	}

};

int main(){

	//give some init size, type ->  min/max heap
	Heap heap(10,false);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int no;
		cin>>no;
		heap.push(no);
	}

	//remove all the elements
	while(!heap.empty()){
		int top = heap.top();
		cout<<top<<", ";
		heap.pop();
	}

	return 0;
}