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

	bool cycle_helper(T node,bool *visited, bool *stack){

		visited[node] = true;
		stack[node] = true;

		for(T nbr: l[node]){
			if(stack[nbr] == true){
				return true;
			}
			else if(visited[nbr] == false){
				bool cycle_mila = cycle_helper(nbr,visited,stack);
				if(cycle_mila == true){
					return true;
				}
			}

		}

		stack[node] = false;
		return false;
	}

	bool cycle_detection(){

		bool *visited = new bool[V];
		bool *stack = new bool[V];

		for(int i=0;i<V;i++){
			visited[i] = stack[i] = false;
		}

		return cycle_helper(0,visited,stack);
	}

};


int main(){

	Graph<int> g(7);

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,5);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(4,2);

	if(g.cycle_detection()){
		cout<<"Cycle found"<<endl;
	} else{
		cout<<"Cycle not found"<<endl;
	}
	
	return 0;
}