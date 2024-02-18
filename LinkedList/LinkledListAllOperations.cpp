#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};

//insert at head
void insertAtHead(Node* &head, int data){
	if( head == NULL ){
		head = new Node(data);
		return;
	}

	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
	return;
}

void insertAtTail(Node* &head, int data){
	if( head == NULL ){
		insertAtHead(head, data);
		return;
	}

	Node* prev = head;
	while(prev->next != NULL){
		prev = prev->next;
	}

	Node* temp = new Node(data);
	prev->next = temp;
	return;
}

int lengthOfList(Node* head){
	int ans = 0;
	while(head != NULL){
		ans++;
		head = head->next;
	}
	return ans;
}

void insertAtMiddle(Node* &head, int data, int idx){
	int len = lengthOfList(head);
	if( head == NULL || idx == 0 ){
		insertAtHead(head, data);
	} else if( len < idx ){
		insertAtTail(head, data);
	} else{
		Node* prev = head;
		int i=1;
		while(i < idx-1){
			prev = prev->next;
			i++;
		}
		Node* temp = new Node(data);
		temp->next = prev->next;
		prev->next = temp;
	}
	return;
}

void deleteAtHead(Node* &head){
	if(head == NULL){
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	return;
}

void deleteAtTail(Node* &head){
	if(head == NULL || head->next == NULL){
		deleteAtHead(head);
		return;
	}

	Node* prev = head->next;
	while(prev->next->next != NULL){
		prev = prev->next;
	}

	Node* curr = prev->next;
	prev->next = curr->next;
	delete curr;
	return;
}

void deleteAtMiddle(Node* &head, int p){
	if(head == NULL || p == 0){
		deleteAtHead(head);
		return;
	} 
	if( p >= lengthOfList(head)-1 ){
		deleteAtTail(head);
		return;
	}
	Node* prev = head;
	int jump = 1;
	while(jump<p){
		prev = prev->next;
		jump++;
	}
	Node* curr = prev->next;
	prev->next = curr->next;
	delete curr;
	return;
}


void print(Node* head){

	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
	return;
}


Node* input(){
	Node* head = NULL;
	int data;
	do{
		cin>>data;
		if(data!=-1){
			insertAtTail(head, data);
		}
	} while(data!=-1);
	return head;
}

ostream& operator<<(ostream &os, Node* head){
	print(head);
	return os;
}

istream& operator>>(istream &is, Node* &head){
	head = input();
	return is;
}


int main(){

	Node* head = NULL;
	cin>>head;
	cout<<head;
	deleteAtMiddle(head, 3);

	print(head);

	// Node* head = NULL;
	// insertAtHead(head, 10);
	// insertAtHead(head, 20);
	// insertAtHead(head, 30);
	// insertAtHead(head, 40);
	// insertAtHead(head, 50);

	// insertAtTail(head, 100);
	// insertAtTail(head, 200);
	// insertAtTail(head, 300);

	// insertAtMiddle(head, 1000, 8);

	// deleteAtHead(head);
	// deleteAtTail(head);
	// deleteAtTail(head);
	// print(head);
	return 0;
}