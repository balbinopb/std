#include "list.h"

void createList(address &first) {
    first = NULL;
}

node* allocate(int x) {
    address newNode = new node();
    newNode->num = x;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(address &first, address p) {
    p->next = first;
    first = p;
}

void insertLast(address &first, address p) {
    if (first == NULL) {
        first = p;
    } else {
        address last = first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

void deleteLast(address &first) {
    if (first == NULL) return;
    if (first->next == NULL) {
        delete first;
        first = NULL;
        return;
    }
    address beforeLast = first;
    while (beforeLast->next->next != NULL) {
        beforeLast = beforeLast->next;
    }
    address last = beforeLast->next;
    beforeLast->next = NULL;
    delete last;
}

void deleteFirst(address &first) {
    if (first != NULL) {
        address tmp = first;
        first = first->next;
        tmp->next = NULL;
        delete tmp;
    }
}

void printInfo(address first) {
    address tmp = first;
    while (tmp != NULL) {
        cout << tmp->num <<" -> ";
        tmp = tmp->next;
    }
    cout<<endl;
}

bool searchElm(address first, int elm) {
    address tmp=first;

    while(tmp!=NULL){
        if(tmp->num==elm){
            return true;
        }
        tmp=tmp->next;
    }
    return false;


}
bool duplicate(address first) {

    address tmp=first;

    while(tmp!=NULL){
        address runner = tmp->next;
        while(runner!=NULL){
            if(tmp->num==runner->num){
                return true;
            }
            runner=runner->next;
        }
        tmp=tmp->next;
    }
    return false;


}
