#include "Tugasrumahmulltilistvar2.h"  // Memasukkan header file yang berisi definisi struktur dan fungsi.

// Membuat list baru untuk toko.
void createListToko(list_toko &t) {
    t.first_toko = NULL;  // Inisialisasi list toko dengan null, menunjukkan list kosong.
}

// Membuat elemen baru untuk toko.
adr_toko createElmToko(string id, string nama) {
    adr_toko p = new elm_toko;  // Membuat node baru.
    p->info_toko.id_toko = id;  // Menyimpan ID toko.
    p->info_toko.nama_toko = nama;  // Menyimpan nama toko.
    p->next_toko = NULL;  // Inisialisasi pointer next dengan null.
    p->barang.first_relation = NULL;  // Inisialisasi list barang dalam toko dengan null.
    return p;  // Mengembalikan node yang baru dibuat.
}

// Membuat list baru untuk barang.
void createListBarang(list_barang &b) {
    b.first_barang = NULL;  // Inisialisasi list barang dengan null, menunjukkan list kosong.
}

// Membuat elemen baru untuk barang.
adr_barang createElmBarang(string id, string nama, int harga) {
    adr_barang q = new elm_barang;  // Membuat node baru.
    q->info_barang.id_barang = id;  // Menyimpan ID barang.
    q->info_barang.nama_barang = nama;  // Menyimpan nama barang.
    q->info_barang.harga = harga;  // Menyimpan harga barang.
    q->next_barang = NULL;  // Inisialisasi pointer next dengan null.
    return q;  // Mengembalikan node yang baru dibuat.
}

// Membuat elemen baru untuk relasi antara toko dan barang.
adr_relation createElmRelation() {
    adr_relation r = new elm_relation;  // Membuat node baru untuk relasi.
    r->next_barang = NULL;  // Menunjuk barang dengan null.
    r->next_relation = NULL;  // Menunjuk relasi berikutnya dengan null.
    return r;  // Mengembalikan node yang baru dibuat.
}

// Memasukkan toko baru ke dalam list toko.
void insertToko(list_toko &t, adr_toko p) {
    if (t.first_toko == NULL) {  // Jika list toko kosong,
        t.first_toko = p;  // toko baru menjadi toko pertama.
    } else {  // Jika list tidak kosong,
        adr_toko q = t.first_toko;  // Mulai dari toko pertama.
        while (q->next_toko != NULL) {  // Cari toko terakhir di list.
            q = q->next_toko;  // Lanjut ke toko berikutnya.
        }
        q->next_toko = p;  // Menambahkan toko baru di akhir list.
    }
}

// Memasukkan barang baru ke dalam list barang.
void insertBarang(list_barang &b, adr_barang q) {
    if (b.first_barang == NULL) {  // Jika list barang kosong,
        b.first_barang = q;  // barang baru menjadi barang pertama.
    } else {  // Jika list tidak kosong,
        q->next_barang = b.first_barang;  // Barang baru menunjuk ke barang pertama saat ini.
        b.first_barang = q;  // Menjadikan barang baru sebagai barang pertama.
    }
}

// Mencari toko berdasarkan ID.
adr_toko searchToko(list_toko t, string id) {
    adr_toko p = t.first_toko;  // Mulai dari toko pertama.
    while (p != NULL && p->info_toko.id_toko != id) {  // Mencari toko dengan ID yang cocok.
        p = p->next_toko;  // Lanjut ke toko berikutnya.
    }
    return p;  // Mengembalikan alamat toko yang dicari atau null jika tidak ditemukan.
}

// Mencari barang berdasarkan ID.
adr_barang searchBarang(list_barang b, string id) {
    adr_barang q = b.first_barang;  // Mulai dari barang pertama.
    while (q != NULL && q->info_barang.id_barang != id) {  // Mencari barang dengan ID yang cocok.
        q = q->next_barang;  // Lanjut ke barang berikutnya.
    }
    return q;  // Mengembalikan alamat barang yang dicari atau null jika tidak ditemukan.
}

// Mencari relasi antara toko dan barang berdasarkan barang.
adr_relation searchRelation(list_relation r, adr_barang p) {
    adr_relation q = r.first_relation;  // Mulai dari relasi pertama.
    while (q != NULL && q->next_barang != p) {  // Mencari relasi yang menunjuk ke barang yang cocok.
        q = q->next_relation;  // Lanjut ke relasi berikutnya.
    }
    return q;  // Mengembalikan alamat relasi yang dicari atau null jika tidak ditemukan.
}
// Menambahkan barang ke toko tertentu.
void addBarang(list_toko &t, list_barang &b, string id_toko, string id_barang) {
    adr_toko p = searchToko(t, id_toko);  // Cari toko dengan ID yang diberikan.
    adr_barang q = searchBarang(b, id_barang);  // Cari barang dengan ID yang diberikan.
    if (p != NULL && q != NULL) {  // Jika toko dan barang ditemukan,
        adr_relation r = createElmRelation();  // Buat elemen relasi baru.
        r->next_barang = q;  // Set barang dalam relasi.
        if (p->barang.first_relation == NULL) {  // Jika belum ada relasi di toko ini,
            p->barang.first_relation = r;  // Set relasi baru sebagai yang pertama.
        } else {  // Jika sudah ada relasi,
            adr_relation s = p->barang.first_relation;  // Mulai dari relasi pertama.
            while (s->next_relation != NULL) {  // Cari relasi terakhir.
                s = s->next_relation;  // Lanjut ke relasi berikutnya.
            }
            s->next_relation = r;  // Tambahkan relasi baru di akhir.
        }
    }
}

// Menghapus barang dari toko tertentu.
void deleteBarangToko(list_toko &t, string id_toko, string id_barang) {
    adr_toko p = searchToko(t, id_toko);  // Cari toko dengan ID yang diberikan.
    if (p != NULL) {  // Jika toko ditemukan,
        if (p->barang.first_relation != NULL) {  // Jika ada relasi barang,
            adr_relation q = p->barang.first_relation;  // Mulai dari relasi pertama.
            adr_relation r = NULL;  // Penunjuk untuk menyimpan relasi sebelumnya.
            while (q != NULL && q->next_barang->info_barang.id_barang != id_barang) {  // Cari barang dalam relasi.
                r = q;  // Simpan relasi sebelumnya.
                q = q->next_relation;  // Lanjut ke relasi berikutnya.
            }
            if (q != NULL && q->next_barang->info_barang.id_barang == id_barang) {  // Jika barang ditemukan dalam relasi,
                if (q == p->barang.first_relation) {  // Jika ini relasi pertama,
                    p->barang.first_relation = q->next_relation;  // Pindahkan kepala relasi ke yang berikutnya.
                } else if (q->next_relation == NULL) {  // Jika ini relasi terakhir,
                    r->next_relation = NULL;  // Akhiri rantai relasi.
                } else {  // Jika berada di tengah,
                    r->next_relation = q->next_relation;  // Lompati relasi ini.
                }
                // Hapus relasi dari memori.
                delete q;
            }
        }
    }
}

// Menghapus toko dari list.
void deleteToko(list_toko &t, string id_toko) {
    adr_toko p = searchToko(t, id_toko);  // Cari toko dengan ID yang diberikan.
    if (p != NULL) {  // Jika toko ditemukan,
        if (p == t.first_toko) {  // Jika ini toko pertama,
            t.first_toko = p->next_toko;  // Pindahkan kepala list ke toko berikutnya.
        } else {  // Jika bukan toko pertama,
            adr_toko q = t.first_toko;  // Mulai dari toko pertama.
            while (q->next_toko != p) {  // Cari toko sebelumnya.
                q = q->next_toko;  // Lanjut ke toko berikutnya.
            }
            q->next_toko = p->next_toko;  // Lompati toko ini dalam list.
        }
        // Hapus semua relasi barang di toko.
        while (p->barang.first_relation != NULL) {
            adr_relation r = p->barang.first_relation;
            p->barang.first_relation = r->next_relation;
            delete r;
        }
        delete p;  // Hapus toko dari memori.
    }
}

// Menghapus barang dari semua toko.
void deleteBarang(list_toko &t, list_barang &b, string id_barang) {
    adr_barang p = searchBarang(b, id_barang);  // Cari barang dengan ID yang diberikan.
    if (p != NULL) {  // Jika barang ditemukan,
        adr_toko q = t.first_toko;  // Mulai dari toko pertama.
        while (q != NULL) {  // Iterasi melalui setiap toko.
            deleteBarangToko(t, q->info_toko.id_toko, id_barang);  // Hapus barang dari setiap toko.
            q = q->next_toko;  // Lanjut ke toko berikutnya.
        }
        // Hapus barang dari list barang.
        if (p == b.first_barang) {  // Jika barang adalah barang pertama,
            b.first_barang = p->next_barang;  // Pindahkan kepala list ke barang berikutnya.
        } else {  // Jika bukan barang pertama,
            adr_barang r = b.first_barang;  // Mulai dari barang pertama.
            while (r->next_barang != p) {  // Cari barang sebelumnya.
                r = r->next_barang;  // Lanjut ke barang berikutnya.
            }
            r->next_barang = p->next_barang;  // Lompati barang ini dalam list.
        }
        delete p;  // Hapus barang dari memori.
    }
}

// Menampilkan informasi barang dari toko tertentu.
void searchBarangFromToko(list_toko t, string id_toko) {
    adr_toko p = searchToko(t, id_toko);  // Cari toko dengan ID yang diberikan.
    if (p != NULL) {  // Jika toko ditemukan,
        if (p->barang.first_relation != NULL) {  // Jika ada relasi barang,
            adr_relation r = p->barang.first_relation;  // Mulai dari relasi pertama.
            while (r != NULL) {  // Iterasi melalui setiap relasi.
                cout << "ID Barang \t: " << r->next_barang->info_barang.id_barang << endl;
                cout << "Nama Barang \t: " << r->next_barang->info_barang.nama_barang << endl;
                cout << "Harga \t\t: " << r->next_barang->info_barang.harga << endl;
                cout << "" << endl;
                r = r->next_relation;  // Lanjut ke relasi berikutnya.
            }
        }
    }
}

// Mencari toko yang menjual barang tertentu.
void searchTokoFromBarang(list_toko t, list_barang b, string id_barang) {
    adr_barang q = searchBarang(b, id_barang);  // Cari barang dengan ID yang diberikan.
    if (q != NULL) {  // Jika barang ditemukan,
        adr_toko p = t.first_toko;  // Mulai dari toko pertama.
        while (p != NULL) {  // Iterasi melalui setiap toko.
            if (p->barang.first_relation != NULL) {  // Jika toko memiliki relasi dengan barang,
                adr_relation r = searchRelation(p->barang, q);  // Cari relasi yang spesifik untuk barang ini.
                if (r != NULL) {  // Jika relasi ditemukan,
                    cout << "ID Toko \t: " << p->info_toko.id_toko << endl;
                    cout << "Nama Toko \t: " << p->info_toko.nama_toko << endl;
                    cout << "" << endl;
                }
            }
            p = p->next_toko;  // Lanjut ke toko berikutnya.
        }
    }
}

// Menampilkan semua data toko dan barang yang terkait.
void viewAll(list_toko t) {
    adr_toko p = t.first_toko;  // Mulai dari toko pertama.
    if (p != NULL) {  // Jika ada toko,
        while (p != NULL) {  // Iterasi melalui setiap toko.
            cout << "==========================" << endl;
            cout << "Id Toko \t: " << p->info_toko.id_toko << endl;
            cout << "Nama Toko \t: " << p->info_toko.nama_toko << endl;
            cout << "" << endl;
            if (p->barang.first_relation != NULL) {  // Jika toko memiliki relasi dengan barang,
                adr_relation q = p->barang.first_relation;  // Mulai dari relasi pertama.
                while (q != NULL) {  // Iterasi melalui setiap relasi.
                    cout << "Id Barang \t: " << q->next_barang->info_barang.id_barang << endl;
                    cout << "Nama Barang \t: " << q->next_barang->info_barang.nama_barang << endl;
                    cout << "Harga \t\t: " << q->next_barang->info_barang.harga << endl;
                    cout << "" << endl;
                    q = q->next_relation;  // Lanjut ke relasi berikutnya.
                }
                cout << "" << endl;
            }
            p = p->next_toko;  // Lanjut ke toko berikutnya.
        }
    }
}
