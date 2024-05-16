#ifndef MULTI_LIST_MTON_H_INCLUDED 
#define MULTI_LIST_MTON_H_INCLUDED 

#include <iostream> // Menyertakan file header iostream untuk operasi input/output standar.
#include <string> // Menyertakan file header string untuk bekerja dengan tipe data string.

using namespace std; 
typedef struct ElmChild *adr_child; // Mendefinisikan alias adr_child untuk tipe data pointer ke struktur ElmChild.
typedef struct ElmParent *adr_parent; // Mendefinisikan alias adr_parent untuk tipe data pointer ke struktur ElmParent.

struct InfoChild // Struktur untuk menyimpan informasi anak.
{
    string idChild; // Anggota data untuk menyimpan ID anak.
    string NamaChild; // Anggota data untuk menyimpan nama anak.
};

struct InfoParent // Struktur untuk menyimpan informasi orang tua.
{
    string idParent; // Anggota data untuk menyimpan ID orang tua.
    string NamaParent; // Anggota data untuk menyimpan nama orang tua.
};

struct ListChild // Struktur untuk menyimpan list anak.
{
    adr_child first_Child; // Pointer ke elemen pertama dalam list anak.
};

struct ListParent // Struktur untuk menyimpan list orang tua.
{
    adr_parent first_Parent; // Pointer ke elemen pertama dalam list orang tua.
};

struct ElmChild // Struktur untuk menyimpan elemen dalam list anak.
{
    InfoChild info; // Informasi anak yang disimpan dalam elemen.
    adr_child next_child; // Pointer ke elemen anak berikutnya.
};

struct ElmParent // Struktur untuk menyimpan elemen dalam list orang tua.
{
    InfoParent info; // Informasi orang tua yang disimpan dalam elemen.
    adr_parent next_parent; // Pointer ke elemen orang tua berikutnya.
    ListChild child; // List anak yang terkait dengan orang tua ini.
};

void createListChild(ListChild &LC); // Prototipe fungsi untuk membuat list anak yang kosong.
void createListParent(ListParent &LP); // Prototipe fungsi untuk membuat list orang tua yang kosong.
adr_child createElmChild(InfoChild info); // Prototipe fungsi untuk membuat elemen baru pada list anak dengan informasi yang diberikan.
adr_parent createElmParent(InfoParent info); // Prototipe fungsi untuk membuat elemen baru pada list orang tua dengan informasi yang diberikan.
void insertChild(ListChild &LC, adr_child c); // Prototipe fungsi untuk memasukkan elemen anak baru ke dalam list anak.
void insertParent(ListParent &LP, adr_parent p); // Prototipe fungsi untuk memasukkan elemen orang tua baru ke dalam list orang tua.
adr_child searchChild(ListChild LC, string idChild); // Prototipe fungsi untuk mencari elemen anak berdasarkan ID anak yang diberikan.
adr_parent searchParent(ListParent LP, string idParent); // Prototipe fungsi untuk mencari elemen orang tua berdasarkan ID orang tua yang diberikan.
void addChild(ListChild &LC, ListParent &LP, string idChild, string idParent); // Prototipe fungsi untuk menambahkan anak ke dalam list anak pada elemen orang tua tertentu.
void viewParent(ListParent &LP); // Prototipe fungsi untuk menampilkan semua elemen orang tua pada list orang tua.
void viewChild(ListChild &LC); // Prototipe fungsi untuk menampilkan semua elemen anak pada list anak.
void viewParentChild(ListParent &LP); // Prototipe fungsi untuk menampilkan semua elemen orang tua dan anak-anaknya pada list orang tua.
void deleteAfterParent(ListParent &LP, string idParent); // Prototipe fungsi untuk menghapus elemen orang tua setelah elemen dengan ID orang tua yang diberikan.
void deleteAfterChild(ListChild &LC, string idChild); // Prototipe fungsi untuk menghapus elemen anak setelah elemen dengan ID anak yang diberikan.
void deleteParent(ListParent &LP, string idParent); // Prototipe fungsi untuk menghapus elemen orang tua beserta anak-anaknya berdasarkan ID orang tua yang diberikan.
void deleteChild(ListChild &LC, ListParent &LP, string idChild); // Prototipe fungsi untuk menghapus elemen anak berdasarkan ID anak yang diberikan.

#endif // MULTI_LIST_MTON_H_INCLUDED 