// Jacob Christiansen Rec. 11 CSCI2270
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct vertex;

struct adjVertex {
	vertex* v;
	int weight;
};

struct vertex {
	string key;
	vector<adjVertex> adjacent;
	bool visited = false;
};

class Graph {
	private:
		//vertices
		vector<vertex> vertices;
		vertex* findVertex(string);
	public:
		//methods for accessing graphs
		Graph();
		~Graph();
		void insertVertex(string);	//identifier of the vertex
		void insertEdge(string,string,int);	//start, end, weight
		void printGraph();
		void DFSpath(string, string);
		void findNodeWithMaximumAdjacent(string);
		void resetVisited();

};

Graph::Graph() {}

Graph::~Graph() {}

void Graph::insertVertex(string value) {
	bool found = false;
	int i=0;
	while (i<vertices.size() && !found) {
		if (vertices[i].key == value) {
			found = true;
		}
		i++;
	}
	if (!found) {
		vertex v;
		v.key = value;
		vertices.push_back(v);
	}
	else {
		cout << "There is already a vertex " << value << " in this graph" << endl;
	}
}

vertex* Graph::findVertex(string value) {
	int i=0;
	while (i<vertices.size()) {
		if (vertices[i].key == value) {
			return &vertices[i];
		}
		i++;
	}
	return nullptr;
}



void Graph::insertEdge(string v1, string v2, int weight) {
	vertex *vStart = findVertex(v1);
	vertex *vEnd = findVertex(v2);
	if (vStart!=nullptr && vEnd!=nullptr) {
		//this code assumes that an edge doesn't exist
		//write some error checking to handle when it does
		adjVertex v1v2Edge;
		v1v2Edge.weight = weight;
		v1v2Edge.v = vEnd;
		vStart->adjacent.push_back(v1v2Edge);
	}
	else {
		if (vStart == nullptr) {
			cout << "no vertex with name " << v1 << " in this graph" << endl;
		}
		if (vEnd == nullptr) {
			cout << "no vertex with name " << v2 << " in this graph" << endl;
		}
	}
}

void Graph::findNodeWithMaximumAdjacent(string start){
	vertex* currentVert = findVertex(start);
	currentVert->visited = true;
	queue<vertex*> vertexQueue;
	vertexQueue.push(currentVert);

	int max =0;
	vertex* maxAdj = currentVert;

	while(vertexQueue.size() != 0){
		vertex* adjVert = vertexQueue.front();
		cout << currentVert->key << " ";
		vertexQueue.pop();

		for(int i=0; i<adjVert->adjacent.size(); i++){
			if(!adjVert->adjacent[i].v->visited){
				adjVert->adjacent[i].v->visited = true;
				vertexQueue.push(adjVert->adjacent[i].v);
			}
			if(max<=adjVert->adjacent[i].v->adjacent.size()){
				max = adjVert->adjacent[i].v->adjacent.size();
				maxAdj = adjVert->adjacent[i].v;
			}
		}
	}
	cout<<endl<<maxAdj->key<<endl;
	resetVisited();
}

void Graph::resetVisited(){
	for(int i=0; i<vertices.size(); i++){
		vertices[i].visited = false;
	}
}


void Graph::DFSpath(string src, string dst) {
	vertex* currentVertex = findVertex(src);
	currentVertex->visited = true;
	stack<vertex*> vertexStack;
	vertexStack.push(currentVertex);
	bool found = false;
	while(!vertexStack.empty() && !found){
		currentVertex = vertexStack.top();
		cout<<currentVertex->key;
		vertexStack.pop();
		for(int i=0; i<currentVertex->adjacent.size(); i++){
			if(currentVertex->key.compare(dst) == 0){
				found = true;
				break;
			}else if(!currentVertex->adjacent[i].v->visited){
				currentVertex->adjacent[i].v->visited = true;
				vertexStack.push(currentVertex->adjacent[i].v);
			}
		}
	}
	cout <<endl;
	resetVisited();
}



int main() {

	Graph myGraph;

	myGraph.insertVertex("A");
	myGraph.insertVertex("B");
	myGraph.insertVertex("C");
	myGraph.insertVertex("D");
	myGraph.insertVertex("E");
	myGraph.insertVertex("F");
	myGraph.insertVertex("G");

	myGraph.insertEdge("A", "B", 0); myGraph.insertEdge("B", "A", 0);
	myGraph.insertEdge("A", "C", 0); myGraph.insertEdge("C", "A", 0);
	myGraph.insertEdge("B", "D", 0); myGraph.insertEdge("D", "B", 0);
	myGraph.insertEdge("C", "D", 0); myGraph.insertEdge("D", "C", 0);
	myGraph.insertEdge("E", "D", 0); myGraph.insertEdge("D", "E", 0);
	myGraph.insertEdge("E", "B", 0); myGraph.insertEdge("B", "E", 0);
	myGraph.insertEdge("E", "G", 0); myGraph.insertEdge("G", "E", 0);
	myGraph.insertEdge("F", "G", 0); myGraph.insertEdge("G", "F", 0);
}