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

void bfsInLine(node *root){
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

node* buildBalancedTree(int *arr,int s, int e){

	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node* root = new node(arr[mid]);
	root->left = buildBalancedTree(arr,s,mid-1);
	root->right = buildBalancedTree(arr,mid+1,e);
	return root;
}


int main(){

	// node* root = buildTree();

	int arr[] = {1,2,3,4,5,6,7};
	int n = 7;

	node* root = buildBalancedTree(arr,0,n-1);
	bfsInLine(root);
	cout<<endl;

	return 0;
}