// Author: Jacob Christiansen
// Class: CSCI 2270
// Course Instructor: Rhonda Hoenigman
// Recitation: 105

#include <iostream>
using namespace std;

struct Node{
	int id;
	Node *next;
};

Node* searchLL(Node *head, int target);
Node* insertHead(Node* head, int newItem);

void insertAfter(Node* prevNode, int newItem);
void insertAfterEven(Node* prevNode, int newItem);

Node * searchLL(Node *head, int target){
	Node *current;
	current = head;
	while(current!=nullptr){
		if(current->id == target)
			return current;
		else
			current = current->next;
	}
	return nullptr;
}


Node* insertHead(Node* head, int newItem){
	//Create new node and temp pointer
	Node* tmp = new Node;
	tmp->id = newItem;
	//Link new node with "old" head
	tmp->next = head;
	//Return head ptr
	return tmp;
}

void insertAfter(Node* prevNode, int newItem){
	//Create new Node
	Node* temp= new Node;
	temp->id = newItem;
	//Link new node with previous node
	temp->next = prevNode->next;
	//Link prevNode with new node
	prevNode->next=temp;
	temp=nullptr;
}

void insertAfterEven(Node* prevNode, int newItem){
	//Create new Node
	Node* temp= new Node;
	temp->id = newItem;
	int index =0;
	while(prevNode->id%2 !=0){
		prevNode = prevNode->next;
		index++;
		if(index == 5){
			cout<<"No even link ID found!"<<endl;
			return;
		}
	}
	temp->next = prevNode->next;
	prevNode->next = temp;

	temp = nullptr;
}


int main(){
	int a[] = {1,2,3,4};
	Node *head, *current, *tmp;
	head = new Node;
	current = new Node;

	head->id = a[0];
	head->next = nullptr;
	current = head;

	int i = 1;
	while(i<4){
		// create new node; use tmp to point to it
		tmp = new Node;
		// populate the payload of tmp with i-th array element
		tmp->id = a[i];
		// in case it's the last element, set current node to indicate end
		tmp->next = nullptr;
		// at this point "current" is still pointing to previous element
		// (could be head)
		// connect the previous element such that it is pointing to the newly created one (tmp)
		current->next = tmp; 
		// move forward. Make current point to the new element
		current = tmp;
		i++;

	}

	Node *targetAddress = searchLL(head, 2);
	cout << "targetAddress " << targetAddress << endl;

	cout << "Traverse and print the LL: " << endl;
	current = head;

	insertAfterEven(current, -1);
	
	while(current != nullptr){
		cout << "ID is " << current->id;
		cout << " on link: " << current << endl;
		current = current->next;
	}

	return 0;
}