#include "list.h"

// Create an empty list
void createList(List &L) {
    first(L) = nullptr;
}

// Allocate a new node
address allocate(infotype x) {
    address P = new elmlist();
    next(P) = nullptr; //p->next=nullptr
    return P;
}

// Insert at the beginning of the list
void insertFirst(List &L, address P) {
    next(P) = first(L); //p->next=L.first
    first(L) = P; //L.first=p
}

// Insert at the end of the list
void insertLast(List &L, address P) {
    if (first(L) == nullptr) {
        first(L) = P;
    } else {
        address last = first(L);
        while (next(last) != nullptr) {
            last = next(last);
        }
        next(last) = P;
    }
}

// Insert after a specific node
void insertAfter(address Prec, address P) {
    if (Prec != nullptr) {
        next(P) = next(Prec);// p->next=prec->next
        next(Prec) = P; //prec->next=p
    }
}

// Delete the first element
void deleteFirst(List &L) {
    if (first(L) != nullptr) {
        address P = first(L);
        first(L) = next(P);
        delete P;
    }
}

// Delete the last element
void deleteLast(List &L) {
    if (first(L) != nullptr) {
        if (next(first(L)) == nullptr) {
            delete first(L);
            first(L) = nullptr;
        } else {
            address P = first(L);
            while (next(next(P)) != nullptr) {
                P = next(P);
            }
            delete next(P);
            next(P) = nullptr;
        }
    }
}

// Delete the element after a specific node
void deleteAfter(address Prec) {
    if (Prec != nullptr && next(Prec) != nullptr) {
        address P = next(Prec);
        next(Prec) = next(P);
        delete P;
    }
}

// Print the list
void printInfo(List L) {
    address P = first(L);
    while (P != nullptr) {
        cout << info(P) << "";
        P = next(P);
    }
    cout << endl;
}

// Search for an element in the list
address searchInfo(List L, infotype x) {
    address P = first(L);
    while (P != nullptr && info(P) != x) {
        P = next(P);
    }
    return P;
}
