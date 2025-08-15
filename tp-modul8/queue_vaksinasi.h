#ifndef QUEUE_VAKSINASI_H_INCLUDED
#define QUEUE_VAKSINASI_H_INCLUDED

#include <iostream>
#include <string>
// #define L.head L.head
// #define last(L) L.tail
// #define next(P) P->next
// #define info(P) P->info

using namespace std;

struct Infotype {
    string nama;
    int usia;
    string pekerjaan;
    string prioritas;
    int nomor_antrean;
    int waktu_daftar;
    bool kondisi_darurat;
};
typedef struct ElemQ *address;
struct ElemQ {
    Infotype info;
    address next;
};
struct Queue {
    address head;
    address tail;
};
void createQueue(Queue &Q);
bool isEmpty(Queue Q);
address createElemQueue(string nama, int usia, string pekerjaan, int nomor_antrean);
void enqueue(Queue &Q, address P);
void dequeue(Queue &Q, address &P);
address front(Queue Q);
address back(Queue Q);
int size(Queue Q);
void printInfo(Queue Q);
void serveQueue(Queue &Q);
void reassignQueue(Queue &Q);
void checkWaitingTime(Queue &Q, int waktu_sekarang);
void emergencyHandle(Queue &Q, int nomor_antrean);
void updatePriority(Queue &Q);
address findAndRemove(Queue &Q, int nomor_antrean);

#endif // QUEUE_VAKSINASI_H_INCLUDED
