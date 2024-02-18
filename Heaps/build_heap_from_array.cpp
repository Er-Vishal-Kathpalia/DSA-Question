#include <bits/stdc++.h>
using namespace std;

//O(Nlog(N))
void buildHeap(vector<int> &v){

	for(int i=2;i<v.size();i++){
		int idx = i;
		int parent = i/2;
		while(idx > 1 && v[idx] > v[parent]){
			swap(v[idx],v[parent]);
			idx = parent;
			parent = parent/2;
		}
	}
}

bool minHeap = true;

bool compare(int a, int b){
	if( minHeap ){
		return a < b;
	}
	else{
		return a > b;
	}
}

void heapify(vector<int> &heap, int idx){
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
			heapify(heap,min_idx);
		}
	}


//O(N)
void buildHeapInOptimised(vector<int> &v){

	for(int i=v.size()-1/2;i>0;i--){
		heapify(v,i);
	}

}

int main(){	

	vector<int> v {-1,10,20,5,6,1,8,9,4};

	buildHeap(v);

	for(int x:v){
		cout<<x<<" ";
	}

	return 0;
}