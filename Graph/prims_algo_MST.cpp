#include<bits/stdc++.h>
using namespace std;

//Graph
class Graph{
	vector<pair<int, int> > *l;
	int V;
public:
	Graph(int V){
		this->V = V;
		l = new vector<pair<int, int> >[V];
	}

	void addEdge(int x, int y, int wt){
		l[x].push_back({y,wt});
		l[y].push_back({x,wt});
	}

	int prims_mst(){
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

		//another Array
		//visited array that denotes whether the node has been included in the MST or not
		bool *vis = new bool[V]{0};
		int ans=0;

		//begin
		Q.push({0,0});

		while(!Q.empty()){
			//pick out the edge with min weight
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if(vis[to]){
				//discard the change and continue
				continue;
			}

			//otherwise take the current edge
			ans += weight;
			vis[to] = 1;

			//add the new edges in the queue
			for(auto x: l[to]){
				if(vis[x.first] == 0){
					Q.push({x.second, x.first});
				}
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

	cout<<g.prims_mst()<<endl;

	return 0;
}