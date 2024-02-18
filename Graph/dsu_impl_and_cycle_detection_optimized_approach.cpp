#include<bits/stdc++.h>
using namespace std;

/*
Optimizations::
1. Path Compression optimization in find Fn  - O(1)
2. Union By Rank optimization in Union Fn -- Maintain a rank funtion to find the larger and smaller set
and while doing union of two sets join the smaller set node with larger one. - O(1)
*/
class Graph{
	int V;
	list<pair<int,int> > l;
public:

	Graph(int V){
		this->V = V;
	}

	void addEdge(int x, int y){
		l.push_back(make_pair(x,y));
	}

	int findSet(int i, int parent[]){
		if(parent[i] == -1){
			return i;
		}

		return parent[i] = findSet(parent[i],parent);
	}

	void union_set(int a, int b, int parent[], int rank[]){

		int set1 = findSet(a,parent);
		int set2 = findSet(b,parent);

		if(set1 != set2){
			if( rank[set1] < rank[set2] ){
				parent[set1] = set2;
				rank[set1] += rank[set2];
			} else{
				parent[set2] = set1;
				rank[set2] += rank[set1];
			}
		} 
	}

	bool isCyclePresent(){

		int *parent = new int[V];
		int *rank = new int[V];

		for(int i=0;i<=V;i++){
			parent[i] = -1;
			rank[i] = 1;
 		}

 		for(auto edge : l){
 			int x = edge.first;
 			int y = edge.second;

 			int s1 = findSet(x,parent);
 			int s2 = findSet(y,parent);

 			if(s1 != s2){
 				union_set(x,y,parent, rank);
 			} else{
 				return true;
 			}
 		}
 		delete [] parent;
 		delete [] rank;
 		return false;
	}

};


int main(){

	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(0,4);
	g.addEdge(5,6);
	g.addEdge(2,5);
	//g.addEdge(2,6);


	if(g.isCyclePresent()){
		cout<<"cycle present"<<endl;
	}
	else{
		cout<<"No Cycle present"<<endl;
	}

	return 0;
}