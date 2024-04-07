/*
===============================================================================
Nama : Sulthonika Mahfudz Al Mujahidin
nim : 1202230023
===============================================================================
*/

#include "tugasrumahpr.h"
#include <iostream>
#include <iomanip>

using namespace std;

void createList(LinkList& list) {
    // Fungsi untuk membuat list kosong
    // Hal ini dilakukan dengan mengatur list.first menjadi NULL
    list.first = NULL;
}

address createElm(Info data) {
    // Fungsi untuk membuat elemen baru
    // Elemen baru akan memiliki Info yang diberikan sebagai parameter, dan next akan diatur menjadi NULL
    address p = new ElmList;
    p->info = data;
    p->next = NULL;
    return p;
}

void insertFirst(LinkList& list, address p) {
    // Fungsi untuk menambahkan elemen baru di awal list
    // Jika list kosong, maka elemen baru akan menjadi kepala list
    // Jika list tidak kosong, maka elemen baru akan disisipkan di awal list
    if (list.first == NULL) {
        list.first = p;
        p->next = list.first;
    } else {
        address q = list.first;
        while (q->next != list.first) {
            q = q->next;
        }
        p->next = list.first;
        q->next = p;
        list.first = p;
    }
}

void insertLast(LinkList& list, address p) {
    // Fungsi untuk menambahkan elemen baru di akhir list
    // Jika list kosong, maka elemen baru akan menjadi kepala list
    // Jika list tidak kosong, maka elemen baru akan disisipkan di akhir list
    if (list.first == NULL) {
        list.first = p;
        p->next = list.first;
    } else {
        address q = list.first;
        while (q->next != list.first) {
            q = q->next;
        }
        q->next = p;
        p->next = list.first;
    }
}

void insertAfter(LinkList& list, address p, int cari) {
    // Fungsi untuk menambahkan elemen baru setelah elemen yang memiliki nomor kelompok yang dicari
    // Jika list kosong, maka elemen baru akan menjadi kepala list
    // Jika list tidak kosong dan elemen yang memiliki nomor kelompok yang dicari ditemukan,
    // maka elemen baru akan disisipkan setelah elemen tersebut
    if (list.first == NULL) {
        list.first = p;
        p->next = list.first;
    } else {
        address q = list.first;
        while ((q->next != list.first) && (q->info.noKelompok != cari)) {
            q = q->next;
        }
        if (q->info.noKelompok == cari) {
            p->info.poinKelompok += q->info.poinKelompok;
            p->next = q->next;
            q->next = p;
        }
    }
}

void deleteFirst(LinkList& list) {
    // Fungsi untuk menghapus elemen pertama dari list
    // Jika list hanya memiliki satu elemen, maka list akan dikosongkan
    // Jika list memiliki lebih dari satu elemen, maka elemen pertama akan dihapus
    if (list.first != NULL) {
        if (list.first->next == list.first) {
            createList(list);
        } else {
            address temp = list.first;
            address q = list.first;
            while (q->next != list.first) {
                q = q->next;
            }
            list.first = temp->next;
            q->next = list.first;
            delete temp;
        }
    }
}

void deleteLast(LinkList& list) {
    // Fungsi untuk menghapus elemen terakhir dari list
    // Jika list hanya memiliki satu elemen, maka list akan dikosongkan
    // Jika list memiliki lebih dari satu elemen, maka elemen terakhir akan dihapus
    if (list.first != NULL) {
        if (list.first->next == list.first) {
            createList(list);
        } else {
            address temp = list.first;
            address q;
            while (temp->next != list.first) {
                q = temp;
                temp = temp->next;
            }
            q->next = list.first;
            delete temp;
        }
    }
}

void deleteAfter(LinkList& list, int cari) {
    // Fungsi untuk menghapus elemen setelah elemen yang memiliki nomor kelompok yang dicari
    // Jika list hanya memiliki satu elemen, maka list akan dikosongkan
    // Jika list memiliki lebih dari satu elemen dan elemen yang memiliki nomor kelompok yang dicari ditemukan,
    // maka elemen setelah elemen tersebut akan dihapus
    if (list.first != NULL) {
        if (list.first->next == list.first) {
            createList(list);
        } else {
            address temp = list.first;
            address q;
            while ((temp->next != list.first) && (temp->info.noKelompok != cari)) {
                q = temp;
                temp = temp->next;
            }
            if (temp->info.noKelompok == cari) {
                if (temp == list.first) {
                    deleteFirst(list);
                } else if (temp->next == list.first) {
                    deleteLast(list);
                } else {
                    q->next = temp->next;
                    delete temp;
                }
            }
        }
    }
}

void view(LinkList list) {
    // Fungsi ini digunakan untuk menampilkan isi dari list
    // Tujuannya adalah untuk menampilkan informasi dari setiap kelompok, yaitu nomor kelompok, nama kelompok, dan poin kelompok

    // Jika list kosong, maka akan ditampilkan pesan "kosong"
    if (list.first == NULL) { 
        cout << "kosong" << endl;
    }
    // Jika list tidak kosong, maka akan menampilkan informasi setiap kelompok
    else {
        // Simpan referensi ke elemen pertama (head) dari list
        address temp = list.first;

        // Lakukan loop terus-menerus sampai kembali ke elemen pertama (head) list
        do {
            // Tampilkan nomor kelompok, nama kelompok, dan poin kelompok untuk elemen saat ini
            cout << temp->info.noKelompok << ". " << setw(9) << left << temp->info.namaKelompok << " {" << temp->info.poinKelompok << "}" << endl;

            // Pindah ke elemen selanjutnya di dalam list
            temp = temp->next;
        } while (temp != list.first);
    }
}

void putar(LinkList& list) {
    // Fungsi ini digunakan untuk memutar urutan elemen dalam list
    // Tujuannya adalah untuk mengubah urutan elemen agar berbeda dari sesi sebelumnya

    // Jika list tidak kosong
    if (list.first != NULL) {
        // Simpan referensi ke elemen pertama (head) dari list
        address temp = list.first;

        // Atur list.first menjadi elemen setelah elemen pertama saat ini
        list.first = temp->next;

        // Lakukan loop untuk mencari elemen terakhir dalam list
        while (temp->next != list.first) {
            temp = temp->next;
        }

        // Atur elemen terakhir untuk menunjuk ke elemen pertama (head) list
        temp->next = list.first;
    }
}

void urutkan(LinkList& list) {
    // Fungsi ini digunakan untuk mengurutkan list berdasarkan poin kelompok
    // Tujuannya adalah untuk menentukan pemenang berdasarkan poin terbesar

    // Jika list tidak kosong
    if (list.first != NULL) {
        // Simpan referensi ke elemen pertama (head) dari list
        address temp = list.first;

        // Lakukan loop terus-menerus sampai kembali ke elemen pertama (head) list
        do {
            // Inisialisasi elemen dengan poin terbesar sementara (min) dengan elemen saat ini
            address min = temp;
            address q = temp->next;

            // Lakukan loop untuk mencari elemen dengan poin terbesar
            while (q != list.first) {
                // Jika poin kelompok elemen q lebih besar dari poin kelompok elemen min,
                // maka atur min menjadi q
                if (q->info.poinKelompok > min->info.poinKelompok) {
                    min = q;
                }

                // Pindah ke elemen selanjutnya
                q = q->next;
            }

            // Lakukan swap informasi antara elemen saat ini (temp) dengan elemen dengan poin terbesar (min)
            swap(temp->info, min->info);

            // Pindah ke elemen selanjutnya
            temp = temp->next;
        } while (temp->next != list.first);
    }
}