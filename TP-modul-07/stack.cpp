#include "stack.h"

void createStack(stack &S){

    Top(S)=0;

}

bool isEmpty(stack S){

    if (Top(S)==0){
        return true;
    }
    return false;

}

bool isFull(stack S){

    if (Top(S)==15){
        return true;
    }
    return false;
}

void push(stack &S, infotype x){

    if (!isFull(S)){
        Top(S)=Top(S)+1;
        info(S)[Top(S)]=x;
    }

}

infotype pop(stack &S){

    infotype x;
    x=info(S)[Top(S)];
    Top(S)--;
    return x;


}



void printInfo(stack S){

    for (int i=0; i<=Top(S); i++){

        cout<<info(S)[i]<<" ";

    }

}




