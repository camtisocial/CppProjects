/*********************
Name: Cameron Thompson
Coding: final project
Purpose: 
**********************/

#include "graph.h"

Graph::Graph() {
};

Graph::~Graph() {
    for(int i{0}; i<numNodes; i++) {
        delete vertices[i];
    }
};


/************** PRIVATE FUNCTIONS *************/
Vertex *Graph::createVertex(int id, string *info) {
    Vertex *newVert = new Vertex;
    newVert->id = id;
    newVert->data = *info;
    return newVert;
}

bool Graph::verifyData(int id, string *info) {
    bool isValid = true;
    if(idPos.count(id)>0 || *info=="" || id<1) {
        isValid = false;
    }
    return isValid;
}

/************** PUBLIC FUNCTIONS *************/

void Graph::printMatrix() {
    for(int i{0}; i<edges.size(); i++) {
        std::cout << "\t";
        for(int j{0}; j<edges.size(); j++) {
            std::cout << edges[i][j] << " "; 
        }
        std::cout << std::endl;
    }
}

void Graph::printVertices() {
    std::cout << "\tIDs: ";
    for(int i{0}; i<vertices.size(); i++) {
        std::cout << vertices[i]->id << ", ";
    }
}

void Graph::printGraph() {
    bool noEdges = true;
    for(int i{0}; i<numNodes; i++) {
        noEdges = true;
        for(int j{0}; j<numNodes; j++) {
            if(edges[i][j] == 1) {
                std::cout << "\t" << vertices[i]->id << "->" << vertices[j]->id << "\n";
                noEdges = false;
            }
        }
        if(noEdges) {
            std::cout << "\t" << vertices[i]->id << "\n";
        }
    }
}

bool Graph::addVertex(int id, string *info) {
    bool vertexAdded = false;
    //allocating and adding vertex to list of vertices
    if(verifyData(id, info)) {
        idPos[id] = numNodes;
        int position = idPos[id];
        numNodes++;
        vertices.push_back(createVertex(id, info));
        edges.resize(numNodes, vector<int>(numNodes, 0));
        vertexAdded = true;
    }
    return vertexAdded;
}

bool Graph::deleteVertex(int id) {
    bool deleted = false;
    int position = idPos[id];
    //std::cout << "position to be deleted = " << position << std::endl;
    if(idPos.count(id) > 0) {
        //shifting columns left
        for(int i{0}; i<edges.size(); i++) {
            for(int j{position}; j<edges.size(); j++) {
                edges[i][j] = edges[i][j+1];
            }
        }
        //shifting rows up 
        for(int p{position}; p<edges.size()-1; p++) {
            edges[p].swap(edges[p+1]);
        }
        numNodes--;
        edges.resize(numNodes, vector<int>(numNodes));
        vertices.erase(vertices.begin()+position);
        deleted = true;
    }
    return deleted;
}

bool Graph::addEdge(int id1, int id2) {
    bool edgeAdded = false;
    if(nodeExists(id1) && nodeExists(id2)) {
        edges[idPos[id1]][idPos[id2]] = 1;
        edges[idPos[id2]][idPos[id1]] = 1;
        edgeAdded = true;
    }
    return edgeAdded;
}

bool Graph::checkEdge(int id1, int id2) {
    bool edgeExists = false;
    if(edges[idPos[id1]][idPos[id2]] == 1) {
        edgeExists = true;
    }
    return edgeExists;
}

bool Graph::removeEdge(int id1, int id2) {
    bool edgeRemoved = false;
    if(nodeExists(id1) && nodeExists(id2)) {
        edges[idPos[id1]][idPos[id2]] = 0;
        edges[idPos[id2]][idPos[id1]] = 0;
        edgeRemoved = true;
    }
    return edgeRemoved;
}

void Graph::clearEdges() {
    for(int i{}; i<numNodes; i++) {
        for(int j{}; j<numNodes; j++) {
            edges[i][j] = 0;
        }
    }
}

bool Graph::getVertex(int id, Vertex *vert) {
    bool found = false;
    if(idPos.count(id) > 0) {
        vert->id = vertices[idPos[id]]->id;
        vert->data = vertices[idPos[id]]->data;
        found = true;
    } else {
        vert->id = -1; 
        vert->data = "";
    }

    return found;
}


bool Graph::nodeExists(int id) {
    return idPos.count(id) > 0;
}

int Graph::getNodeCount() {
    return numNodes;
}

void Graph::DFS(int id) {
    static vector<int> visited;
    int position = idPos[id];

    visited.push_back(vertices[position]->id); 
    std::cout << "\tVisited: " << vertices[position]->id << std::endl;

    for(int i{}; i<numNodes; i++) {
        if(edges[position][i] == 1) {
            if(!(std::count(visited.begin(), visited.end(), vertices[i]->id))) {
                DFS(vertices[i]->id);
            }
        }
    }
}


void Graph::BFS(int id) {
    vector<int> visited;
    vector<int> q;
    int position = idPos[id];

    visited.push_back(vertices[position]->id);
    q.push_back(vertices[position]->id);

    while (!q.empty()) {
        std::cout << "\tVisited: " << q.front() << std::endl;
        int position = idPos[q.front()];
        q.erase(q.begin());

        for(int i{}; i<numNodes; i++) {
            if(edges[position][i] == 1) {
                if(!(std::count(visited.begin(), visited.end(), vertices[i]->id))) {
                    visited.push_back(vertices[i]->id);
                    q.push_back(vertices[i]->id);
                }
            }
        }
    }
}










