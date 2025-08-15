#include "graph.h"

int main() {
    graph G;
    initGraph(G);

    buildGraph(G);

    cout << "\nGraph structure:\n";
    adrVertex temp = G.firstVertex;
    while (temp != nullptr) {
        cout << "Vertex: " << temp->idVertex << endl;
        temp = temp->nextVertex;
    }

    return 0;
}
