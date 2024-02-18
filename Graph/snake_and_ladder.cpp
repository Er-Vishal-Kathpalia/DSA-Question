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

	void adjList(){

		for(auto itr:l){
			T node = itr.first;
			cout<<"Node "<<node<<"--> ";
			for(T val:l[node]){
				cout<<val<<" ";
			}	
			cout<<endl;
		}
	}

	int shortestPath(T src, T dest){
		queue<T> q;
		map<T,int> dist;
		map<T,T> parent;

		for(auto itr:l){
			T val = itr.first;
			dist[val] = INT_MAX;
		}

		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while(!q.empty()){
			
			T node = q.front();
			q.pop();

			for(T nbr:l[node]){
				if(dist[nbr] == INT_MAX){
					q.push(nbr);
					//mark the node visited
					dist[nbr] = dist[node] + 1;
					parent[nbr] = node;
				}
			}
		}

		T temp = dest;
		cout<<"Distance "<<endl;
		while(temp!= src){
			cout<<temp<<"<--";
			temp = parent[temp];
		}
		cout<<src<<endl;
		cout<<"Min Number of turns required is ";
		return dist[dest];
	}

};


int main(){

	int board[50] = {0};

	//Input
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = 22;

	Graph<int> g;
	//Add Edges to the graph
	for(int i=0;i<=36;i++){
		for(int dice=1;dice<=6;dice++){
			int j = i+dice;
			j += board[j];
			if(j<=36){
				g.addEdge(i,j);
			}
		}
	}
	g.addEdge(36,36);

	// g.bredthFirstSearch(0);
	// cout<<endl;
	// g.adjList();

	//dist to reach at final position
	cout<<g.shortestPath(0,36)<<endl;



	return 0;
}