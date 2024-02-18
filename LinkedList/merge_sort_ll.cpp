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

node* merge(node* a, node* b){
	//base case
	if(a == NULL){
		return b;
	}
	if(b ==  NULL){
		return a;
	}
	//take a head pointer
	node* c;

	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	} else{
		c = b;
		c->next = merge(a,b->next);
	}

	return c;
}

node* middleElement(node*head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	node*slow = head;
	node*fast = head->next;
	while(fast != NULL && fast->next!=NULL ){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* mergeSort(node* head){
	//base case
	if(head == NULL || head->next == NULL){
		return head;
	}

	//rec case
	node* mid = middleElement(head);

	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	node* c = merge(a,b);
	return c;
}

int main(){


	node* head;
	cin>>head;

	cout<<head<<endl;
	head = mergeSort(head);
	cout<<head<<endl;
	return 0;
}