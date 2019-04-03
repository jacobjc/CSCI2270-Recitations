#include <iostream>
#include "doublyLL.h"
using namespace std;

doublyLL::doublyLL(){
}

doublyLL::doublyLL(int nodeID){
	//create head node
	head = createNode(nodeID, nullptr, nullptr);
	tail = head;
}

doublyLL::~doublyLL(){
}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext){
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;

	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID){
	if (head == nullptr){
		//nothing in the list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else {
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

bool doublyLL::deleteNode(int testID){
	Node *curr = head;
	bool test = false;

	while(curr != NULL){
		if(curr->id == testID){
			curr->prev->next = curr->next;
			if(curr->next != NULL){
				curr->next->prev = curr->prev;
			}
			delete[] curr;
			test = true;
		}
		curr = curr->next;
	}
	return test;
}

void doublyLL::print_list(){
	Node *current = new Node;
	current = head;
	while(current->next != NULL){
		cout<<current->id<<endl;
		current = current->next;
	}
	cout<<current->id<<endl;
}

int main(){
	doublyLL newList;
	Node *recentNode;
	int numArr[20] = {1,4,4,4,4,4,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	for(int i=0; i<20; i++){
		newList.insertNodeAtEnd(numArr[i]);
	}
	newList.print_list();

	bool t = newList.deleteNode(4);
	cout<<"Deleted!"<<endl;
	newList.print_list();
}