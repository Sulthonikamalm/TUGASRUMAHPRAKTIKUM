#ifndef MULTILISTVAR2_H_INCLUDED  // Memastikan bahwa header hanya dimasukkan sekali oleh preprocessor.
#define MULTILISTVAR2_H_INCLUDED

#include <iostream>  // Memasukkan library standar untuk input dan output.
#include <string>    // Memasukkan library string untuk menggunakan tipe data string.
using namespace std;  // Menggunakan namespace std untuk menghindari penulisan std:: berulang kali.

// Struktur untuk menyimpan informasi toko.
struct info_toko {
    string id_toko;    // Variabel untuk ID toko.
    string nama_toko;  // Variabel untuk nama toko.
};

// Struktur untuk menyimpan informasi barang.
struct info_barang {
    string id_barang;  // Variabel untuk ID barang.
    string nama_barang; // Variabel untuk nama barang.
    int harga;         // Variabel untuk harga barang.
};

// Pointer ke elemen toko.
typedef struct elm_toko* adr_toko;
// Pointer ke elemen barang.
typedef struct elm_barang* adr_barang;
// Pointer ke elemen relasi.
typedef struct elm_relation* adr_relation;

// Struktur untuk list toko.
struct list_toko {
    adr_toko first_toko;  // Pointer ke toko pertama dalam list.
};

// Struktur untuk list barang.
struct list_barang {
    adr_barang first_barang;  // Pointer ke barang pertama dalam list.
};

// Struktur untuk list relasi antara toko dan barang.
struct list_relation {
    adr_relation first_relation;  // Pointer ke relasi pertama dalam list.
};

// Elemen untuk toko.
struct elm_toko {
    info_toko info_toko;   // Data toko.
    adr_toko next_toko;    // Pointer ke toko berikutnya.
    list_relation barang;  // List relasi barang yang dijual oleh toko.
};

// Elemen untuk barang.
struct elm_barang {
    info_barang info_barang;  // Data barang.
    adr_barang next_barang;   // Pointer ke barang berikutnya.
};

// Elemen untuk relasi antara toko dan barang.
struct elm_relation {
    adr_barang next_barang;    // Pointer ke barang dalam relasi.
    adr_relation next_relation; // Pointer ke relasi berikutnya.
};

// Deklarasi fungsi untuk membuat list toko.
void createListToko(list_toko &t);
// Deklarasi fungsi untuk membuat elemen toko.
adr_toko createElmToko(string id, string nama);
// Deklarasi fungsi untuk membuat list barang.
void createListBarang(list_barang &b);
// Deklarasi fungsi untuk membuat elemen barang.
adr_barang createElmBarang(string id, string nama, int harga);
// Deklarasi fungsi untuk membuat elemen relasi.
adr_relation createElmRelation();

// Deklarasi fungsi untuk memasukkan toko ke dalam list.
void insertToko(list_toko &t, adr_toko p);
// Deklarasi fungsi untuk memasukkan barang ke dalam list.
void insertBarang(list_barang &b, adr_barang q);

// Deklarasi fungsi untuk mencari toko berdasarkan ID.
adr_toko searchToko(list_toko t, string id);
// Deklarasi fungsi untuk mencari barang berdasarkan ID.
adr_barang searchBarang(list_barang b, string id);
// Deklarasi fungsi untuk mencari relasi antara barang dengan list relasi.
adr_relation searchRelation(list_relation r, adr_barang p);

// Deklarasi fungsi untuk menambahkan barang ke toko.
void addBarang(list_toko &t, list_barang &b, string id_toko, string id_barang);
// Deklarasi fungsi untuk menghapus barang dari toko.
void deleteBarangToko(list_toko &t, string id_toko, string id_barang);
// Deklarasi fungsi untuk menghapus toko dari list.
void deleteToko(list_toko &t, string id_toko);
// Deklarasi fungsi untuk menghapus barang dari semua toko.
void deleteBarang(list_toko &t, list_barang &b, string id_barang);

// Deklarasi fungsi untuk mencari barang yang dijual oleh toko tertentu.
void searchBarangFromToko(list_toko t, string id_toko);
// Deklarasi fungsi untuk mencari toko yang menjual barang tertentu.
void searchTokoFromBarang(list_toko t, list_barang b, string id_barang);
// Deklarasi fungsi untuk menampilkan semua toko dan barang yang terkait.
void viewAll(list_toko t);

#endif // MULTILISTVAR2_H_INCLUDED
