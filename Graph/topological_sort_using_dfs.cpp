#include <bits/stdc++.h>
#include <map>
using namespace std;

template<typename T>
class Graph{
	map<T, list<T> > l;
public:

	void addEdge(T x, T y){
		l[x].push_back(y);		
	}

	void dfs_helper(T src, map<T, bool> &isVisited, list<T> &ordering){
		
		isVisited[src] = true;

		for(T nbr: l[src]){
			if(!isVisited[nbr]){
				dfs_helper(nbr, isVisited, ordering);
			}
		}
		ordering.push_front(src);
		return;
	}

	list<T> dfs(){
		map<T, bool> isVisited;
		list<T> ordering;
		for(auto node:l){
			T val = node.first;
			isVisited[val] = false;
		}

		for(auto p:l){
			T node = p.first;
			if(!isVisited[node]){
				dfs_helper(node,isVisited, ordering);
			}
		}
		return ordering;
	}

};


int main(){

	Graph<string> g;

	g.addEdge("Python","Data Preprocessing");
	g.addEdge("Python","Pytorch");
	g.addEdge("Python","ML basics");
	g.addEdge("Pytorch","Deep learning");
	g.addEdge("ML basics","Deep learning");
	g.addEdge("Deep learning","Face Recog");
	g.addEdge("Data set","Face Recog");

	list<string> ans = g.dfs();
	for(auto itr: ans){
		cout<<itr<<endl;
	}

	return 0;
}