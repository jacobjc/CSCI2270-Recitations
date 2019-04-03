// Author: Jacob Christiansen
// Recitation: 105

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct CAR{
	string make;
	string model;
	string year;

	CAR(){
	}
	CAR(string ma, string mo, string yr){
		make = ma;
		model = mo;
		year = yr;
	}
};

void getInfo(string filename, CAR cars[]){
	ifstream fr;
	fr.open(filename);
	if(fr.is_open()){
		string line;
		int index = 0;
		while(getline(fr, line)){

			stringstream ss(line);
			string ma;
			string mo;
			string yr;

			getline(ss, ma);
			getline(ss, mo);
			getline(ss, yr);
			cars[index] = CAR(ma, mo, yr);
			index++;

		}
	}
	else{
		cout<<"Failed to open file!"<<endl;
	}
}

void outInfo(string filename, CAR cars[], int length){
	ofstream fw;
	fw.open(filename);
	if(fw.is_open()){
		for(int i = 0; i<length; i++){
			fw << cars[i].make << "\t" << cars[i].model << "\t" << cars[i].year << endl;
		}
	}
	else{
		cout<<"Failed to open file!"<<endl;
	}
}

int main(int argc, char*argv[]) {
	cout << "STARTING" <<endl;
	int length = atoi(argv[2]);
	CAR arr[length];
	getInfo(argv[1], arr);
	outInfo(argv[3], arr, length);
	cout << "ENDING" << endl;
}