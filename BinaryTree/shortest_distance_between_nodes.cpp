#include<bits/stdc++.h>
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

node* lca(node* root, int a,int b){

	if(root==NULL){
		return NULL;
	}

	if(root->data==a || root->data==b){
		return root;
	}

	node* leftans = lca(root->left,a,b);
	node* rightans = lca(root->right,a,b);

	if(leftans!=NULL && rightans!=NULL){
		return root;
	}

	if(leftans!=NULL){
		return leftans;
	}
	return rightans;
}

int search(node* root, int key, int level){

	if(root==NULL){
		return -1;
	}

	if(root->data == key){
		return level;
	}

	int left = search(root->left,key,level+1);
	if(left != -1){
		return left;
	}
	return search(root->right,key,level+1);
}

int findDistance(node* root, int a,int b){

	node* lca_node = lca(root, a, b); //2

	int l1 = search(lca_node,a,0);
	int l2 = search(lca_node,b,0);

	return l1+l2;
}


int main(){

	node* root = buildTree();
	int a = 1;
	int b = 7;
	cout<<findDistance(root,a,b)<<endl;

	a = 9;
	b = 13;
	cout<<findDistance(root,a,b)<<endl;

	return 0;
}