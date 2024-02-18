#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* insertInBst(node*root, int data){

	//base case
	if(root == NULL){
		return new node(data);
	}

	if(data<=root->data){
		root->left = insertInBst(root->left,data);
	} else{
		root->right = insertInBst(root->right,data);
	}

	return root;
}


node* build(){
	int d;
	cin>>d;

	node* root = NULL;
	while(d!=-1){
		root = insertInBst(root,d);
		cin>>d;
	}
	return root;
}

void bfs(node *root){
	//base case
	if(root== NULL){
		return;
	}
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* d = q.front();
		if(d == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		} else {
			cout<<d->data<<" ";
			q.pop();
			
			if(d->left!=NULL){
				q.push(d->left);
			}

			if(d->right!=NULL){
				q.push(d->right);
			}
		}
	}
}

void inorder(node* root){

	if(root == NULL){
		return;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


bool search(node*root, int key){

	//base case
	if(root == NULL){
		return false;
	}
	if(key == root->data){
		return true;
	} 

	if(key < root->data){
		return search(root->left,key);
	}
	return search(root->right,key);
}

node* deleteInBST(node*root, int data){
	if(root == NULL){
		return NULL;
	} 
	else if(data < root->data){
		root->left = deleteInBST(root->left,data);
		return root;
	} else if( data == root->data ){

		//Found the node to delete the 3 cases
		//1. Node with 0 children - leaf node
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		} 
		//2. Node with one children
		else if( root->left != NULL && root->right == NULL ){
			node* temp = root->left;
			delete root;
			return temp;

		}
		else if( root->right != NULL && root->left == NULL ){
			node* temp = root->right;
			delete root;
			return temp;

		}
		//3. Node with 2 childrens
		else{
			node* replace = root->right;
			//find the inorder successor from right subtree
			while(replace->left!=NULL){
				replace = replace->left;
			}
			root->data = replace->data;
			root->right = deleteInBST(root->right,replace->data);
			return root;
		}

	} else{
		root->right = deleteInBST(root->right,data);
		return root;
	}
}

int main(){

	node* root = build();
	bfs(root);
	cout<<endl;
	inorder(root);
	cout<<endl;

	int s;
	cin>>s;
	// if( search(root,s) ){
	// 	cout<<"Found"<<endl;
	// } else{
	// 	cout<<"Not Found"<<endl;
	// }

	deleteInBST(root,s);
	inorder(root);
	cout<<endl;
	

	return 0;
}