#include<bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string>& operations){
	int X=0;
	for(int i=0;i<operations.size();i++){
		string type = operations[i];
		if(type == "X++" || type == "++X"){
			X++;
		} 
		else if(type == "--X" || type == "X--"){
			X--;
		}
	}
	return X;
}


int main(){

    vector<string> v;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string no;
        cin>>no;
        v.push_back(no);
    }
    cout<<finalValueAfterOperations(v)<<endl;
    return 0;
}

/*


*/