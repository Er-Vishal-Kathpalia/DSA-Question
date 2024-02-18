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

	void dfs(){
		map<T, bool> isVisited;
		for(auto node:l){
			T val = node.first;
			isVisited[val] = false;
		}
		//Connected component -- Iterate over all the nodes
		// and check if all are not visited
		int cnt = 0;
		for(auto p:l){
			T node = p.first;
			if(!isVisited[node]){
				cout<<"Component "<<cnt<<" -->";
				dfs_helper(node, isVisited);
				cnt++;
				cout<<endl;
			}
		}
	}

};


int main(){

	Graph<int> g;

	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);

	g.addEdge(5,6);
	g.addEdge(6,7);

	g.addEdge(8,8);

	g.dfs();
	
	return 0;
}