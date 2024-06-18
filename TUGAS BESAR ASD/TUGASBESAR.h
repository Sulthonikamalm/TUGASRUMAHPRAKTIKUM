#ifndef TUGASBESAR_H
#define TUGASBESAR_H

#include <iostream>
#include <string>
using namespace std;

struct infotype_brand {
    string id_brand;
    string nama_brand;
};

struct infotype_produk {
    string id_produk;
    string nama_produk;
    int harga;
};

typedef struct elm_brand *adr_brand;
typedef struct elm_produk *adr_produk;
typedef struct elm_relasi *adr_relasi;

struct list_brand {
    adr_brand pertama_brand;
};

struct list_produk {
    adr_produk pertama_produk;
};

struct list_relasi {
    adr_relasi pertama_relasi;
};

struct elm_brand {
    infotype_brand info_brand;
    adr_brand selanjutnya_brand;
    list_relasi produk;
};

struct elm_produk {
    infotype_produk info_produk;
    adr_produk selanjutnya_produk;
};

struct elm_relasi {
    adr_produk selanjutnya_produk;
    adr_relasi selanjutnya_relasi;
};

void buatListBrand(list_brand &b);
adr_brand buatElmBrand(string id, string nama);
void buatListProduk(list_produk &p);
adr_produk buatElmProduk(string id, string nama, int harga);
adr_relasi buatElmRelasi();

void tambahBrandPertama(list_brand &b, adr_brand p);
// void tambahBrandTerakhir(list_brand &b, adr_brand p);
// void tambahProdukPertama(list_produk &p, adr_produk q);
void tambahProdukTerakhir(list_produk &p, adr_produk q);
void tambahProdukKeBrand(list_brand &b, list_produk &p, string id_brand, string id_produk);

void hapusProdukDariBrand(list_brand &b, string id_brand, string id_produk);
void hapusBrand(list_brand &b, string id_brand);
void hapusProduk(list_brand &b, list_produk &p, string id_produk);

adr_brand cariBrand(list_brand b, string id);
adr_produk cariProduk(list_produk p, string id_produk);
adr_relasi cariRelasi(list_relasi r, adr_produk p);

void cariProdukDariBrand(list_brand b, string id_brand);
void cariBrandDariProduk(list_brand b, list_produk p, string id_produk);
void tampilkanSemua(list_brand b);
void brandDenganProdukTerbanyak(list_brand b);
void brandDenganProdukTersedikit(list_brand b);

// Fungsi untuk menampilkan semua brand
void tampilkanSemuaBrand(const list_brand &b);

// Fungsi untuk menampilkan semua produk
void tampilkanSemuaProduk(const list_produk &p);


#endif // TUGASBESAR_H_INCLUDED
