#include <iostream>
#include"list.h"


int main()
{
    int n;
    cin>>n;
    address first;
    createList(first);

    insertFirst(first, allocate(10));
    insertFirst(first, allocate(50));
    insertLast(first, allocate(20));
    insertLast(first, allocate(30));
    insertLast(first, allocate(40));
    insertLast(first, allocate(50));
    insertLast(first, allocate(50));

    cout<<"\nBEFORE DELETE"<<endl;
    printInfo(first);

    deleteLast(first);
    cout<<"\nAFTER DELETE"<<endl;
    printInfo(first);

    if(searchElm(first,50)){
        cout<<"\nELEMENT KETEMU"<<endl;
    }else{
        cout<<"\nELEMENT TIDAK KETEMU"<<endl;
    }



    if(duplicate(first)){
        cout<<"\nELEMENT DUPLICATE"<<endl;
    }else{
        cout<<"\nELEMENT TIDAK ADA DUPLICATE"<<endl;
    }

    return 0;
}
