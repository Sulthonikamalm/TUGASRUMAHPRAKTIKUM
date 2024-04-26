#ifndef TUGASRUMAHQUEU_H_INCLUDED
#define TUGASRUMAHQUEU_H_INCLUDED

#include <iostream> // Menggunakan library iostream untuk input-output
using namespace std; // Menggunakan namespace std untuk memudahkan penggunaan fungsi dari library

const int MAX_QUEUE = 100; // Mendefinisikan konstanta MAX_QUEUE dengan nilai 100 sebagai ukuran maksimum antrian

struct QueueOfInt { // Mendefinisikan struktur QueueOfInt untuk menyimpan data antrian
    int data[MAX_QUEUE]; // Array data dengan ukuran MAX_QUEUE untuk menyimpan elemen antrian
    int head, tail; // Variabel head dan tail untuk menandai posisi awal dan akhir antrian
};

void CreateEmpty(QueueOfInt &q); // Deklarasi fungsi CreateEmpty untuk membuat antrian kosong
bool isEmpty(QueueOfInt q); // Deklarasi fungsi isEmpty untuk mengecek apakah antrian kosong
bool isFull(QueueOfInt q); // Deklarasi fungsi isFull untuk mengecek apakah antrian penuh
void enQueue(QueueOfInt &q, int val); // Deklarasi fungsi enQueue untuk menambahkan elemen ke antrian
void deQueue(QueueOfInt &q); // Deklarasi fungsi deQueue untuk menghapus elemen dari antrian
int front(QueueOfInt q); // Deklarasi fungsi front untuk mendapatkan elemen yang berada di depan antrian
int size(QueueOfInt q); // Deklarasi fungsi size untuk mendapatkan jumlah elemen dalam antrian
void drawLine(int length); // Deklarasi fungsi drawLine untuk menggambar garis sepanjang length

#endif // PRAKTIKUMQUEU_H_INCLUDED
