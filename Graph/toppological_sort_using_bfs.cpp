#include<bits/stdc++.h>
using namespace std;

/*
1. Topological sort using map
2. Topological sort using list
*/

// Using Map
/*
template<typename T>
class Graph{
	map<T, list<T> > m;
	int V;
	map<T, int> inOrdering;
public:

	Graph(int vertices){
		V = vertices;
		for(int i=0;i<V;i++){
			inOrdering[i] = 0;
		}
	}

	void addEdge(T x, T y){
		m[x].push_back(y);
		inOrdering[y]++;
	}

	void topological_sort(){
		queue<T> q;

		for(auto it: inOrdering){
			if(it.second == 0){
				q.push(it.first);
			}
		}

		while(!q.empty()){
			T node = q.front();
			q.pop();

			cout<<node<<" ";
			for(auto itr: m[node]){
				inOrdering[itr]--;
				if(inOrdering[itr] == 0){
					q.push(itr);
				}
			}
		}
		return;
	}
};
*/

template<typename T>
class Graph{
	int V;
	list<T> *l;
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(T x, T y){
		l[x].push_back(y);
	}

	void topological_sort(){

		int *indegree = new int[V];

		//init by 0
		for(int i=0;i<V;i++){
			indegree[i] = 0;
		}

		//build indegree of elements in list of array
		for(int i=0;i<V;i++){
			for(auto y:l[i]){
				indegree[y]++;
			}
		}

		queue<T> q;
		//if indegree of elements is 0 push element in queue
		for(int i=0;i<V;i++){
			if(indegree[i]==0){
				q.push(i);
			}
		}

		//until queue is empty print the current node and push the nbr if indegree becomes 0.
		while(!q.empty()){
			T node = q.front();
			q.pop();

			cout<<node<<" ";
			for(auto nbr:l[node]){
				indegree[nbr]--;
				if(indegree[nbr] == 0){
					q.push(nbr);
				}
			}
		}
		return;
	}
};


int main(){

	Graph<int> g(6);

	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(3,5);
	g.addEdge(4,5);


	g.topological_sort();
	return 0;
}