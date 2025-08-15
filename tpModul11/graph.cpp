#include "graph.h"

void createVertex(char newVertexID, adrVertex& v) {
    v = new vertex;
    v->idVertex = newVertexID;
    v->nextVertex = nullptr;
    v->firstEdge = nullptr;
}

void initGraph(graph& G) {
    G.firstVertex = nullptr;
}

void addVertex(graph& G, char newVertexID) {
    adrVertex temp = G.firstVertex;
    while (temp != nullptr) {
        if (temp->idVertex == newVertexID) {
            cout << "Vertex " << newVertexID << " already exists.\n";
            return;
        }
        temp = temp->nextVertex;
    }


    adrVertex newVertex;
    createVertex(newVertexID, newVertex);


    if (G.firstVertex == nullptr) {
        G.firstVertex = newVertex;
    } else {
        temp = G.firstVertex;
        while (temp->nextVertex != nullptr) {
            temp = temp->nextVertex;
        }
        temp->nextVertex = newVertex;
    }

    cout << "Vertex " << newVertexID << " added.\n";
}

void buildGraph(graph& G) {
    char inputChar;
    cout << "Enter vertex IDs\n";

    while (true) {
        cin >> inputChar;

        if (!isalpha(inputChar)) {
            cout << "Stopping input. Non-letter character detected.\n";
            break;
        }

        addVertex(G, inputChar);
    }
}

void disconnectVertex(adrVertex& v) {
    adrEdge tempEdge = v->firstEdge;
    while (tempEdge != nullptr) {
        adrEdge delEdge = tempEdge;
        tempEdge = tempEdge->nextEdge;
        delete delEdge;
    }
    v->firstEdge = nullptr;
}

void disconnectGraph(graph& G) {
    adrVertex tempVertex = G.firstVertex;
    while (tempVertex != nullptr) {
        adrVertex delVertex = tempVertex;
        tempVertex = tempVertex->nextVertex;
        disconnectVertex(delVertex);
        delete delVertex;
    }
    G.firstVertex = nullptr;
}

void addEdge
