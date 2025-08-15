#include "DLL.h"

bool isEmpty(List L) {
    return L.first == NULL && L.last == NULL;
}

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

bool createNewElmt(infotype X, address &P) {
    P = new elmList;
    if (P != NULL) {
        P->info = X;
        P->prev = NULL;
        P->next = NULL;
        return true;
    } else {
        return false;
    }
}

void insertFirst(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = next(Prec);
        P->prev = Prec;
        if (next(Prec) != NULL) {
            Prec->next->prev= P;
        } else {
            L.last = P;
        }
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        insertFirst(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (!isEmpty(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = next(L.first);
            L.first->prev = NULL;
        }
        P->next = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}


void deleteLast(List &L, address &P) {
    if (!isEmpty(L)) {
        P = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = prev(L.last);
            L.last->next = NULL;
        }
        P->prev = NULL;
    }
}

void concat(List L1, List L2, List &L3) {
    createList(L3);
    if (!isEmpty(L1)) L3.first = L1.first;
    if (!isEmpty(L2)) {
        if (L3.first != NULL) L1.last->next = L3.first;
        else L3.first = L3.first;
        L3.first->prev = L1.first;
    }
    L3.last = (!isEmpty(L2)) ? L2.last : L1.last;
}

address findLagu(string Judul, List L) {
    address P = L.first;
    while (P != NULL) {
        if ((P->info) == Judul){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void removeLagu(string Judul, List &L) {
    address P = findLagu(Judul, L);
    if (P != NULL) {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        delete P;
    }
}

