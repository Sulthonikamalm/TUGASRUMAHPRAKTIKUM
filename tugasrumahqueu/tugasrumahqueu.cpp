#include <iostream> // Menggunakan library iostream untuk input-output
#include <cstdlib> // Menggunakan library cstdlib untuk fungsi system

// #include <tugasrumahqueu.h> // Komentar ini dinonaktifkan karena file header tidak digunakan

using namespace std; // Menggunakan namespace std untuk memudahkan penggunaan fungsi dari library

const int maxqueue = 10; // Mendefinisikan konstanta maxqueue dengan nilai 10 sebagai ukuran maksimum antrian

struct QueueOfInt { // Mendefinisikan struktur QueueOfInt untuk menyimpan data antrian
    int ar[maxqueue]; // Array ar dengan ukuran maxqueue untuk menyimpan elemen antrian
    int head, tail; // Variabel head dan tail untuk menandai posisi awal dan akhir antrian
};

void CreateEmpty(QueueOfInt &q) { // Fungsi untuk membuat antrian kosong
    q.head = -1; // Mengatur head ke nilai -1
    q.tail = -1; // Mengatur tail ke nilai -1
}

bool isEmpty(QueueOfInt q) { // Fungsi untuk mengecek apakah antrian kosong
    return (q.head == -1) && (q.tail == -1); // Mengembalikan true jika head dan tail bernilai -1
}

bool isFull(QueueOfInt q) { // Fungsi untuk mengecek apakah antrian penuh
    return (q.head == 0 && q.tail == maxqueue - 1); // Mengembalikan true jika head adalah 0 dan tail adalah maxqueue - 1
}

void enQueue(QueueOfInt &q, int elm) { // Fungsi untuk menambahkan elemen ke antrian
    if (isFull(q)) { // Jika antrian penuh
        cout << "Antrian sudah penuh" << endl; // Menampilkan pesan antrian sudah penuh
    } else {
        if (isEmpty(q)) { // Jika antrian kosong
            q.head = 0; // Mengatur head ke 0
            q.tail = 0; // Mengatur tail ke 0
        } else {
            q.tail++; // Menambahkan tail
        }
        q.ar[q.tail] = elm; // Menambahkan elemen ke antrian
        cout << "Elemen " << elm << " berhasil ditambahkan ke antrian" << endl; // Menampilkan pesan elemen berhasil ditambahkan
    }
}

void deQueue(QueueOfInt &q) { // Fungsi untuk menghapus elemen dari antrian
    if (isEmpty(q)) { // Jika antrian kosong
        cout << "Antrian sudah kosong" << endl; // Menampilkan pesan antrian sudah kosong
    } else {
        if (q.head == q.tail) { // Jika head sama dengan tail
            CreateEmpty(q); // Memanggil fungsi CreateEmpty untuk membuat antrian kosong
        } else {
            int removed = q.ar[q.head]; // Simpan elemen yang dihapus
            for (int i = q.head + 1; i <= q.tail; i++) { // Menggeser elemen antrian
                q.ar[i - 1] = q.ar[i];
            }
            q.tail--; // Mengurangi tail
            cout << "Elemen " << removed << " berhasil dihapus dari antrian" << endl; // Menampilkan pesan elemen berhasil dihapus
        }
    }
}

// Fungsi tambahan untuk mendapatkan elemen di depan antrian
int front(QueueOfInt q) {
    if (isEmpty(q)) { // Jika antrian kosong
        cout << "Antrian kosong" << endl; // Menampilkan pesan antrian kosong
        return -1; // Mengembalikan nilai -1
    } else {
        return q.ar[q.head]; // Mengembalikan elemen di depan antrian
    }
}

// Fungsi tambahan untuk mendapatkan jumlah elemen dalam antrian
int size(QueueOfInt q) {
    if (isEmpty(q)) { // Jika antrian kosong
        return 0; // Mengembalikan nilai 0
    } else {
        return q.tail - q.head + 1; // Mengembalikan jumlah elemen dalam antrian
    }
}

void drawLine(int length) { // Fungsi untuk menggambar garis sepanjang length
    for (int i = 0; i < length; i++) { // Loop untuk menggambar garis
        cout << "="; // Menampilkan karakter "="
    }
    cout << endl; // Pindah baris
}