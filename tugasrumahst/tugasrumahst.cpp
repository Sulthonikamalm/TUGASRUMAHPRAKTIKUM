#include "tugasrumahst.h" // Mengimpor definisi struktur data dan fungsi dari header file

// Inisialisasi stack dengan menetapkan top ke -1, menandakan stack kosong
void initStack(Stack &s) {
    s.top = -1; // Stack kosong jika top adalah -1
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack s) {
    return s.top == -1; // Mengembalikan true jika top adalah -1, yang berarti stack kosong
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack s) {
    return s.top == MAX_SIZE - 1; // Mengembalikan true jika top sama dengan MAX_SIZE - 1, yang berarti stack penuh
}

// Menambahkan elemen ke dalam stack
void push(Stack &s, Mobil x) {
    if (isFull(s)) { // Cek apakah stack sudah penuh
        cout << "Stack Penuh" << endl; // Jika ya, tampilkan pesan stack penuh
    } else { // Jika tidak,
        s.top++; // Naikkan top
        s.data[s.top] = x; // Simpan data mobil ke dalam stack
    }
}

// Menghapus elemen dari stack dan mengembalikannya
Mobil pop(Stack &s) {
    Mobil temp; // Deklarasi variabel temp untuk menyimpan data sementara
    if (isEmpty(s)) { // Cek apakah stack kosong
        cout << "Stack Kosong" << endl; // Jika ya, tampilkan pesan stack kosong
    } else { // Jika tidak,
        temp = s.data[s.top]; // Simpan data top ke dalam temp
        s.top--; // Turunkan top
    }
    return temp; // Kembalikan data yang di-pop
}

// Melihat elemen teratas dari stack tanpa menghapusnya
Mobil peek(Stack s) {
    Mobil temp; // Deklarasi variabel temp untuk menyimpan data sementara
    if (isEmpty(s)) { // Cek apakah stack kosong
        cout << "Stack Kosong" << endl; // Jika ya, tampilkan pesan stack kosong
    } else { // Jika tidak,
        temp = s.data[s.top]; // Simpan data top ke dalam temp
    }
    return temp; // Kembalikan data top
}

// Menampilkan semua elemen dalam stack
void showMobil(Stack s) {
    if (isEmpty(s)) { // Cek apakah stack kosong
        cout << "Stack Kosong" << endl; // Jika ya, tampilkan pesan stack kosong
    } else { // Jika tidak,
        cout << "Data Kendaraan:" << endl; // Tampilkan header
        for (int i = s.top; i >= 0; i--) { // Iterasi dari top ke bawah
            // Tampilkan data mobil
            cout << "Merk: " << s.data[i].merk << ", Warna: " << s.data[i].warna << ", Tahun: " << s.data[i].tahun << endl;
        }
    }
}

// Mencari mobil berdasarkan merk dan mengembalikan posisinya dalam stack
int searchMobil(Stack s, string merk) {
    int count = 1; // Inisialisasi counter
    for (int i = s.top; i >= 0; i--) { // Iterasi dari top ke bawah
        if (s.data[i].merk == merk) { // Jika merk ditemukan
            // Tampilkan data mobil yang ditemukan
            cout << "Kendaraan Ditemukan pada Urutan ke-" << count << ":" << endl;
            cout << "Merk: " << s.data[i].merk << ", Warna: " << s.data[i].warna << ", Tahun: " << s.data[i].tahun << endl;
            return i; // Kembalikan posisi mobil dalam stack
        }
        count++; // Naikkan counter
    }
    return -1; // Jika tidak ditemukan, kembalikan -1
}