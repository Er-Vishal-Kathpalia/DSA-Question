#include <bits/stdc++.h>
#include <list>
using namespace std;

class Graph{
	
	unordered_map<string, list<pair<string, int> > > l;
public:

	void addEdge(string x, string y, bool biDirectional, int wt){
		l[x].push_back(make_pair(y,wt));
		if(biDirectional){
			l[y].push_back(make_pair(x,wt));
		}
	}

	void printAdjlist(){
		for(auto itr:l){
			string city = itr.first;
			list<pair<string, int> > val = itr.second;

			cout<<"City "<<city<<"->";
			for(pair<string, int> edge : l[city]){
				string dest = edge.first;
				int weight = edge.second;
				cout<<"("<<dest<<", "<<weight<<")"<<",";
			}
			cout<<endl;
		}
	}

};


int main(){
	Graph g;

	g.addEdge("A","B", true, 20);
	g.addEdge("A","D", false, 50);
	g.addEdge("A","C", true, 10);
	g.addEdge("C","D", true, 40);
	g.addEdge("B","D", true, 30);


	g.printAdjlist();
	return 0;
}