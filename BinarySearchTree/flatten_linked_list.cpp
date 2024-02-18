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

class LinkedList{

public:
	node*head;
	node*tail;

};

LinkedList flatten(node* root){
	LinkedList l;

	if(root == NULL){
		l.head = l.tail = NULL;
		return l;
	}
	//Leaf node
	if(root->left == NULL && root->right == NULL){
		l.head = l.tail = root;
		return l;
	}

	//Left is not null
	if(root->left!=NULL && root->right==NULL){
		LinkedList leftLL = flatten(root->left);
		leftLL.tail->right = root;

		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	//Right is not null
	if(root->left==NULL && root->right!=NULL){
		LinkedList rightLL = flatten(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}
	//Both the sides are not null
	LinkedList leftLL = flatten(root->left);
	LinkedList rightLL = flatten(root->right);
	leftLL.tail->right = root;
	root->right = rightLL.head;

	l.head = leftLL.head;
	l.tail = rightLL.tail;
	return l;

}

int main(){

	node* root = build();
	bfs(root);
	cout<<endl;
	inorder(root);
	cout<<endl;

	LinkedList ll = flatten(root);
	node*temp = ll.head;

	while( temp!=NULL ){
		cout<<temp->data<<" -> ";
		temp = temp->right;
	}
	cout<<endl;
	return 0;
}