#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <string>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef struct {
    int intData;
    char charData;
    string stringData;
    int dataType;
} infotype;

typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

int selectMenu_103012350551();
void createList_103012350551(List &L);
void createNewElement_103012350551(List &L, infotype x);
void insertLast_103012350551(List &L, address P);
void showAll_103012350551(List &L);
address findMin_103012350551(List L);
void showMiddle_103012350551(List &L, int value);
float consonantPercentage_103012350551(List L);
void showFirsttK_103012350551(List L, int k);
address shortestName_103012350551(List L);
void showFirstKNameC_103012350551(List L, int k, char c);

#endif // LIST_H_INCLUDED
