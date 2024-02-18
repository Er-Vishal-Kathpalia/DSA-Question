#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*next;

	node(int d){
		data = d;
		next = NULL;
	}
};

//Procedural Programming
void insertAtHead(node*&head, int data){

	if(head == NULL){
		head = new node(data);
		return;
	}

	node *temp = new node(data);
	temp->next = head;
	head = temp;
	return;
}


void print(node*head){
	
	while(head!=NULL){
		cout<<head->data<<"-> ";
		head = head->next;
	}
	cout<<endl;
}


//Take input through method
node* input_At_Head(){
	node*head = NULL;
	int d;
	cin>>d;
	while(d != -1){
		insertAtHead(head, d);
		cin>>d;
	}

	return head;
}

//Cout operator overloading
ostream& operator<<(ostream &os,node*head){
	print(head);
	return os;
}

//Cin Operator overloading
istream& operator>>(istream &is, node* &head){
	head = input_At_Head();
	return is;
}

node* kthElement(node*head, int k){
	node*slow = head;
	node*fast = head;

	while(k>0){
		fast = fast->next;
		k--;
	}
	while(fast!=NULL){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main(){

	node* head;
	cin>>head;
	cout<<head<<endl;
	int k;
	cin>>k;
	node* val = kthElement(head,k);
	cout<<"Kth Element is "<<val->data<<endl;
	cout<<head<<endl;

	return 0;
}