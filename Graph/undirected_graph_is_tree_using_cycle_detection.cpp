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

	void addEdge(T x, T y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool is_tree(T src){
		queue<T> q;
		bool *visited = new bool[V];
		int *parent = new int[V];

		for(int i=0;i<V;i++){
			visited[i] = false;
			parent[i] = i;
		}

		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			T node = q.front();
			q.pop();

			for(auto nbr:l[node]){
				if(visited[nbr] && parent[node]!=nbr){
					return false;
				} else if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = node;
				}
			}
		}
		return true;
	}

};


int main(){

	Graph<int> g(4);

	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,3);

	if(g.is_tree(1)){
		cout<<"Cycle Not found it means tree"<<endl;
	} else{
		cout<<"Cycle found it means not a tree"<<endl;
	}
	return 0;
}