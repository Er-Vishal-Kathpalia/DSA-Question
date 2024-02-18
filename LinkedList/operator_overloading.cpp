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

int length(node*head){
	int len = 0;
	while(head!=NULL){
		len++;
		head = head->next;
	}
	return len;
}

void insertAtTail(node*&head,int data){
	if(head == NULL){
		insertAtHead(head,data);
		return;
	}

	node*tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}

	tail->next = new node(data);
	return;
}


void insertAtMiddle(node*&head, int data, int p){

	if(head == NULL || p == 0){
		insertAtHead(head,data);
		return;
	} else if( p > length(head) ){
		insertAtTail(head,data);
	} else{
		int jump = 1;
		node*temp = head;
		while(jump <= p-1){
			temp = temp->next;
			jump++;
		}

		node *n = new node(data);
		n -> next = temp->next;
		temp->next = n;
	}
	return;
}


void deleteAtHead(node*&head){
	if(head == NULL){
		return;
	}

	node*prev = head->next;
	delete head;
	head = prev;
}


void deleteAtTail(node*&head){
	if(head == NULL || head->next == NULL){
		deleteAtHead(head);
		return;
	}
	node*prev = head->next;
	while(prev->next->next!=NULL){
		prev = prev->next;
	}
	node*current = prev->next->next;
	delete current;
	prev->next = NULL;
}

bool searchInLinkedList(node*head, int key){
	while(head!=NULL){
		if(head->data == key){
			return true;
		}
		head = head->next;
	}
	return false;
}

bool searchRecursively(node*head, int key){
	//base case
	if(head == NULL){
		return false;
	}

	if(head->data == key){
		return true;
	} else{
		return searchRecursively(head->next, key);
	}
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


int main(){

	// node* head = input();
	// print(head);

	//Operator Overloading
	node* head;
	node* head2;
	cin>>head>>head2;	
	cout<<head<<head2;
	return 0;
}