#include<bits/stdc++.h>
using namespace std;

//DSU Data structure
//Pair Compression + Union By Rank
//Hint : Compile with cpp ie cpp17
class DSU{
	int *parent;
	int *rank;
public:
	DSU(int V){
		parent = new int[V];
		rank = new int[V];
		//parent = -1, rank = 1

		for(int i=0;i<V;i++){
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i){
		if( parent[i] == -1){
			return i;
		}
		return parent[i] = find(parent[i]);
	}

	void unite(int x, int y){
		int s1 = find(x);
		int s2 = find(y);

		if(s1 != s2){
			if(rank[s1] < rank[s2]){
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}



};

class Graph{
	vector<vector<int> > edgelist;
	int V;

public:
	Graph(int V){
		this->V = V;
	}

	void addEdge(int x, int y, int w){
		edgelist.push_back({w,x,y});
	}

	int kruskal_mst(){
		//1. Sort all edges on the bases of weight
		sort(edgelist.begin(),edgelist.end());
		DSU s(V);
		
		int ans = 0;
		for(auto edge : edgelist){
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			//take edge in MST if it doesn't make a cycle
			if(s.find(x) != s.find(y)){
				s.unite(x,y);
				ans += w;
			}
		}
		return ans;
	}

};

int main(){

	Graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(1,3,3);
	g.addEdge(3,2,4);
	g.addEdge(2,0,2);
	g.addEdge(0,3,2);
	g.addEdge(1,2,2);

	cout<<g.kruskal_mst()<<endl;
	return 0;
}