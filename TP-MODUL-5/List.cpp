#include "list.h"

int selectMenu_103012350551() {
    int choice;
    cout << "====== MENU ======" << endl;
    cout << "1. Add N new data" << endl;
    cout << "2. Show all data" << endl;
    cout << "3. Find minimum integer value" << endl;
    cout << "4. Insert integer in the middle" << endl;
    cout << "5. Show consonant percentage" << endl;
    cout << "6. Show first K characters" << endl;
    cout << "7. Find visitor with shortest name" << endl;
    cout << "8. Show first K names starting with specific character" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    return choice;
}

void createList_103012350551(List &L) {
    first(L) = NULL;
}

void createNewElement_103012350551(List &L, infotype x) {
    address P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    insertLast_103012350551(L, P);
}

void insertLast_103012350551(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void showAll_103012350551(List &L) {
    address P = first(L);
    if (P == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    while (P != NULL) {
        if (info(P).dataType == 0) {
            cout << info(P).intData << " ";  // Int
        } else if (info(P).dataType == 1) {
            cout << info(P).charData << " "; // Char
        } else if (info(P).dataType == 2) {
            cout << info(P).stringData << " "; // String
        }
        P = next(P);
    }
    cout << endl;
}

address findMin_103012350551(List L) {
    address P = first(L);
    if (P == NULL) {
        return NULL;
    }

    address minAddress = NULL;
    while (P != NULL) {
        if (info(P).dataType == 0) {  // Int
            if (minAddress == NULL || info(P).intData < info(minAddress).intData) {
                minAddress = P;
            }
        }
        P = next(P);
    }
    return minAddress;
}

void showMiddle_103012350551(List &L, int value) {
    address newElement = new elmlist;
    newElement->info.intData = value;
    newElement->info.dataType = 0;
    newElement->next = NULL;

    int length = 0;
    address P = first(L);
    while (P != NULL) {
        length++;
        P = next(P);
    }

    if (length == 0) {
        first(L) = newElement;
    } else {
        int mid = length / 2;
        P = first(L);
        for (int i = 0; i < mid - 1; ++i) {
            P = next(P);
        }

        next(newElement) = next(P);
        next(P) = newElement;
    }
}

float consonantPercentage_103012350551(List L) {
    int consonants = 0, vowels = 0;
    address P = first(L);

    while (P != NULL) {
        if (info(P).dataType == 1) {
            char ch = tolower(info(P).charData);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
        P = next(P);
    }

    int total = vowels + consonants;
    return total > 0 ? (consonants * 100.0 / total) : 0.0;
}

void showFirsttK_103012350551(List L, int k) {
    address P = first(L);
    int count = 0;

    while (P != NULL && count < k) {
        if (info(P).dataType == 1) {
            cout << info(P).charData << " ";
            count++;
        }
        P = next(P);
    }
    cout << endl;
}

address shortestName_103012350551(List L) {
    address P = first(L);
    if (P == NULL) return NULL;

    address shortest = NULL;
    while (P != NULL) {
        if (info(P).dataType == 2) {
            if (shortest == NULL || info(P).stringData.length() <= info(shortest).stringData.length()) {
                shortest = P;
            }
        }
        P = next(P);
    }

    return shortest;
}

void showFirstKNameC_103012350551(List L, int k, char c) {
    address P = first(L);
    int count = 0;

    while (P != NULL && count < k) {
        if (info(P).dataType == 2 && info(P).stringData[0] == c) {
            cout << info(P).stringData << " ";
            count++;
        }
        P = next(P);
    }
    cout << endl;
}
