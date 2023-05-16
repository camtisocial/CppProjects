/*********************
Name: Cameron Thompson
Coding: Final project
Purpose: main file
**********************/

#include "main.h"

int main() {


string tmpstring;
tmpstring = "test";
Vertex newVert;

int ids[10] = {43, 4, 0, 13, 2, 1, -1, 6, 37, 2};
string strings[10] = {"A", "B", "C", "D", "E", "F", "", "G", "H", "I"};
vector<int> randIds{};

srand (time(NULL));

cout << "\n-----------Testing Basic Functions-----------" << endl;
cout << "Creating graph...";
Graph graph;
cout << "done" << endl << endl;
cout << "checking list...\n";
cout << "\tThere are " << graph.getNodeCount() << " nodes." << endl << endl;

//adding VALID vertices and returning them
cout << "Adding Vertices...";
int minVerts{0};
while (minVerts < 6) {
    int randIndex = rand() % 10;
    if(graph.addVertex(ids[randIndex], &strings[randIndex])) {
        randIds.push_back(ids[randIndex]);
        cout << "\n\tAdded ID:" << ids[randIndex] << "  |  Info: " << strings[randIndex];
        minVerts = minVerts+1;
    } else {
        cout << "\n\tFAILED ID:" << ids[randIndex] << "  |  Info: " << strings[randIndex];
    }
}
cout << endl << endl << endl;
cout << "\tThere are " << graph.getNodeCount() << " nodes." << endl << endl << endl;

cout << "Getting vertices...";

//getting vertices
for(int i; i<10 ; i++) {
    int randIndex = rand() % 10;
    if (graph.getVertex(ids[randIndex], &newVert)) {
        cout << "\n\tValid ID:" << newVert.id << "  |  Info: " << newVert.data;
    } else {
        cout << "\n\tINVALID ID:" << newVert.id << "  |  Info: " << newVert.data;
    }
}


cout << "\n\nAdding edges...\n";

graph.addEdge(randIds[0], randIds[1]);
graph.addEdge(randIds[0], randIds[2]);
graph.addEdge(randIds[1], randIds[3]);
graph.addEdge(randIds[1], randIds[4]);
graph.addEdge(randIds[2], randIds[5]);
graph.printGraph();

cout << "\n\n";

cout << "-----------Traversals-----------" << endl << endl;
graph.printVertices();
cout << "\n\n";
cout << "\t---Adjacency matrix---\n";
graph.printMatrix();
cout << "\n";
cout << "\t---Graph---\n";
graph.printGraph();

cout << "\nDepth first search...\n";
graph.DFS(1);


cout << "\nBreadth first search...\n";
graph.BFS(1);


cout << "\n-----------Deleting and rearranging edges/nodes-----------" << endl;
cout << "\nDeleting second vertex from graph...\n\n";
graph.deleteVertex(2);
graph.printVertices();
cout << "\n\n";
cout << "\t---Adjacency matrix---\n";
graph.printMatrix();
cout << "\n\n";
cout << "\t---Graph---\n";
graph.printGraph();
cout << "\n\n";


cout << "Clearing edges...\n\n";

graph.clearEdges();

graph.printVertices();
cout << "\n\n";
cout << "\t---Adjacency matrix---\n";
graph.printMatrix();
cout << "\n\n";
cout << "\t---Graph---\n";
graph.printGraph();
cout << "\n\n";

	return 0;
}

