#include "mutil_linkedList.h"

void createListJadwal(ListJadwal &L){

    L.first=NULL;

}

adr_jadwalP createElemenJadwal (infotype x){

        adr_jadwalP P=new elementJadwal();
        P->info=x;
        P->next=NULL;
        return P;

}

void InsertLastJ(ListJadwal &L, adr_jadwalP P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adr_jadwalP last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = P;
    }
}

/** \brief
 string kode;
    string jenis;
    string tanggal;
    string waktu;
    string asal;
    string tujuan;
    int kapasitas;
 *
 */



void ShowJadwal (ListJadwal L){
    if (L.first==NULL){
        cout<<"List is empty"<<endl;
    }else {
        adr_jadwalP P=L.first;
        while (P!=NULL){
            cout<<"kode: "<<P->info.kode<<endl;
            cout<<"jenis: "<<P->info.jenis<<endl;
            cout<<"tanggal: "<<P->info.tanggal<<endl;
            cout<<"waktu: "<<P->info.waktu<<endl;
            cout<<"asal: "<<P->info.asal<<endl;
            cout<<"tujuan: "<<P->info.tujuan<<endl;
            cout<<"kapasitas: "<<P->info.kapasitas<<endl;
            cout << "----------------------" << endl;
            P=P->next;
        }
    }



}

void DeleteFirstJ(ListJadwal &L,adr_jadwalP &P){

    if (L.first!=NULL){
        P=L.first;
        L.first=P->next;
        delete P;
    }

}

bool SearchJ (ListJadwal L,string dari,string ke,string tanggal){

    adr_jadwalP P=L.first;
    while(P!=NULL){
        if (P->info.asal==dari && P->info.tujuan==ke && P->info.tanggal==tanggal){
            cout<<"kode: "<<P->info.kode<<endl;
            cout<<"jenis: "<<P->info.jenis<<endl;
            cout<<"tanggal: "<<P->info.tanggal<<endl;
            cout<<"waktu: "<<P->info.waktu<<endl;
            cout<<"asal: "<<P->info.asal<<endl;
            cout<<"tujuan: "<<P->info.tujuan<<endl;
            cout<<"kapasitas: "<<P->info.kapasitas<<endl;
            cout << "----------------------" << endl;
        }
        P=P->next;

    }


}
