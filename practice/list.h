#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct node* address;

struct node {
    int num;
    address next;
};

void createList(address &first);
address allocate(int x);
void insertFirst(address &first, address p);
void insertLast(address &first, address p);
void deleteLast(address &first);
void deleteFirst(address &first);
void printInfo(address first);
bool searchElm(address first, int elm);
bool duplicate(address first);

#endif // LIST_H_INCLUDED
