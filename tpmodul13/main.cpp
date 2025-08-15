#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    cout << "\n===================================================================" << endl;
    adrNode root = NULL;
    int x[9] = {5, 3, 9, 10, 4, 7, 1, 8, 6};

    for (int i = 0; i < 9; i++) {
        adrNode new_node = newNode(x[i]);
        root = insertNode(root, new_node);
    }

    for (int i = 0; i < 9; i++) {
        cout << x[i] << " ";
    }

    cout << "\n\nPre Order\t\t  : ";
    printPreOrder(root);

    cout << "\n\nDescendent of Node 9\t  : ";
    printDescendant(root, 9);

    cout << "\n\nSum of BST Info\t\t  : " << sumNode(root);
    cout << "\nNumber of Leaves\t  : " << countLeaves(root);
    cout << "\nHeight of Tree\t\t  : " << heightTree(root) - 1;

    cout << "\n===================================================================" << endl;

    return 0;
}
