#include "tugasrumahst.cpp" // Mengimpor file tugasrumahst.cpp
#include <iostream> // Mengimpor library iostream untuk input dan output
#include <limits> // Mengimpor library limits untuk menggunakan numeric limits

using namespace std; // Menggunakan namespace std untuk memudahkan penulisan kode

int main() {
    Stack s; // Membuat variabel stack s
    initStack(s); // Menginisialisasi stack s
    Mobil temp; // Membuat variabel temp untuk menyimpan data mobil sementara
    int pilihan, index; // Membuat variabel pilihan untuk menu dan index untuk pencarian
    string merk, warna; // Membuat variabel merk dan warna untuk input data mobil
    int tahun; // Membuat variabel tahun untuk input data mobil
    char lagi; // Membuat variabel lagi untuk menanyakan pengguna apakah ingin mengulang

    do {
       
        system ("cls"); // Membersihkan layar
        cout << "===================================================\n"; // Menampilkan header aplikasi
        cout << "= Selamat Datang di Aplikasi SHOWROOM Mobil smalm =\n"; // Menampilkan header aplikasi
        cout << "===================================================\n"; // Menampilkan header aplikasi
        cout << "Pilihan Menu:\n"; // Menampilkan menu pilihan
        cout << "1. Tambah Kendaraan\n"; // Menu untuk menambah kendaraan
        cout << "2. Lihat Kendaraan Teratas\n"; // Menu untuk melihat kendaraan teratas
        cout << "3. Hapus Kendaraan Teratas\n"; // Menu untuk menghapus kendaraan teratas
        cout << "4. Lihat Seluruh Kendaraan\n"; // Menu untuk melihat seluruh kendaraan
        cout << "5. Cari Kendaraan Berdasarkan\n"; // Menu untuk mencari kendaraan
        cout << "6. Keluar\n"; // Menu untuk keluar dari aplikasi
        cout << "Masukkan Pilihan: "; // Meminta pengguna memasukkan pilihan
        cin >> pilihan; // Menerima input pilihan dari pengguna
        cout << "\n"; 

        switch (pilihan) { // Memproses pilihan berdasarkan input pengguna
            case 1: // Jika pengguna memilih 1
                do {
                    cout << "Masukkan Merk: "; // Meminta pengguna memasukkan merk
                    cin >> temp.merk; // Menerima input merk dari pengguna
                    cout << "Masukkan Warna: "; // Meminta pengguna memasukkan warna
                    cin >> temp.warna; // Menerima input warna dari pengguna
                    cout << "Masukkan Tahun: "; // Meminta pengguna memasukkan tahun
                    cin >> temp.tahun; // Menerima input tahun dari pengguna
                    push(s, temp); // Menambahkan data mobil ke stack
                    cout << "\nData Berhasil ditambah!\n"; // Menampilkan pesan sukses
                    cout << "Tambah Data Lagi? (y/n): "; // Menanyakan pengguna apakah ingin menambah lagi
                    cin >> lagi; // Menerima input dari pengguna
                    
                    cin.ignore(); // Mengabaikan input berikutnya untuk mencegah error
                } while (lagi == 'y' || lagi == 'Y'); // Mengulang jika pengguna memasukkan 'y' atau 'Y'
                break; // Keluar dari case
            case 2: // Jika pengguna memilih 2
                temp = peek(s); // Mengambil data mobil teratas dari stack
                cout << "Kendaraan Teratas:\n"; // Menampilkan judul kendaraan teratas
                cout << "Merk: " << temp.merk << "\n"; // Menampilkan merk mobil teratas
                cout << "Warna: " << temp.warna << "\n"; // Menampilkan warna mobil teratas
                cout << "Tahun: " << temp.tahun << "\n\n"; // Menampilkan tahun mobil teratas
                break; // Keluar dari case
            case 3: // Jika pengguna memilih 3
                temp = pop(s); // Menghapus data mobil teratas dari stack
                cout << "Kendaraan Teratas Berhasil Dihapus\n\n"; // Menampilkan pesan sukses
                break; // Keluar dari case
            case 4: // Jika pengguna memilih 4
                showMobil(s); // Menampilkan seluruh data mobil dalam stack
                cout << "\n"; 
                break; // Keluar dari case
            case 5: // Jika pengguna memilih 5
                cout << "Masukkan Merk yang Dicari: "; // Meminta pengguna memasukkan merk yang dicari
                cin >> merk; // Menerima input merk dari pengguna
                index = searchMobil(s, merk); // Mencari mobil berdasarkan merk
                if (index == -1) { // Jika mobil tidak ditemukan
                    cout << "Kendaraan Tidak Ditemukan\n\n"; // Menampilkan pesan tidak ditemukan
                }
                break; // Keluar dari case
            case 6: // Jika pengguna memilih 6
                cout << "Terima Kasih Telah Menggunakan Aplikasi ShowRoom Mobil Smalm\n"; // Menampilkan pesan terima kasih
                break; // Keluar dari case
            default: // Jika pengguna memasukkan pilihan selain 1-6
                cout << "Pilihan Tidak Valid\n\n"; // Menampilkan pesan pilihan tidak valid
                break; // Keluar dari case
        }
        system("pause"); // Menjeda program sebelum melanjutkan
    } while (pilihan != 6); // Mengulang selama pengguna tidak memilih 6 (keluar)

    return 0; // Mengakhiri program
}
