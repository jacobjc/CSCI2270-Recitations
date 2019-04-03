#include <iostream>
#include "BST.cpp"  

int main(){
 	BST *myTree = new BST(10);
 	myTree->insertNode(16);
 	myTree->insertNode(4);
 	myTree->insertNode(11);
 	myTree->insertNode(2);
 	myTree->printTree();
 	cout<<endl;
 	cout << myTree->searchKey(9) << endl;
 	cout << myTree->searchKey(10) << endl;
 }