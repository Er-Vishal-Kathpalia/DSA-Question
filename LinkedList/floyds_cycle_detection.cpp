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

bool cycleDetection(node* head){
	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL){
		
		fast = fast->next->next;
		slow = slow->next;

		if(slow == fast){
			return true;
		}
	}
	return false;
}

int main(){

	node* head;
	cin>>head;

	bool ans = cycleDetection(head);
	if(ans){
		cout<<"Cycle detected"<<endl;
	} else{
		cout<<"No Cycle detected"<<endl;
	}

	return 0;
}