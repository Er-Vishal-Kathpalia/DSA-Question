#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	int V;
	list<T> *l;
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(T x, T y, bool directed = true){
		l[x].push_back(y);
		if(!directed){
			l[y].push_back(x);
		}
	}

	bool cycle_helper(T src, bool *visited, T parent){
		visited[src] = true;

		for(T nbr: l[src]){
			if(!visited[nbr]){
				bool cycle_found = cycle_helper(nbr, visited, src);
				if(cycle_found){
					return true;
				}
			} else if(nbr!=parent) {
				return true;
			}
		}

		return false;
	}

	bool cycle_detection(){
		bool *visited = new bool[V];

		for(int i=0;i<V;i++){
			visited[i] = false;
		}
		return cycle_helper(0,visited,-1);
	}

};


int main(){

	Graph<int> g(7);

	g.addEdge(0,1,false);
	g.addEdge(1,2,false);
	g.addEdge(2,3,false);
	g.addEdge(3,4,false);
	g.addEdge(0,4,false);


	if(g.cycle_detection()){
		cout<<"Cycle found"<<endl;
	} else{
		cout<<"Cycle not found"<<endl;
	}
	
	return 0;
}