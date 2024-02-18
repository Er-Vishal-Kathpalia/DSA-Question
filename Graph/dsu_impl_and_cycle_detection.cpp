#include<bits/stdc++.h>
using namespace std;

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

		return findSet(parent[i],parent);
	}

	void union_set(int a, int b, int parent[]){

		int set1 = findSet(a,parent);
		int set2 = findSet(b,parent);

		if(set1 != set2){
			parent[a] = b;
		} 
	}

	bool isCyclePresent(){

		int *parent = new int[V];
		for(int i=0;i<=V;i++){
			parent[i] = -1;
 		}

 		for(auto edge : l){
 			int x = edge.first;
 			int y = edge.second;

 			int s1 = findSet(x,parent);
 			int s2 = findSet(y,parent);

 			if(s1 != s2){
 				union_set(x,y,parent);
 			} else{
 				cout<<"Same parents "<<s1<<" and "<<s2<<endl;
 				return true;
 			}
 		}
 		delete [] parent;
 		return false;
	}

};


int main(){

	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	// g.addEdge(3,0);

	if(g.isCyclePresent()){
		cout<<"cycle present"<<endl;
	}
	else{
		cout<<"No Cycle present"<<endl;
	}

	return 0;
}