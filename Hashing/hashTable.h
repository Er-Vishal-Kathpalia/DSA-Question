#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class Node{
public:
	string key;
	T data;
	Node<T>* next;
	Node(string key, T val){
		this->key = key;
		this->data = val;
		next = NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class HashTable{

	int table_size;
	int current_size;
	Node<T>** table;

	int hashFn(string key){
		int idx = 0;
		int p=1;
		for(int j=0;j<key.length();j++){
			idx = idx + (key[j]*p)%table_size;
			idx = idx%table_size;
			p = (p*27)%table_size;
		}
		return idx;
	}

	void rehash(){

		Node<T>** oldTable = table;
		int oldTableSize = table_size;
		table_size = 2*table_size;
		table = new Node<T>*[table_size];

		for(int i=0;i<table_size;i++){
			table[i] = NULL;
		}
		current_size = 0;

		//copy data from oldtable to newTable
		for(int i=0;i<oldTableSize;i++){
			
			Node<T>* temp = oldTable[i];
			while(temp!=NULL){
				insert(temp->key, temp->data);
				temp = temp->next;
			}
			
			if(oldTable[i]!=NULL){
				delete oldTable[i];
			}
		}
		delete [] oldTable;
	}

public:

	HashTable(int ts = 7){
		table_size = ts;
		table = new Node<T>*[table_size];
		current_size = 0;
		for(int i=0;i<table_size;i++){
			table[i] = NULL;
		}
	}

	void insert(string key, T value){
		int idx = hashFn(key);
		Node<T>* n = new Node<T>(key, value);
		//insertAtHead
		n->next = table[idx];
		table[idx] = n;
		current_size++;

		//rehashing
		float load_factor = current_size/(1.0*table_size);
		if(load_factor>0.7){
			rehash();
		}
	}

	void print(){
		
		for(int i=0;i<table_size;i++){
			Node<T>* temp = table[i];
			cout<<"Bucket of index "<<i<<"-> ";
			while(temp!=NULL){
				cout<<temp->key<<"-> ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	T* search(string key){
		int idx = hashFn(key);
		Node<T>* temp = table[idx];

		while(temp!=NULL){
			if(temp->key == key){
				return &temp->data;
			}
			temp = temp->next;
		}

		return NULL;
	}

	void erase(string key){
		//....
		int idx = hashFn(key);
		Node<T>* prev = table[idx];
		Node<T>* current = table[idx];
		
		if( current->key == key ){
			delete current;
			table[idx] = NULL;
		}

		current = current->next;
		while(current != NULL){
			if(current->key == key){
				break;
			}
			prev = prev->next;
			current = current->next;
		}
		Node<T>* temp = temp->next;
		delete temp;
		prev->next = temp; 

	}

	T& operator[](string key){
		T* f = search(key);
		if(f == NULL){
			//insert key value as garbage in the hashmap
			T garbage;
			insert(key,garbage);
			f = search(key);
		}
		return *f;
	}


};