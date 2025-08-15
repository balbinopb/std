#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

#define Top(S) (S).top
#define info(S) (S).info

using namespace std;

typedef char infotype;

struct stack {
    infotype info[15];
    int top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
infotype pop(stack &S);
void printInfo(stack S);


#endif // STACK_H_INCLUDED
