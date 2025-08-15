#ifndef MUTIL_LINKEDLIST_H_INCLUDED
#define MUTIL_LINKEDLIST_H_INCLUDED

#include<iostream>

using namespace std;

struct jadwalPenerbangan{
    string kode;
    string jenis;
    string tanggal;
    string waktu;
    string asal;
    string tujuan;
    int kapasitas;
};

typedef struct elementJadwal* adr_jadwalP;
typedef jadwalPenerbangan infotype;

struct elementJadwal{

    infotype info;
    adr_jadwalP next;

};


struct ListJadwal{

    adr_jadwalP first;

};

void createListJadwal(ListJadwal &L) ;
adr_jadwalP createElemenJadwal (infotype x) ;
void InsertLastJ(ListJadwal &L, adr_jadwalP P) ;
void ShowJadwal (ListJadwal L);
void DeleteFirstJ(ListJadwal &L,adr_jadwalP &P);
bool SearchJ (ListJadwal L,string dari,string ke,string tanggal);


#endif // MUTIL_LINKEDLIST_H_INCLUDED
