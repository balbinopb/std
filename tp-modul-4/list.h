#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef int infotype;
typedef struct elmlist* address;


struct elmlist {
    infotype info;
    address next;
    //elmlist *next;
};

struct List {
    address first;
};

//is same as
/*
elmlist* first  //right
*/
void createList(List &L);
address allocate(infotype x);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(address Prec, address P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(address Prec);
void printInfo(List L);
address searchInfo(List L, infotype x);

#endif
