#include "mutil_linkedList.h"

int main()
{
    ListJadwal L;
    createListJadwal(L);

    infotype jadwal1 = {"GA456", "Internasional", "2024-12-05", "09:45", "Jakarta", "Singapore", 180};
    infotype jadwal2 = {"SJ789", "Domestik", "2024-12-07", "13:20", "Surabaya", "Bali", 200};
    infotype jadwal3 = {"ID101", "Domestik", "2024-12-10", "06:15", "Medan", "Jakarta", 160};
    infotype jadwal4 = {"QZ234", "Internasional", "2024-12-12", "22:00", "Bali", "Kuala Lumpur", 150};
    infotype jadwal5 = {"JT567", "Domestik", "2024-12-15", "18:30", "Makassar", "Surabaya", 140};
    infotype jadwal6 = {"GA890", "Internasional", "2024-12-20", "11:50", "Jakarta", "Sydney", 220};
    infotype jadwal7 = {"SJ321", "Domestik", "2024-12-25", "16:45", "Yogyakarta", "Jakarta", 170};
    infotype jadwal8 = {"ID654", "Domestik", "2024-12-28", "07:30", "Bandung", "Jakarta", 180};
    infotype jadwal9 = {"QZ987", "Internasional", "2024-12-30", "20:15", "Jakarta", "Bangkok", 200};
    infotype jadwal10 = {"JT112", "Domestik", "2025-01-02", "10:10", "Semarang", "Denpasar", 150};
    infotype jadwal11 = {"ID655", "Domestik", "2024-12-28", "10:30", "Bandung", "Jakarta", 180};

    // Insert data into the list
    InsertLastJ(L, createElemenJadwal(jadwal1));
    InsertLastJ(L, createElemenJadwal(jadwal2));
    InsertLastJ(L, createElemenJadwal(jadwal3));
    InsertLastJ(L, createElemenJadwal(jadwal4));
    InsertLastJ(L, createElemenJadwal(jadwal5));
    InsertLastJ(L, createElemenJadwal(jadwal6));
    InsertLastJ(L, createElemenJadwal(jadwal7));
    InsertLastJ(L, createElemenJadwal(jadwal8));
    InsertLastJ(L, createElemenJadwal(jadwal9));
    InsertLastJ(L, createElemenJadwal(jadwal10));
    InsertLastJ(L, createElemenJadwal(jadwal11));


    // Show the schedule
    cout << "Jadwal Penerbangan:" << endl;
    cout << "----------------------" << endl;
    ShowJadwal(L);
    cout << "----------------------" << endl;
    cout << "----------------------" << endl;



    //delete first
    adr_jadwalP P;
    DeleteFirstJ(L, P);

    // Show the schedule after deleting
    cout << "Jadwal setelah hapus:" << endl;
    cout << "----------------------" << endl;
    ShowJadwal(L);
    cout << "----------------------" << endl;
    cout << "----------------------" << endl;


    // Search
    string dari="Bandung", ke="Jakarta", tanggal="2024-12-28";
    cout << "Mencari jadwal penerbangan:" << endl;
    cout << "----------------------" << endl;
    SearchJ (L, dari, ke, tanggal);


    return 0;
}
