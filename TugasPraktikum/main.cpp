#include <iostream> // Menyertakan file header iostream untuk operasi input/output standar.
#include <cstdlib> // Menyertakan file header cstdlib yang dibutuhkan untuk fungsi system().
#include "multi_list_MtoN.cpp" // Menyertakan file sumber "multi_list_MtoN.cpp" yang berisi implementasi fungsi-fungsi untuk manipulasi list anak dan orang tua.

using namespace std; 
void printMenu() // Fungsi untuk menampilkan menu pilihan kepada pengguna.
{
    cout << "Keluarga berencana" << endl; // Menampilkan judul program.
    cout << "1. Tambah anak" << endl; // Menampilkan pilihan menu untuk menambah anak.
    cout << "2. Tambah orang tua" << endl; // Menampilkan pilihan menu untuk menambah orang tua.
    cout << "3. Pilih orang tua untuk menambah anak" << endl; // Menampilkan pilihan menu untuk menambahkan anak ke orang tua tertentu.
    cout << "4. Hapus anak" << endl; // Menampilkan pilihan menu untuk menghapus anak.
    cout << "5. Hapus orang tua" << endl; // Menampilkan pilihan menu untuk menghapus orang tua beserta anak-anaknya.
    cout << "pilih: "; // Meminta pengguna untuk memilih opsi.
}

int main() // Fungsi utama program.
{
    ListChild LC; // Membuat objek list anak.
    ListParent LP; // Membuat objek list orang tua.
    createListChild(LC); // Menginisialisasi list anak kosong.
    createListParent(LP); // Menginisialisasi list orang tua kosong.

    int choice; // Variabel untuk menyimpan pilihan pengguna.
    string idChild, idParent, namaChild, namaParent; // Variabel untuk menyimpan ID dan nama anak/orang tua.

    do {
        cout << "view child" << endl; // Menampilkan judul "view child".
        viewChild(LC); // Menampilkan semua elemen anak pada list anak.
        cout << "\n" << endl; // Memberikan baris kosong.

        cout << "view parent" << endl; // Menampilkan judul "view parent".
        viewParent(LP); // Menampilkan semua elemen orang tua pada list orang tua.
        cout << "\n" << endl; // Memberikan baris kosong.

        cout << "view parentchild" << endl; // Menampilkan judul "view parentchild".
        viewParentChild(LP); // Menampilkan semua elemen orang tua dan anak-anaknya pada list orang tua.
        cout << "\n" << endl; // Memberikan baris kosong.

        printMenu(); // Menampilkan menu pilihan.
        cin >> choice; // Meminta pengguna untuk memasukkan pilihan.

        switch (choice) {
            case 1: // Jika pengguna memilih untuk menambah anak.
                cout << "Masukkan ID anak: "; // Meminta pengguna untuk memasukkan ID anak.
                cin >> idChild; // Menerima input ID anak.
                cout << "Masukkan nama anak: "; // Meminta pengguna untuk memasukkan nama anak.
                cin >> namaChild; // Menerima input nama anak.
                insertChild(LC, createElmChild({idChild, namaChild})); // Memasukkan elemen anak baru ke dalam list anak.
                break;

            case 2: // Jika pengguna memilih untuk menambah orang tua.
                cout << "Masukkan ID orang tua: "; // Meminta pengguna untuk memasukkan ID orang tua.
                cin >> idParent; // Menerima input ID orang tua.
                cout << "Masukkan nama orang tua: "; // Meminta pengguna untuk memasukkan nama orang tua.
                cin >> namaParent; // Menerima input nama orang tua.
                insertParent(LP, createElmParent({idParent, namaParent})); // Memasukkan elemen orang tua baru ke dalam list orang tua.
                break;

            case 3: // Jika pengguna memilih untuk menambahkan anak ke orang tua tertentu.
                cout << "Masukkan ID anak: "; // Meminta pengguna untuk memasukkan ID anak.
                cin >> idChild; // Menerima input ID anak.
                cout << "Masukkan ID orang tua: "; // Meminta pengguna untuk memasukkan ID orang tua.
                cin >> idParent; // Menerima input ID orang tua.
                addChild(LC, LP, idChild, idParent); // Menambahkan anak ke dalam list anak pada elemen orang tua tertentu.
                break;

            case 4: // Jika pengguna memilih untuk menghapus anak.
                cout << "Masukkan ID anak yang akan dihapus: "; // Meminta pengguna untuk memasukkan ID anak yang akan dihapus.
                cin >> idChild; // Menerima input ID anak.
                deleteChild(LC, LP, idChild); // Menghapus elemen anak berdasarkan ID anak yang diberikan.
                break;

            case 5: // Jika pengguna memilih untuk menghapus orang tua beserta anak-anaknya.
                cout << "Masukkan ID orang tua yang akan dihapus beserta semua anaknya: "; // Meminta pengguna untuk memasukkan ID orang tua yang akan dihapus.
                cin >> idParent; // Menerima input ID orang tua.
                deleteParent(LP, idParent); // Menghapus elemen orang tua beserta anak-anaknya berdasarkan ID orang tua yang diberikan.
                break;

            default: // Jika pengguna memasukkan pilihan yang tidak valid.
                cout << "Pilihan tidak valid!" << endl; // Menampilkan pesan bahwa pilihan tidak valid.
        }

        system("pause"); // Menampilkan prompt untuk menekan tombol apa saja untuk melanjutkan.
        system("cls"); // Membersihkan layar konsol.
    } while (choice != 0); // Perulangan akan berlanjut selama pengguna tidak memilih opsi 0 untuk keluar dari program.

    return 0; // Mengembalikan nilai 0 sebagai indikasi program berjalan dengan sukses.
}