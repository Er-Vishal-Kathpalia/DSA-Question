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

//pre order traversal
void printPreorder(node* root){

	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

//inorder traversal
void printInorder(node* root){

	if(root == NULL){
		return;
	}

	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

//post order traversal
void printPostorder(node* root){

	if(root == NULL){
		return;
	}

	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}

int height(node* root){
	if(root == NULL){
		return 0;
	}

	int l = height(root->left);
	int r = height(root->right);
	return max(l,r)+1;
}

void printKthNode(node* root, int k){
	if(root == NULL){
		return;
	}

	if(k == 1){
		cout<<root->data<<" ";
	}

	printKthNode(root->left, k-1);
	printKthNode(root->right, k-1);
	return;
}

int main(){

	node* root = buildTree();
	cout<<"Pre order traversal"<<endl;
	printPreorder(root);
	cout<<endl;

	cout<<"In order traversal"<<endl;
	printInorder(root);
	cout<<endl;
	
	cout<<"Pre order traversal"<<endl;
	printPostorder(root);
	cout<<endl;

	cout<<"Height of tree"<<endl;
	cout<<height(root)<<endl;

	cout<<"Print Kth node"<<endl;
	printKthNode(root,3);
	cout<<endl;

	int h = height(root);

	cout<<"Level order traversal"<<endl;
	for(int i=1;i<=h;i++){
		printKthNode(root,i);
		cout<<endl;
	}

	return 0;
}