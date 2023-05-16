/*
 * Name: Cameron Thompson
 * Coding: final project
 * Purpose:
 */

#ifndef GRAPH_H
#define GRAPH_H
#include "data.h"

class Graph {
public:
    Graph();
    ~Graph();

    bool addVertex(int, string*);
    bool deleteVertex(int);
    bool getVertex(int, Vertex*);

    bool addEdge(int, int);
    bool removeEdge(int, int);
    bool checkEdge(int, int);
    void clearEdges();

    int getNodeCount();
    void printGraph();
    void printMatrix();
    void printVertices();

    void DFS(int);
    void BFS(int);




private:
    //attributes
    vector<vector<int>> edges;
    vector<Vertex*> vertices;
    map<int, int> idPos; 
    int numNodes{0};

    //helper functions
    Vertex *createVertex(int, string*);
    bool verifyData(int, string*);

};







#endif /* GRAPH_H */
