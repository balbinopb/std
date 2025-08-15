#include "Tree.h"

adrNode newNode(infotype x) {
    adrNode new_node = new node;
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

adrNode findNode(adrNode root, infotype x) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == x) {
        return root;
    }
    adrNode p = findNode(root->left, x);
    if (p != NULL) {
        return p;
    }
    return findNode(root->right, x);
}

adrNode insertNode(adrNode root, adrNode new_node) {
    if (root == NULL) {
        return new_node;
    }
    if (new_node->data < root->data) {
        root->left = insertNode(root->left, new_node);
    } else {
        root->right = insertNode(root->right, new_node);
    }
    return root;
}

void printPreOrder(adrNode root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

/*
void printLeaf(adrNode root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    printLeaf(root->left);
    printLeaf(root->right);
}


*/

void printDescendant(adrNode root, infotype x) {
    adrNode p = findNode(root, x);
    if (p == NULL) {
        cout << "Node not found" << endl;
        return;
    }
   // cout << p->data << " ";
    printPreOrder(p->left);
    printPreOrder(p->right);
}

int sumNode(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumNode(root->left) + sumNode(root->right);
}

/*

int countNode(adrNode root){
    if (root == NULL){
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

*/


int countLeaves(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}


/*
int countInternal(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 0;
    }
    //return sumNode(root) - countLeaves(root);
    return 1 + countInternal(root->left) + countInternal(root->right);
}
*/


/*
void printLevel(adrNode root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        cout << root->data << " ";
    } else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
*/

/*
void printGivenLevel(adrNode root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        cout << root->data << " ";
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}
*/



int heightTree(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = heightTree(root->left);
    int right_height = heightTree(root->right);
    return max(left_height, right_height) + 1;
}
