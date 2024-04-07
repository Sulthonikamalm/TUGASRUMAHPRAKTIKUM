/*
===============================================================================
Nama : Sulthonika Mahfudz Al Mujahidin
nim : 1202230023
===============================================================================
*/

#ifndef TUGASRUMAHPR_H_INCLUDED  // Preprocessor directive untuk memastikan header file hanya diinclude sekali
#define TUGASRUMAHPR_H_INCLUDED

#include <string>  // Menginclude header untuk menggunakan tipe data string
using namespace std;  // Menggunakan namespace std agar tidak perlu menulis std:: setiap kali

// Definisi struktur ElmInfo yang menyimpan informasi setiap kelompok
typedef struct ElmInfo {
    int noKelompok;  // Nomor kelompok
    string namaKelompok;  // Nama kelompok
    int poinKelompok;  // Poin kelompok
} Info;

// Definisi tipe data address sebagai pointer ke struktur ElmList
typedef struct ElmList* address;

// Definisi struktur ElmList yang menyimpan informasi kelompok dan pointer ke elemen berikutnya
struct ElmList {
    Info info;  // Informasi kelompok
    address next;  // Pointer ke elemen berikutnya
};

// Definisi struktur LinkList yang hanya menyimpan pointer ke elemen pertama (head)
struct LinkList {
    address first;  // Pointer ke elemen pertama (head) dari list
};

// Deklarasi fungsi-fungsi yang akan digunakan di main.cpp
void createList(LinkList& list);  // Membuat list baru
address createElm(Info data);  // Membuat elemen baru berdasarkan data kelompok
void insertFirst(LinkList& list, address p);  // Menambahkan elemen baru di awal list
void insertLast(LinkList& list, address p);  // Menambahkan elemen baru di akhir list
void insertAfter(LinkList& list, address p, int cari);  // Menambahkan elemen baru setelah elemen tertentu
void deleteFirst(LinkList& list);  // Menghapus elemen pertama dari list
void deleteLast(LinkList& list);  // Menghapus elemen terakhir dari list
void deleteAfter(LinkList& list, int cari);  // Menghapus elemen setelah elemen tertentu
void view(LinkList list);  // Menampilkan isi list
void putar(LinkList& list);  // Memutar urutan list
void urutkan(LinkList& list);  // Mengurutkan list berdasarkan poin terbesar

#endif // TUGASRUMAHPR_H_INCLUDED