#include "stack.h"

int main()
{
    stack S;
    createStack(S);

    stack tempStack;
    createStack(tempStack);

    int lastDigit;

    cout<<"enter your last digit of NIM ";
    cin>>lastDigit;


    switch (lastDigit%4){
    case 0:
        push(S, 'I');
        push(S, 'F');
        push(S, 'L');
        push(S, 'A');
        push(S, 'B');
        push(S, 'J');
        push(S, 'A');
        push(S, 'Y');
        push(S, 'A');

        printInfo(S);
        cout << endl;

        while (!isEmpty(S)){
            push(tempStack, pop(S));
        }

        for (int i = 0; i <= 4 && !isEmpty(tempStack); i++){
            pop(tempStack);
        }

        while (!isEmpty(tempStack)){
            push(S, pop(tempStack));
        }

        printInfo(S);
        cout << endl;
        break;
    case 1:
        push(S, 'H');
        push(S, 'A');
        push(S, 'L');
        push(S, 'O');
        push(S, 'B');
        push(S, 'A');
        push(S, 'N');
        push(S, 'D');
        push(S, 'U');
        push(S, 'N');
        push(S, 'G');

        printInfo(S);
        cout << endl;

        while (!isEmpty(S)){
            push(tempStack, pop(S));
        }

        for (int i = 0; i <= 3 && !isEmpty(tempStack); i++){
            pop(tempStack);
        }

        while (!isEmpty(tempStack)){
            push(S, pop(tempStack));
        }

        printInfo(S);
        cout << endl;
        break;

    case 2:
        push(S, 'P');
        push(S, 'E');
        push(S, 'R');
        push(S, 'C');
        push(S, 'A');
        push(S, 'Y');
        push(S, 'A');
        push(S, 'D');
        push(S, 'I');
        push(S, 'R');
        push(S, 'I');

        printInfo(S);
        cout << endl;

        while (!isEmpty(S)){
            push(tempStack, pop(S));
        }

        for (int i = 0; i <= 6 && !isEmpty(tempStack); i++){
            pop(tempStack);
        }

        while (!isEmpty(tempStack)){
            push(S, pop(tempStack));
        }

        printInfo(S);
        cout << endl;
        break;

    case 3:
        push(S, 'S');
        push(S, 'T');
        push(S, 'R');
        push(S, 'U');
        push(S, 'K');
        push(S, 'T');
        push(S, 'U');
        push(S, 'R');
        push(S, 'D');
        push(S, 'A');
        push(S, 'T');
        push(S, 'A');

        printInfo(S);
        cout << endl;

        while (!isEmpty(S))
        {
            push(tempStack, pop(S));
        }

        for (int i = 0; i <= 7 && !isEmpty(tempStack); i++)
        {
            pop(tempStack);
        }

        while (!isEmpty(tempStack))
        {
            push(S, pop(tempStack));
        }

        printInfo(S);
        cout << endl;
        break;

    default:
        cout << " " << endl;
    }

    return 0;
}
