#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

typedef struct Node *address;
typedef int infotype;

struct Node {
    infotype info;
    address left;
    address right;
};

typedef Node *adrNode;

adrNode newNode(infotype x);
void insertNode(adrNode &root, adrNode p);
void deleteNode(adrNode &root, adrNode &p);
void printInOrder(adrNode root);
adrNode findMin(adrNode root);

#endif
