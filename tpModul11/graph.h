#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge {
    char destVertexID;
    int weight;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};


void createVertex(char newVertexID, adrVertex& v);
void initGraph(graph& G);
void addVertex(graph& G, char newVertexID);
void buildGraph(graph& G);




#endif // GRAPH_H_INCLUDED
