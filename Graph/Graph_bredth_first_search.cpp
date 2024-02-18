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

	void bredthFirstSearch(T src){
		queue<T> q;
		map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			
			T node = q.front();
			q.pop();

			for(T nbr:l[node]){
				if(!visited[nbr]){
					q.push(nbr);
					//mark the node visited
					visited[nbr] = true;
				}
			}
			cout<<node<<" ";
		}

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

	g.bredthFirstSearch(0);
	return 0;
}