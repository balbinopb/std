#include "queue_vaksinasi.h"


void createQueue(Queue &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}

bool isEmpty(Queue Q) {
    return Q.head == NULL;
}

address createElemQueue(string nama, int usia, string pekerjaan, int nomor_antrean) {
    address P = new ElemQ;
    P->info.nama = nama;
    P->info.usia = usia;
    P->info.pekerjaan = pekerjaan;
    P->info.prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan") ? "Prioritas Tinggi" : "Normal";
    P->info.nomor_antrean = nomor_antrean;
    P->info.kondisi_darurat = false;
    P->next = NULL;
    return P;
}

void enqueue(Queue &Q, address P) {
    if (isEmpty(Q)) {
        Q.head = P;
        Q.tail = P;
    } else if (P->info.prioritas == "Prioritas Tinggi") {
        address temp = Q.head;
        address prev = NULL;
        while (temp != NULL && temp->info.prioritas == "Prioritas Tinggi") {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) {
            P->next = Q.head;
            Q.head = P;
        } else {
            P->next = prev->next;
            prev->next = P;
        }
        if (P->next == NULL) {
            Q.tail = P;
        }
    } else {
        Q.tail->next = P;
        Q.tail = P;
    }
}


void dequeue(Queue &Q, address &P) {
    if (isEmpty(Q)) {
        P = NULL;
        cout << "Semua warga telah terlayani." << endl;
    } else {
        P = Q.head;
        Q.head = Q.head->next;
        if (Q.head == NULL) {
            Q.tail = NULL;
        }
        P->next = NULL;
    }
}

address front(Queue Q) {
    return Q.head;
}

address back(Queue Q) {
    return Q.tail;
}

int size(Queue Q) {
    int count = 0;
    address temp = Q.head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printInfo(Queue Q) {
    address temp = Q.head;
    cout << "Daftar Antrean:" << endl;
    while (temp != NULL) {
        cout << "Nama: " << temp->info.nama << endl;
        cout << "Usia: " << temp->info.usia << endl;
        cout << "Pekerjaan: " << temp->info.pekerjaan << endl;
        cout << "Prioritas: " << (temp->info.prioritas == "Prioritas Tinggi" ? "Ya" : "Tidak") << endl;
        cout << "Nomor Antrean: " << temp->info.nomor_antrean << endl;
        cout << "------------------------" << endl;
        temp = temp->next;
    }
}


void serveQueue(Queue &Q) {
    address P;
    while (!isEmpty(Q)) {
        dequeue(Q, P);

        // Output format matching the image
        cout << "Melayani warga:" << endl;
        cout << "Nama       : " << P->info.nama << endl;
        cout << "Usia       : " << P->info.usia << endl;
        cout << "Pekerjaan  : " << P->info.pekerjaan << endl;
        cout << "Prioritas  : " << (P->info.prioritas == "Prioritas Tinggi" ? "Ya" : "Tidak") << endl;
        cout << "Vaksinasi berhasil." << endl;
        cout << "------------------------" << endl;

        delete P;
    }
    cout << "Semua warga telah terlayani hari ini." << endl;
}


void reassignQueue(Queue &Q) {
    Queue tempQ;
    createQueue(tempQ);
    address current = Q.head;

    while (current != NULL) {
        address nextElem = current->next;
        current->next = NULL;

        if (current->info.prioritas == "Prioritas Tinggi") {
            enqueue(tempQ, current); // High-priority to the front
        } else {
            enqueue(tempQ, current); // Normal priority follows
        }
        current = nextElem;
    }
    Q = tempQ;
}


void checkWaitingTime(Queue &Q, int waktu_sekarang) {
    address current = Q.head;
    Queue tempQ;
    createQueue(tempQ);

    while (current != NULL) {
        address nextElem = current->next;
        current->next = NULL;

        int wait_time = waktu_sekarang - current->info.waktu_daftar;
        if (wait_time > 120 && current->info.prioritas != "Prioritas Tinggi") {
            current->info.prioritas = "Prioritas Tinggi";
        }
        enqueue(tempQ, current);
        current = nextElem;
    }
    Q = tempQ;
}

void emergencyHandle(Queue &Q, int nomor_antrean) {
    Queue tempQ;
    createQueue(tempQ);
    bool found = false;

    while (!isEmpty(Q)) {
        address P;
        dequeue(Q, P);

        if (P->info.nomor_antrean == nomor_antrean) {
            P->info.kondisi_darurat = true;
            P->info.prioritas = "Prioritas Tinggi";
            enqueue(tempQ, P);
            found = true;
            break;
        } else {
            enqueue(tempQ, P);
        }
    }

    if (found) {
        address emergencyElem = tempQ.head;
        tempQ.head = tempQ.head->next;
        emergencyElem->next = Q.head;
        Q.head = emergencyElem;
    }

    while (!isEmpty(tempQ)) {
        address P;
        dequeue(tempQ, P);
        enqueue(Q, P);
    }

    if (!found) {
        cout << "Warga dengan nomor antrean " << nomor_antrean << " tidak ditemukan." << endl;
    }
}

void updatePriority(Queue &Q) {
    Queue tempQ;
    createQueue(tempQ);

    address current = Q.head;
    while (current != NULL) {
        address nextElem = current->next;
        current->next = NULL;

        if (current->info.kondisi_darurat || current->info.prioritas == "Prioritas Tinggi") {
            enqueue(tempQ, current);
        } else {
            enqueue(Q, current);
        }
        current = nextElem;
    }
    Q = tempQ;
}

address findAndRemove(Queue &Q, int nomor_antrean) {
    if (isEmpty(Q)) return NULL;

    address current = Q.head;
    address previous = NULL;

    while (current != NULL) {
        if (current->info.nomor_antrean == nomor_antrean) {
            if (previous == NULL) {
                Q.head = current->next;
                if (Q.head == NULL) Q.tail = NULL;
            } else {
                previous->next = current->next;
                if (current == Q.tail) Q.tail = previous;
            }
            current->next = NULL;
            return current;
        }
        previous = current;
        current = current->next;
    }
    return NULL;
}

