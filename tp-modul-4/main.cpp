#include "list.h"

int main() {
    List L;
    createList(L);
    int nim;
    address P;

    cout << "Input NIM (Student ID) digit by digit:" << endl;
    for (int i = 1; i <= 10; i++) {  // Loop for 10 digits
        cout << "Digit " << i << ": ";
        cin >> nim;
        P = allocate(nim);
        insertFirst(L, P);
    }

    cout << "List content: ";
    printInfo(L);

    return 0;
}
