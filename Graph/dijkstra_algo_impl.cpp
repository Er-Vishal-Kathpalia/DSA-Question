#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	unordered_map<T, list<pair<T, int> > > m;
public:

	void addEdge(T u, T v, int dist, bool biDirectional = true){
		m[u].push_back(make_pair(v,dist));
		if(biDirectional){
			m[v].push_back(make_pair(u,dist));
		}
	}

	void print(){
		for(auto j : m){
			cout<<j.first<<"->";
			for(auto l:j.second){
				cout<<l.first<<", "<<l.second<<" ";
			}
			cout<<endl;
		}
	}

	void dijkastraSSSP(T src){
		unordered_map<T, int> dist; 

		//initially set all the distance as INT_MAX
		for(auto j:m){
			dist[j.first] = INT_MAX;
		}

		set<pair<int, T> > s;
		dist[src] = 0;
		s.insert(make_pair(0,src));

		while(!s.empty()){
			auto p = *(s.begin());
			T node = p.second;
			int node_dist = p.first;

			s.erase(s.begin());

			//Iterate over nbr of node
			for(auto childpair:m[node]){
				if( node_dist + childpair.second < dist[childpair.first]){
					//In the set updation of a aparticualr is not possible
					// we have to remove the old pair, and insert the new pair to simulate updation
					T dest = childpair.first;
					auto f = s.find(make_pair(dist[dest],dest));\
					if(f!=s.end()){
						s.erase(f);
					}
					dist[dest] = node_dist+childpair.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
		}
		//Let's print distance to all other nodes from src
		for(auto d: dist){
			cout<<d.first<<" is located at distance of "<<d.second<<endl;
		}
	}

};


int main(){

	/*
	Graph<int> g;
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(1,3,4);
	g.addEdge(1,4,7);
	g.addEdge(3,4,2);
	//g.printAdjlist();
	g.dijkastraSSSP(1);
	*/

	Graph<string> india;
	india.addEdge("Amritsar","Delhi",1);
	india.addEdge("Amritsar","Jaipur",4);
	india.addEdge("Jaipur","Delhi",2);
	india.addEdge("Jaipur","Mumbai",8);
	india.addEdge("Bhopal","Agra",2);
	india.addEdge("Mumbai","Bhopal",3);
	india.addEdge("Agra","Delhi",1);

	india.dijkastraSSSP("Amritsar");

	return 0;
}