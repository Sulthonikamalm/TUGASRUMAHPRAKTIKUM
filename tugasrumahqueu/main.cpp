#include <iostream> // Menggunakan library iostream untuk input-output
#include <cstdlib> // Menggunakan library cstdlib untuk fungsi system
#include "tugasrumahqueu.cpp" // Menggunakan file tugasrumahqueu.cpp yang berisi implementasi fungsi antrian

using namespace std;

int main() {
    QueueOfInt queue; // Membuat objek antrian dengan tipe data QueueOfInt
    CreateEmpty(queue); // Memanggil fungsi CreateEmpty untuk membuat antrian kosong
    int choice, value;

    do {
        system("cls"); // Membersihkan layar
        drawLine(50); // Menggambar garis pembatas
        cout << "=== Program Antrian Pembelian Tiket Konser Musik ===" << endl; // Menampilkan judul program
        drawLine(50); // Menggambar garis pembatas
        cout << "1. Tambahkan pembeli ke antrian" << endl; // Menampilkan opsi untuk menambahkan pembeli ke antrian
        cout << "2. Hapus pembeli dari antrian" << endl; // Menampilkan opsi untuk menghapus pembeli dari antrian
        cout << "3. Lihat pembeli di depan antrian" << endl; // Menampilkan opsi untuk melihat pembeli di depan antrian
        cout << "4. Lihat semua pembeli yang sedang antri" << endl; // Menampilkan opsi untuk melihat semua pembeli yang sedang antri
        cout << "5. Lihat jumlah pembeli yang sedang antri" << endl; // Menampilkan opsi untuk melihat jumlah pembeli yang sedang antri
        cout << "6. Keluar" << endl; // Menampilkan opsi untuk keluar dari program
        drawLine(50); // Menggambar garis pembatas
        cout << "Masukkan pilihan: "; // Meminta input pilihan dari pengguna
        cin >> choice; // Membaca pilihan dari pengguna
        cin.ignore(); // Untuk membaca newline dari cin sebelumnya

        switch (choice) {
            case 1:
                system("cls"); // Membersihkan layar
                drawLine(50); // Menggambar garis pembatas
                cout << "Masukkan nomor identitas pembeli: "; // Meminta input nomor identitas pembeli
                cin >> value; // Membaca nomor identitas dari pengguna
                enQueue(queue, value); // Memanggil fungsi enQueue untuk menambahkan pembeli ke antrian
                break;
            case 2:
                // system("cls"); // Membersihkan layar (dikomentari karena tidak perlu)
                cout << endl;
                drawLine(50); // Menggambar garis pembatas
                deQueue(queue); // Memanggil fungsi deQueue untuk menghapus pembeli dari antrian
                cout << "Pembeli berhasil dihapus dari antrian." << endl; // Menampilkan pesan pembeli berhasil dihapus
                drawLine(50); // Menggambar garis pembatas
                system("pause"); // Menunggu pengguna menekan tombol
                break;
            case 3:
                // system("cls"); // Membersihkan layar (dikomentari karena tidak perlu)
                cout << endl;
                drawLine(50); // Menggambar garis pembatas
                cout << "Pembeli di depan antrian: " << front(queue) << endl; // Menampilkan pembeli di depan antrian
                drawLine(50); // Menggambar garis pembatas
                system("pause"); // Menunggu pengguna menekan tombol
                break;
            case 4:
                // system("cls"); // Membersihkan layar (dikomentari karena tidak perlu)
                cout << endl;
                drawLine(50); // Menggambar garis pembatas
                cout << "Pembeli yang sedang antri: ";
                if (isEmpty(queue)) {
                    cout << "Antrian kosong" << endl; // Menampilkan pesan antrian kosong jika tidak ada pembeli
                } else {
                    for (int i = queue.head; i <= queue.tail; i++) {
                        cout << queue.ar[i] << " "; // Menampilkan nomor identitas pembeli yang sedang antri
                    }
                    cout << endl;
                }
                drawLine(50); // Menggambar garis pembatas
                system("pause"); // Menunggu pengguna menekan tombol
                break;
            case 5:
                // system("cls"); // Membersihkan layar (dikomentari karena tidak perlu)
                cout << endl;
                drawLine(50); // Menggambar garis pembatas
                cout << "Jumlah pembeli yang sedang antri: " << size(queue) << endl; // Menampilkan jumlah pembeli yang sedang antri
                drawLine(50); // Menggambar garis pembatas
                system("pause"); // Menunggu pengguna menekan tombol
                break;
            case 6:
                system("cls"); // Membersihkan layar
                drawLine(50); // Menggambar garis pembatas
                cout << "|                                                |" << endl;
                cout << "|                                                |" << endl;
                cout << "|  Terima kasih telah menggunakan program ini :) |" << endl;
                cout << "|                                                |" << endl;
                cout << "|                                                |" << endl;
                drawLine(50); // Menggambar garis pembatas
                // system("pause"); // Menunggu pengguna menekan tombol
                break;
            default:
                system("cls"); // Membersihkan layar
                drawLine(50); // Menggambar garis pembatas
                cout << "Pilihan tidak valid." << endl; // Menampilkan pesan pilihan tidak valid
                drawLine(50); // Menggambar garis pembatas
                system("pause"); // Menunggu pengguna menekan tombol
                break;
        }
    } while (choice != 6); // Melakukan perulangan selama pilihan tidak sama dengan 6

    return 0;
}