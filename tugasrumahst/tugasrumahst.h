#ifndef TUGASRUMAHST_H_INCLUDED // Cek apakah sudah didefinisikan sebelumnya
#define TUGASRUMAHST_H_INCLUDED // Mendefinisikan TUGASRUMAHST_H_INCLUDED
#include <iostream> // Mengimpor library iostream untuk input dan output
#include <string> // Mengimpor library string untuk menggunakan tipe data string
using namespace std; // Menggunakan namespace std untuk memudahkan penulisan kode

#define MAX_SIZE 100 // Mendefinisikan ukuran maksimal stack

// Membuat struktur data untuk Mobil
struct Mobil {
    string merk; // Menyimpan merk mobil
    string warna; // Menyimpan warna mobil
    int tahun; // Menyimpan tahun pembuatan mobil
};

// Membuat struktur data untuk Stack
struct Stack {
    Mobil data[MAX_SIZE]; // Array untuk menyimpan data mobil
    int top; // Variabel untuk menunjukkan posisi teratas dari stack
};

// Deklarasi fungsi untuk inisialisasi stack
void initStack(Stack &s);
// Deklarasi fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack s);
// Deklarasi fungsi untuk mengecek apakah stack penuh
bool isFull(Stack s);
// Deklarasi fungsi untuk menambahkan data mobil ke dalam stack
void push(Stack &s, Mobil x);
// Deklarasi fungsi untuk menghapus data mobil dari stack dan mengembalikannya
Mobil pop(Stack &s);
// Deklarasi fungsi untuk melihat data mobil teratas dari stack tanpa menghapusnya
Mobil peek(Stack s);
// Deklarasi fungsi untuk menampilkan semua data mobil dalam stack
void showMobil(Stack s);
// Deklarasi fungsi untuk mencari mobil berdasarkan merk dan mengembalikan posisinya dalam stack
int searchMobil(Stack s, string merk);

#endif // TUGASRUMAHST_H_INCLUDED