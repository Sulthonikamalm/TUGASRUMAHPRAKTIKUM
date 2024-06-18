#include "TUGASBESAR.cpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <limits>

#undef WIN32_LEAN_AND_MEAN

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayMenu() {
    setColor(10);
    cout << "============================================================" << endl;
    cout << "|               Sistem Manajemen Brand Produk              |" << endl;
    cout << "============================================================" << endl;
    setColor(7);
    cout << "| 1. Tambahkan Brand Baru                                  |" << endl;
    cout << "| 2. Tambahkan Produk Baru                                 |" << endl;
    cout << "| 3. Tambahkan Brand dengan Produknya                      |" << endl;
    cout << "| 4. Hapus Brand                                           |" << endl;
    cout << "| 5. Hapus Produk                                          |" << endl;
    cout << "| 6. Lihat Semua Brand dan Produknya                       |" << endl;
    cout << "| 7. Lihat Produk dari Brand Tertentu                      |" << endl;
    cout << "| 8. Lihat Brand yang Menjual Produk                       |" << endl;
    cout << "| 9. Lihat Brand dengan Produk Terbanyak & Paling Sedikit  |" << endl;
    cout << "| 0. Keluar dari Sistem                                    |" << endl;
    setColor(10);
    cout << "============================================================" << endl;
    setColor(7);
    cout << "\nMasukkan pilihan Anda: ";
}

void displayData(list_brand &brands, list_produk &produk) {
    cout <<  "ini adalah data brand dan produk yang sesuai dengan insert firt dan insert last" << endl;
    tampilkanSemuaBrand(brands);
    tampilkanSemuaProduk(produk);
    cout << endl;
}

int main() {
    list_brand brands;
    list_produk produk;
    buatListBrand(brands);
    buatListProduk(produk);
    int pilihan;

    do {
        system("cls");
        displayMenu();
        cin >> pilihan;

        if (pilihan < 0 || pilihan > 9) {
            setColor(12); // Set warna teks merah
            cout << "Kode tidak valid, periksa lagi pilihan Anda." << endl;
            setColor(7); // Set warna teks putih
            cin.clear(); // Clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
            continue;
        }
        system("cls");

        switch (pilihan) {
            case 1: {
                string id, nama;
                cout << "Masukkan ID Brand: ";
                cin >> id;
                cout << "Masukkan Nama Brand: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                getline(cin, nama); // Read the entire line
                tambahBrandPertama(brands, buatElmBrand(id, nama));
                break;
                system("pause");
            }
            case 2: {
                string id, nama;
                int harga;
                cout << "Masukkan ID Produk: ";
                cin >> id;
                cout << "Masukkan Nama Produk: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                getline(cin, nama); // Read the entire line
                cout << "Masukkan Harga Produk: ";
                cin >> harga;
                tambahProdukTerakhir(produk, buatElmProduk(id, nama, harga));
                break;
                system("pause");
            }
            case 3: {
                string id_brand, id_produk;
                cout << "Masukkan ID Brand: ";
                cin >> id_brand;
                cout << "Masukkan ID Produk: ";
                cin >> id_produk;
                tambahProdukKeBrand(brands, produk, id_brand, id_produk);
                break;
                system("pause");
            }
            case 4: {
                string id;
                cout << "Masukkan ID Brand yang akan Dihapus: ";
                cin >> id;
                hapusBrand(brands, id);
                break;
                system("pause");
            }
            case 5: {
                string id;
                cout << "Masukkan ID Produk yang akan Dihapus: ";
                cin >> id;
                hapusProduk(brands, produk, id);
                break;
                system("pause");
            }
            case 6: {
                displayData(brands, produk);
                tampilkanSemua(brands);
                break;
                system("pause");
            }
            case 7: {
                string id;
                cout << "Masukkan ID Brand: ";
                cin >> id;
                cariProdukDariBrand(brands, id);
                system("pause");
                break;
            }
            case 8: {
                string id;
                cout << "Masukkan ID Produk: ";
                cin >> id;
                cariBrandDariProduk(brands, produk, id);
                system("pause");
                break;
            }
            case 9: {
                brandDenganProdukTerbanyak(brands);
                brandDenganProdukTersedikit(brands);
                system("pause");
                break;
            }
            case 0: {
                cout << "Terima kasih telah menggunakan sistem ini." << endl;
                break;
            }
            default: {
                setColor(12); // Set warna teks merah
                cout << "Kode tidak valid, periksa lagi pilihan Anda." << endl;
                setColor(7); // Set warna teks putih
                cin.clear(); // Clear input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
                break;
            }
        }

        if (pilihan != 0) {
            setColor(10);
            cout << endl << "Tekan enter untuk melanjutkan...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            
        }

    } while (pilihan != 0);

    return 0;
}
