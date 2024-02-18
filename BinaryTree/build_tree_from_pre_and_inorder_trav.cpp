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


node* createTreeFromTrav(int *in, int *pre, int s, int e){
	static int i=0;

	if(s>e){
		return NULL;
	}

	node* root = new node(pre[i]);
	int index = -1;
	for(int j=s;j<=e;j++){
		if(in[j] == pre[i]){
			index = j;
			break;
		}
	}

	i++;
	root->left = createTreeFromTrav(in,pre,s,index-1);
	root->right = createTreeFromTrav(in,pre,index+1,e);
	return root;
}

int main(){

	int in[] = {3,2,8,4,1,6,7,5};
	int pre[] = {1,2,3,4,8,5,6,7};
	int n = sizeof(pre)/sizeof(pre[0]);

	node* root = createTreeFromTrav(in,pre,0,n-1);
	bfsInLine(root);

	return 0;
}