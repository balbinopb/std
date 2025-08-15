#include "tree2.h"

adrNode newNode(infotype x) {
    adrNode p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(adrNode &root, adrNode p) {
    if (root == NULL) {
        root = p;
    } else if (p->info < root->info) {
        insertNode(root->left, p);
    } else {
        insertNode(root->right, p);
    }
}

void deleteNode(adrNode &root, adrNode &p) {
    if (root == NULL) return;
    if (p->info < root->info) {
        deleteNode(root->left, p);
    } else if (p->info > root->info) {
        deleteNode(root->right, p);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            adrNode temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            adrNode temp = root;
            root = root->left;
            delete temp;
        } else {
            adrNode temp = findMin(root->right);
            root->info = temp->info;
            deleteNode(root->right, temp);
        }
    }
}

adrNode findMin(adrNode root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void printInOrder(adrNode root) {
    if (root != NULL) {
        printInOrder(root->left);
        std::cout << root->info << " ";
        printInOrder(root->right);
    }
}
