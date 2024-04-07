/*
===============================================================================
Nama : Sulthonika Mahfudz Al Mujahidin
nim : 1202230023
===============================================================================
*/

#include "tugasrumahpr.h"  // Menginclude file header yang berisi definisi struktur data dan fungsi-fungsi yang dibutuhkan
#include "tugasrumahpr.cpp"  // Menginclude file implementasi dari fungsi-fungsi yang didefinisikan di "tugasrumahpr.h"
#include <iostream>  // Menginclude header untuk input/output
#include <iomanip>  // Menginclude header untuk manipulasi input/output

using namespace std;  // Menggunakan namespace std agar tidak perlu menulis std:: setiap kali

// Deklarasi array dataKelompok yang berisi informasi kelompok, termasuk nomor kelompok, nama kelompok, dan poin awal
Info dataKelompok[] = 
{ 
    {1, "Windows", 0}, 
    {2, "MacOs", 0}, 
    {3, "Linux", 0}, 
    {4, "Android", 0}, 
    {5, "IOS", 0}, 
    {6, "FreeBSD", 0}, 
    {7, "Chrome Os", 0}, 
    {8, "Solaris", 0}, 
    {9, "Ubuntu", 0} };

int main() {
    // Membuat list baru yang akan menyimpan informasi kelompok
    LinkList list;
    createList(list);

    // Menambahkan elemen-elemen (informasi kelompok) ke dalam list
    for (int i = 0; i < 9; i++) {
        address temp = createElm(dataKelompok[i]);  // Membuat elemen baru berdasarkan data di dataKelompok
        insertLast(list, temp);  // Menambahkan elemen baru ke akhir list
    }

    // Inisialisasi variabel sesi dan gameSelesai
    // Variabel sesi akan menyimpan nomor sesi saat ini
    // Variabel gameSelesai akan digunakan untuk mengontrol loop utama
    int sesi = 0;
    bool gameSelesai = false;

    do {
        // Membersihkan layar konsol dan menampilkan judul "GAMES ITERATION" serta nomor sesi saat ini
        system("cls");
        cout << "GAMES ITERATION" << endl;
        cout << "SESI [" << sesi << "]" << endl;
        // Menampilkan daftar kelompok beserta poin mereka saat ini
        view(list);
        cout << endl;

        // Meminta input dari pengguna, apakah ingin mengganti sesi (input 1) atau menyudahi dan mengurutkan (input 0)
        cout << "Tekan 1 untuk mengganti sesi dan tekan 0 untuk menyudahi dan mengurutkan untuk mengetahui pemenang !! : ";
        int input;
        cin >> input;

        // Jika pengguna memilih 1 (ingin mengganti sesi):
        if (input == 1) {
            // Increment nilai sesi, artinya sesi sekarang menjadi sesi selanjutnya
            // Misalnya, jika sesi saat ini adalah 0, maka setelah di-increment
            // nilai sesi akan menjadi 1 (sesi berikutnya)
            sesi = sesi + 1;

            // Meminta input poin untuk setiap kelompok
            // Loop ini akan berjalan sebanyak 9 kali, sekali untuk setiap kelompok
            for (int i = 0; i < 9; i++) {
                // Menampilkan nomor dan nama kelompok, lalu meminta pengguna
                // memasukkan poin tambahan untuk kelompok tersebut
                cout << dataKelompok[i].noKelompok << ". " << dataKelompok[i].namaKelompok << ": ";
                int tambahPoin;
                cin >> tambahPoin;

                // Menambahkan poin yang diinput oleh pengguna ke poin kelompok saat ini
                // Misalnya, jika poin kelompok saat ini adalah 10, dan pengguna
                // memasukkan poin tambahan 5, maka poin kelompok akan menjadi 15
                dataKelompok[i].poinKelompok += tambahPoin;
            }

            // Memperbarui poin kelompok pada list
            // Menyimpan referensi ke elemen pertama (head) dari list
            address temp = list.first;

            // Melakukan loop untuk menelusuri seluruh elemen dalam list
            do {
                // Loop untuk memeriksa setiap kelompok dalam array dataKelompok
                for (int i = 0; i < 9; i++) {
                    // Memeriksa apakah nomor kelompok pada elemen saat ini di list
                    // sama dengan nomor kelompok pada array dataKelompok
                    if (temp->info.noKelompok == dataKelompok[i].noKelompok) {
                        // Jika sama, maka perbarui poin kelompok pada elemen list
                        // dengan poin kelompok yang terdapat pada array dataKelompok
                        temp->info.poinKelompok = dataKelompok[i].poinKelompok;

                        // Setelah memperbarui poin, langsung keluar dari loop for
                        // agar tidak melakukan pengecekan lagi untuk elemen yang sama
                        break;
                    }
                }

                // Pindah ke elemen selanjutnya di dalam list
                temp = temp->next;

            // Lakukan loop terus-menerus sampai temp kembali ke elemen pertama (head) list
            } while (temp != list.first);

            // Memutar urutan list, agar urutannya berbeda dari sesi sebelumnya
            putar(list);
        }
        // Jika pengguna memilih 0 (ingin menyudahi dan mengurutkan):
        else if (input == 0) {
            char pilihan;
            cout << "|=========================================================================|" << endl;
            cout << "                             GAME SUDAH SELESAI                            " << endl;
            cout << "|=========================================================================|" << endl;
            cout << "Apakah Anda ingin mengetahui siapa pemenang diantara daftar kelompok ? [y/n]: ";
            cin >> pilihan;

            // Jika pengguna memilih 'y' (ya, ingin mengetahui pemenang):
            if (tolower(pilihan) == 'y') {
                system("cls");
                cout << "POINT TERBESAR DAN MENJADI PEMENANG !!!" << endl;
                cout << "DI EVENT GAMES ITERATION" << endl;
                cout << "DI SESI [" << sesi << "]" << endl;
                urutkan(list);  // Mengurutkan list berdasarkan poin terbesar
                view(list);  // Menampilkan daftar kelompok yang sudah diurutkan
                gameSelesai = true;  // Mengubah gameSelesai menjadi true, sehingga loop utama akan berhenti
            }
            // Jika pengguna memilih 'n' (tidak, tidak ingin mengetahui pemenang):
            else if (tolower(pilihan) == 'n') {
                system("cls");
                cout << "Data Kelompok:" << endl;
                gameSelesai = false;  // Membiarkan gameSelesai tetap false, sehingga loop utama akan tetap berjalan
            }
            // Jika input pengguna salah, tampilkan pesan error:
            else {
                system("cls");
                cout << "Pilihan yang anda masukan salah!" << endl;
                gameSelesai = false;  // Membiarkan gameSelesai tetap false, sehingga loop utama akan tetap berjalan
            }
        }
        // Jika input pengguna selain 1 atau 0, tampilkan pesan error:
        else {
            cout << "Pilihan yang anda masukan salah!" << endl;
            gameSelesai = false;  // Membiarkan gameSelesai tetap false, sehingga loop utama akan tetap berjalan
        }
    } while (!gameSelesai);

    // Setelah loop utama selesai, menunggu pengguna menekan Enter untuk keluar
    cout << "Tekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}