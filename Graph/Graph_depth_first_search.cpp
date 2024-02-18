#include <bits/stdc++.h>
#include <map>
using namespace std;

template<typename T>
class Graph{
	map<T, list<T> > l;
public:

	void addEdge(T x, T y){
		l[x].push_back(y);		
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &isVisited){
		cout<<src<<" ";
		isVisited[src] = true;

		for(T nbr: l[src]){
			if(!isVisited[nbr]){
				dfs_helper(nbr, isVisited);
			}
		}
	}

	void dfs(T src){
		map<T, bool> isVisited;
		for(auto node:l){
			T val = node.first;
			isVisited[val] = false;
		}
		dfs_helper(src, isVisited);
	}

};


int main(){

	Graph<int> g;

	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);

	g.dfs(0);
	cout<<endl;

	return 0;
}