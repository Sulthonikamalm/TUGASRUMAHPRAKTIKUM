#include "Tugasrumahmulltilistvar2.cpp"  // Memasukkan file implementasi.
#include <iostream>
#include <cstdlib>  // Untuk fungsi system("cls") yang membersihkan layar.
#include <cstddef>  // Untuk tipe data std::byte.

using namespace std;

// Menampilkan menu utama program.
void displayMenu() {
    system("cls");  // Bersihkan layar.
    cout << "========= Program Pendataan Toko ========" << endl;
    cout << "1. Insert Toko" << endl;
    cout << "2. Insert Barang" << endl;
    cout << "3. Tambah Relasi Toko dan Barang" << endl;
    cout << "4. View Data" << endl;
    cout << "5. Search Barang pada Toko Tertentu" << endl;
    cout << "6. Search Toko yang Jual Barang Tertentu" << endl;
    cout << "7. Hapus Barang dari Toko" << endl;
    cout << "8. Hapus Toko" << endl;
    cout << "9. Keluar" << endl;
    cout << "Masukkan pilihan anda: ";
}

// Fungsi utama untuk menjalankan program.
int main() {
    list_toko tokoList;  // Inisialisasi list toko.
    list_barang barangList;  // Inisialisasi list barang.
    createListToko(tokoList);  // Membuat list toko kosong.
    createListBarang(barangList);  // Membuat list barang kosong.
    int pilihan;  // Untuk menyimpan pilihan pengguna dari menu.
    string idToko, namaToko, idBarang, namaBarang;
    int harga;

    do {
        displayMenu();  // Tampilkan menu.
        cin >> pilihan;  // Baca pilihan pengguna.
        cin.ignore();  // Bersihkan buffer input.

        switch(pilihan) {
            case 1: {
                cout << "Masukkan ID Toko: ";
                getline(cin, idToko);
                cout << "Masukkan Nama Toko: ";
                getline(cin, namaToko);
                insertToko(tokoList, createElmToko(idToko, namaToko));  // Tambahkan toko baru.
                break;
            }
            case 2: {
                cout << "Masukkan ID Barang: ";
                getline(cin, idBarang);
                cout << "Masukkan Nama Barang: ";
                getline(cin, namaBarang);
                cout << "Masukkan Harga: ";
                cin >> harga;
                cin.ignore();
                insertBarang(barangList, createElmBarang(idBarang, namaBarang, harga));  // Tambahkan barang baru.
                break;
            }
            case 3: {
                cout << "Masukkan ID Toko: ";
                getline(cin, idToko);
                cout << "Masukkan ID Barang: ";
                getline(cin, idBarang);
                addBarang(tokoList, barangList, idToko, idBarang);  // Tambahkan relasi antara toko dan barang.
                break;
            }
            case 4: {
                viewAll(tokoList);  // Tampilkan semua data toko dan barang.
                break;
            }
            case 5: {
                cout << "Masukkan ID Toko untuk mencari barang: ";
                getline(cin, idToko);
                searchBarangFromToko(tokoList, idToko);  // Cari dan tampilkan barang di toko tertentu.
                break;
            }
            case 6: {
                cout << "Masukkan ID Barang untuk mencari toko: ";
                getline(cin, idBarang);
                searchTokoFromBarang(tokoList, barangList, idBarang);  // Cari dan tampilkan toko yang menjual barang tertentu.
                break;
            }
            case 7: {
                cout << "Masukkan ID Toko: ";
                getline(cin, idToko);
                cout << "Masukkan ID Barang yang akan dihapus: ";
                getline(cin, idBarang);
                deleteBarangToko(tokoList, idToko, idBarang);  // Hapus barang dari toko tertentu.
                break;
            }
            case 8: {
                cout << "Masukkan ID Toko yang akan dihapus: ";
                getline(cin, idToko);
                deleteToko(tokoList, idToko);  // Hapus toko dari list.
                break;
            }
            case 9:
                cout << "Keluar dari program." << endl;  // Keluar dari loop dan program.
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;  // Jika input tidak valid, minta pengguna memasukkan lagi.
        }
        system("pause");  // Tahan layar sehingga pengguna dapat melihat hasil sebelum lanjut.
    } while (pilihan != 9);

    return 0;  // Akhiri program dengan status sukses.
}
