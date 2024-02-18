#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(){
	int d;
	cin>>d;

	if(d == -1){
		return NULL;
	}

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

pair<int,bool> heightBalanced(node* root){
	pair<int, bool> ans;
	if(root == NULL){
		ans.first = 0;
		ans.second = true;
		return ans;
	}

	pair<int, bool> left = heightBalanced(root->left);
	pair<int, bool> right = heightBalanced(root->right);
	ans.first = max(left.first,right.first)+1;
	if( abs(left.first-right.first) <= 1 && left.second && right.second ){
		ans.second = true;
	} else {
		ans.second = false;
	}
	return ans;
}

class HBPair{
public:
	int height;
	bool balance;
};

HBPair isHeightBalance(node *root){
	HBPair p;
	if(root == NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}

	HBPair left = isHeightBalance(root->left);
	HBPair right = isHeightBalance(root->right);
	p.height = max(left.height,right.height)+1;
	if( abs(left.height-right.height) <= 1 && left.balance && right.balance ){
		p.balance = true;
	} else {
		p.balance = false;
	}
	return p;
}


int main(){

	node* root = buildTree();

	pair<int, bool> ans = heightBalanced(root);
	if(ans.second){
		cout<<"Balanced"<<endl;
	} else{
		cout<<"Not Balanced"<<endl;
	}

	if(isHeightBalance(root).balance){
		cout<<"Balanced"<<endl;
	} else{
		cout<<"Not Balanced"<<endl;
	}
	return 0;
}