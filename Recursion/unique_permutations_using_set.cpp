#include<bits/stdc++.h>
using namespace std;

void permute(char *in, int i, set<string> &store){

	//base case
	if(in[i] == '\0'){
		string temp(in);
		store.insert(temp);
		//cout<<in<<" ";
		return;
	}

	//recursive case
	for(int j=i;in[j]!='\0';j++){
		swap(in[i],in[j]);
		permute(in,i+1,store);
		//Backtracking
		swap(in[i],in[j]);
	}

}


int main(){

	char in[100];
	cin>>in;
	set<string> store;

	permute(in, 0, store);

	for(auto str: store){
		cout<<str<<", ";
	}

	cout<<endl;

	return 0;
}