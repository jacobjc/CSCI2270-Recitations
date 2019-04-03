#include "Graph.h"
#include "Graph.cpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
    Graph* myGraph = new Graph();
    ifstream fr;
    fr.open(argv[1]);
    string line = "";

    getline(fr, line);
    stringstream ss(line);
    string line2 = "";
    vector <string> cities;

    getline(ss, line2, ' ');
    while(getline(ss, line2, ' ')){
        myGraph->addVertex(line2);
        cities.push_back(line2);
    }

    while(getline(fr, line)){
        stringstream ss(line);
        string line2 = "";
        string currCity = "";

        getline(ss, currCity, ' ');
        int index = 0;
        while(getline(ss, line2, ' ')){
            if(stoi(line2) > 0){
                myGraph->addEdge(currCity, cities[index], index);
            }
            index++;
        }
    }
    myGraph->displayEdges();

    return 0;
}