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

	int pairing(){

		int *parent = new int[V];
		int *rank = new int[V];

		for(int i=0;i<=V;i++){
			parent[i] = -1;
			rank[i] = 1;
 		}

 		//CodeLogic
 		int ans = 0;
 		for(auto edge : l){
 			int i = edge.first;
 			int j = edge.second;

 			int s1 = findSet(i,parent);
 			int s2 = findSet(j,parent);

 			union_set(s1,s2,parent,rank);
 		}

 		for (int i=1;i<=V;i++){
 			ans += V-rank[findSet(i,parent)];
 		}

 		delete [] parent;
 		delete [] rank;
 		return ans/2;

	}

};


int main(){

	int n,m;
	cin>>n>>m;
	Graph g(n);
	
	while(m--){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}

	cout<<g.pairing()<<endl;

	return 0;
}