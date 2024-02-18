#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;

	ListNode(int data){
		this->val = data;
		next = NULL;
	}

};

//insert at head
void insertAtHead(ListNode* &head, int data){
	if( head == NULL ){
		head = new ListNode(data);
		return;
	}

	ListNode* temp = new ListNode(data);
	temp->next = head;
	head = temp;
	return;
}

void insertAtTail(ListNode* &head, int data){
	if( head == NULL ){
		insertAtHead(head, data);
		return;
	}

	ListNode* prev = head;
	while(prev->next != NULL){
		prev = prev->next;
	}

	ListNode* temp = new ListNode(data);
	prev->next = temp;
	return;
}

ListNode* input(){
	ListNode* head = NULL;
	int data;
	do{
		cin>>data;
		if(data!=-1){
			insertAtTail(head, data);
		}
	} while(data!=-1);
	return head;
}

void print(ListNode* head){

	while(head != NULL){
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<endl;
	return;
}

int lengthOfList(ListNode* head){
	int ans = 0;
	while(head != NULL){
		ans++;
		head= head->next;
	}
	return ans;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
	ListNode* head = NULL;
	while(list1 != NULL && list2 != NULL){
		if(list1->val <= list2->val){
			insertAtTail(head, list1->val);
			list1 = list1->next;
		} else{
			insertAtTail(head, list2->val);
			list2 = list2->next;
		}
	}

	while(list1 != NULL){
		insertAtTail(head, list1->val);
		list1 = list1->next;
	}

	while(list2 != NULL){
		insertAtTail(head, list2->val);
		list2 = list2->next;
	}

	return head;
}


void swapLL(ListNode* &first, ListNode* &second){
	ListNode* temp = second->next;
	second->next = first->next;
	first->next = temp;
}

ListNode* swapPairs(ListNode* head){
	if(head == NULL || head->next == NULL){
		//
	}
	while(head->next->next != NULL){
		swapLL(head, head->next);
		head = head->next->next;
	}
}


int main(){

	ListNode* l1 = input();
	print(l1);
	ListNode* head = swapPairs(l1);
	print(head);
	return 0;
}

/*
1_0x1->2_0x2->3_0x3->4_0x4->5_NULL



*/
