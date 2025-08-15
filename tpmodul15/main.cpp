#include "tree2.h"

int main() {
    cout << "\n===================================================================" << endl;
    adrNode root = NULL;

    // Insert Nodes
    insertNode(root, newNode(8));
    insertNode(root, newNode(9));
    insertNode(root, newNode(12));
    insertNode(root, newNode(13));
    insertNode(root, newNode(15));
    insertNode(root, newNode(17));
    insertNode(root, newNode(7));
    insertNode(root, newNode(6));
    insertNode(root, newNode(4));


    // Perform Deletions and Print
    int nodesToDelete[] = {8, 9, 12, 13, 15, 17, 7, 6, 4};
    printInOrder(root);cout << endl;
    for (int val : nodesToDelete) {
        adrNode toDelete = newNode(val);
        deleteNode(root, toDelete);
        printInOrder(root);
        cout << endl;
    }
    cout << "\n===================================================================" << endl;
    return 0;
}
