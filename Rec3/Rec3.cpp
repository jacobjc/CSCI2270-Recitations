// Author: Jacob Christiansen
// Recitation: 105

#include <iostream>
#include <fstream>
using namespace std;

void resize(int *&oldArray, int *capacity){
	// cout <<  "resize has run" << endl;
	int newCapacity = *capacity * 2;
	int *newArray = new int[newCapacity];
	for(int i=0; i<(*capacity); i++){
		// cout<<"setting newArray["<<i<<"] = oldArray["<<i<<"]"<< endl;
		newArray[i] = oldArray[i];
	}
	delete[] oldArray;
	oldArray = newArray;
	*capacity = newCapacity;
}

int main(int argc, char *argv[]){
	if(argc != 2){
		return 1;
	}

	ifstream fr;
	string filename = argv[1];
	fr.open(filename);
	int capacity = 10;
	int *arr = new int[capacity];
	
	if(fr.is_open()){
	int index = 0;
	string line;
		while(getline(fr, line)){
			// cout << line <<endl;
			if(index == capacity){
				resize(arr, &capacity);
			}
		arr[index++] = stoi(line);
		}
	}
	else{
		cout<<"File didn't open!"<<endl;
	}

	cout << "Array Size is: "<< capacity << endl << "Array Output: " << endl;
	for(int i=0; i< 50; i++){
		cout<< arr[i] << endl;
	}
}