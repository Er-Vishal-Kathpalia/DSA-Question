#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given N ropes of different sizes , we have to join the ropes together.
The cost of joining 2 ropes of different sizes A and B is (A+B). Find the minimum cost
to join all the ropes together.

Ropes - 4,3,2,6
*/

int join_the_ropes(int ropes[], int n){
	//min heap
	priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes+n);

	int cost=0;

	while(n > 1){
		int A = pq.top();
		pq.pop();
		int B = pq.top();
		pq.pop();
		int min_cost = (A+B);
		n--;
		cost += min_cost;
		pq.push(min_cost);
	}
	return cost;
}


int main(){

	int ropes[] = {4,3,2,6};
	int n = sizeof(ropes)/sizeof(ropes[0]);

	cout<<join_the_ropes(ropes,n)<<endl;

	return 0;
}