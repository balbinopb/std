#include "tree.h"

void createTree(adrNode &root){
    root = NULL;
} //
bool isEmpty(adrNode root){
    return root == NULL;
} //

adrNode findParent(adrNode root, infotype x){
    if (root == NULL){
        return NULL;
    }
    if ((root->left != NULL && root->left->data == x) || (root->right != NULL && root->right->data == x)){
        return root;
    }
    adrNode p = findParent(root->left, x);
    if (p != NULL){
        return p;
    }
    return findParent(root->right, x);
}//recursive function to find parent of a node

void printInOrder(adrNode root){
    if (root == NULL){
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}//recursive function to print in order
