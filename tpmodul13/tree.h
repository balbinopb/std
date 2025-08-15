#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct node *address;

struct node{
    int data;
    address left;
    address right;
};

typedef node *adrNode;

typedef int infotype;


adrNode newNode(infotype x);
// void createTree(adrNode &root); //
// bool isEmpty(adrNode root); //


adrNode findNode(adrNode root, infotype x);
// adrNode findParent(adrNode root, infotype x);//
adrNode findMax(adrNode root);
adrNode findMin(adrNode root);//
// adrNode deleteNode(adrNode root, infotype x);//

void printPreOrder(adrNode root);

void printDescendant(adrNode root, infotype x);
// void printAncestor(adrNode root, infotype x);//
// void printLeaf(adrNode root);//
// void printInternal(adrNode root);//
// void printLevel(adrNode root, int level);//
// void printGivenLevel(adrNode root, int level);//

int sumNode(adrNode root);
// int countSibling(adrNode root, infotype x);//
// int countCousin(adrNode root, infotype x);//
//int countNode(adrNode root);//
int countLeaves(adrNode root);
//int countInternal(adrNode root);//
int heightTree(adrNode root);

adrNode insertNode(adrNode root, adrNode new_node);


#endif // TREE_H_INCLUDED
