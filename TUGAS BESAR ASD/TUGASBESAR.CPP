#include "TUGASBESAR.h"

// membuat daftar brand dengan brand pertama diatur menjadi NULL
void buatListBrand(list_brand &b) {
    b.pertama_brand = NULL;
}

adr_brand buatElmBrand(string id, string nama) {
    adr_brand p = new elm_brand;
    p->info_brand.id_brand = id; // untuk membuat sebuah tempat yang berisi id dan nama
    p->info_brand.nama_brand = nama;
    p->selanjutnya_brand = NULL; // mengatur pointer untuk relasi dan elemen berikutnya ke NULL
    p->produk.pertama_relasi = NULL;
    return p;
}

void buatListProduk(list_produk &p) {
    p.pertama_produk = NULL;
}

adr_produk buatElmProduk(string id, string nama, int harga) {
    adr_produk q = new elm_produk;
    q->info_produk.id_produk = id;
    q->info_produk.nama_produk = nama;
    q->info_produk.harga = harga;
    q->selanjutnya_produk = NULL;
    return q;
}

adr_relasi buatElmRelasi() {
    adr_relasi r = new elm_relasi;
    r->selanjutnya_produk = NULL;
    r->selanjutnya_relasi = NULL;
    return r;
}

// penerapan dari multilinkedlist
void tambahBrandPertama(list_brand &b, adr_brand p) {
    if(b.pertama_brand == NULL) {
        b.pertama_brand = p;
    } else {
        p->selanjutnya_brand = b.pertama_brand;
        b.pertama_brand = p;
    }
}

// void tambahBrandTerakhir(list_brand &b, adr_brand p) {
//     if(b.pertama_brand == NULL) {
//         b.pertama_brand = p;
//     } else {
//         adr_brand q = b.pertama_brand;
//         while(q->selanjutnya_brand != NULL) {
//             q = q->selanjutnya_brand;
//         }
//         q->selanjutnya_brand = p;
//     }
// }

// void tambahProdukPertama(list_produk &p, adr_produk q) {
//     if(p.pertama_produk == NULL) {
//         p.pertama_produk = q;
//     } else {
//         q->selanjutnya_produk = p.pertama_produk;
//         p.pertama_produk = q;
//     }
// }

//penerapan singly linked list insertlast
void tambahProdukTerakhir(list_produk &p, adr_produk q) {
    if(p.pertama_produk == NULL) {
        p.pertama_produk = q;
    } else {
        adr_produk r = p.pertama_produk;
        while(r->selanjutnya_produk != NULL) {
            r = r->selanjutnya_produk;
        }
        r->selanjutnya_produk = q;
    }
}

adr_brand cariBrand(list_brand b, string id) {
    adr_brand p = b.pertama_brand;
    while ((p->info_brand.id_brand != id) && (p->selanjutnya_brand != NULL)) {
        p = p->selanjutnya_brand;
    }
    if(p->info_brand.id_brand == id) {
        return p;
    } else {
        return NULL;
    }
}

adr_produk cariProduk(list_produk p, string id_produk) {
    adr_produk q = p.pertama_produk;
    while((q->info_produk.id_produk != id_produk) && (q->selanjutnya_produk != NULL)) {
        q = q->selanjutnya_produk;
    }
    if(q->info_produk.id_produk == id_produk) {
        return q;
    } else {
        return NULL;
    }
}

adr_relasi cariRelasi(list_relasi r, adr_produk p) {
    adr_relasi q = r.pertama_relasi;
    while((q->selanjutnya_relasi != NULL) && (q->selanjutnya_produk != p)) {
        q = q->selanjutnya_relasi;
    }
    if(q->selanjutnya_produk == p) {
        return q;
    } else {
        return NULL;
    }
}

void tambahProdukKeBrand(list_brand &b, list_produk &p, string id_brand, string id_produk) {
    adr_brand pb = cariBrand(b, id_brand);
    adr_produk pp = cariProduk(p, id_produk);
    if((pb != NULL) && (pp != NULL)) {
        adr_relasi r = buatElmRelasi();
        r->selanjutnya_produk = pp;
        if(pb->produk.pertama_relasi == NULL) {
            pb->produk.pertama_relasi = r;
        } else {
            adr_relasi t = pb->produk.pertama_relasi;
            while(t->selanjutnya_relasi != NULL) {
                t = t->selanjutnya_relasi;
            }
            t->selanjutnya_relasi = r;
        }
    }
}

void hapusProdukDariBrand(list_brand &b, string id_brand, string id_produk) {
    adr_brand pb = cariBrand(b, id_brand);
    if(pb != NULL) {
        if(pb->produk.pertama_relasi != NULL) {
            adr_relasi q = pb->produk.pertama_relasi;
            adr_relasi r = pb->produk.pertama_relasi;
            while((q->selanjutnya_produk->info_produk.id_produk != id_produk) && (q->selanjutnya_relasi != NULL)) {
                r = q;
                q = q->selanjutnya_relasi;
            }
            if(q->selanjutnya_produk->info_produk.id_produk == id_produk) {
                if(q == pb->produk.pertama_relasi) {
                    pb->produk.pertama_relasi = r->selanjutnya_relasi;
                    q->selanjutnya_relasi = NULL;
                } else if(q->selanjutnya_relasi == NULL) {
                    r->selanjutnya_relasi = NULL;
                } else {
                    r->selanjutnya_relasi = q->selanjutnya_relasi;
                    q->selanjutnya_relasi = NULL;
                }
                q->selanjutnya_produk = NULL;
            }
        }
    }
}

void hapusBrand(list_brand &b, string id_brand) {
    adr_brand p = cariBrand(b, id_brand);
    if(p != NULL) {
        p->produk.pertama_relasi = NULL;
        if(p == b.pertama_brand) {
            b.pertama_brand = p->selanjutnya_brand;
            p->selanjutnya_brand = NULL;
        } else {
            adr_brand q = b.pertama_brand;
            while(q->selanjutnya_brand != p) {
                q = q->selanjutnya_brand;
            }
            q->selanjutnya_brand = p->selanjutnya_brand;
            p->selanjutnya_brand = NULL;
        }
    }
}

void hapusProduk(list_brand &b, list_produk &p, string id_produk) {
    adr_produk q = cariProduk(p, id_produk);
    if (q != NULL) {
        adr_brand pb = b.pertama_brand;
        while(pb != NULL) {
            hapusProdukDariBrand(b, pb->info_brand.id_brand, id_produk);
            pb = pb->selanjutnya_brand;
        }
        if(q == p.pertama_produk) {
            p.pertama_produk = q->selanjutnya_produk;
            q->selanjutnya_produk = NULL;
        } else {
            adr_produk r = p.pertama_produk;
            while(r->selanjutnya_produk != q) {
                r = r->selanjutnya_produk;
            }
            r->selanjutnya_produk = q->selanjutnya_produk;
            q->selanjutnya_produk = NULL;
        }
    }
}

void cariProdukDariBrand(list_brand b, string id_brand) {
    adr_brand pb = cariBrand(b, id_brand);
    if (pb != NULL) {
        if (pb->produk.pertama_relasi != NULL) {
            adr_relasi r = pb->produk.pertama_relasi;
            while(r->selanjutnya_relasi != NULL) {
                cout<< "ID Produk \t: "<<r->selanjutnya_produk->info_produk.id_produk<<endl;
                cout<< "Nama Produk \t: "<<r->selanjutnya_produk->info_produk.nama_produk<<endl;
                cout<< "Harga \t\t: "<<r->selanjutnya_produk->info_produk.harga<<endl;
                cout<<""<<endl;
                r = r->selanjutnya_relasi;
            }
            cout<< "ID Produk \t: "<<r->selanjutnya_produk->info_produk.id_produk<<endl;
            cout<< "Nama Produk \t: "<<r->selanjutnya_produk->info_produk.nama_produk<<endl;
            cout<< "Harga \t\t: "<<r->selanjutnya_produk->info_produk.harga<<endl;
            cout<<""<<endl;
        } else {
            cout << "Brand " << id_brand << " tidak memiliki produk." << endl;
        }
    } else {
        cout << "Brand dengan ID " << id_brand << " tidak ditemukan." << endl;
    }
}

void cariBrandDariProduk(list_brand b, list_produk p, string id_produk) {
    adr_produk q = cariProduk(p, id_produk);
    if (q != NULL) {
        bool found = false;
        adr_brand pb = b.pertama_brand;
        while (pb != NULL) {
            if (pb->produk.pertama_relasi != NULL) {
                adr_relasi r = cariRelasi(pb->produk, q);
                if (r != NULL) {
                    cout<< "ID Brand \t: " << pb->info_brand.id_brand <<endl;
                    cout<< "Nama Brand \t: " << pb->info_brand.nama_brand <<endl;
                    cout<<""<<endl;
                    found = true;
                }
            }
            pb = pb->selanjutnya_brand;
        }
        if (!found) {
            cout << "Tidak ada brand yang menjual produk dengan ID " << id_produk << endl;
        }
    } else {
        cout << "Produk dengan ID " << id_produk << " tidak ditemukan" << endl;
    }
}

void tampilkanSemua(list_brand b) {
    adr_brand pb = b.pertama_brand;
    if (pb != NULL) {
        while(pb != NULL) {
            // cout << "============================================================" << endl;
            cout << " berikut data semuanya brand dan produk yang sudah terelasi " << endl;
            cout << "============================================================" << endl;
            cout<<"ID Brand \t: "<<pb->info_brand.id_brand<<endl;
            cout<<"Nama Brand \t: "<<pb->info_brand.nama_brand<<endl;
            cout<<""<<endl;
            if(pb->produk.pertama_relasi != NULL) {
                adr_relasi r = pb->produk.pertama_relasi;
                while(r != NULL) {
                    cout<<"ID Produk \t: "<<r->selanjutnya_produk->info_produk.id_produk<<endl;
                    cout<<"Nama Produk \t: "<<r->selanjutnya_produk->info_produk.nama_produk<<endl;
                    cout<<"Harga \t\t: "<<r->selanjutnya_produk->info_produk.harga<<endl;
                    cout<<""<<endl;
                    r = r->selanjutnya_relasi;
                }
            } else {
                cout << "Brand ini tidak memiliki produk." << endl;
            }
            cout<<""<<endl;
            pb = pb->selanjutnya_brand;
        }
    } else {
        cout << "Tidak ada brand yang tersedia." << endl;
    }
}

void brandDenganProdukTerbanyak(list_brand b) {
    adr_brand pb = b.pertama_brand;
    adr_brand brand_terbanyak = NULL;
    int max_produk = 0;

    while(pb != NULL) {
        int jumlah_produk = 0;
        if(pb->produk.pertama_relasi != NULL) {
            adr_relasi r = pb->produk.pertama_relasi;
            while(r != NULL) {
                jumlah_produk++;
                r = r->selanjutnya_relasi;
            }
        }
        if(jumlah_produk > max_produk) {
            max_produk = jumlah_produk;
            brand_terbanyak = pb;
        }
        pb = pb->selanjutnya_brand;
    }

    if(brand_terbanyak != NULL) {
        cout<<"Brand dengan produk terbanyak:"<<endl;
        cout<<"ID Brand \t: "<<brand_terbanyak->info_brand.id_brand<<endl;
        cout<<"Nama Brand \t: "<<brand_terbanyak->info_brand.nama_brand<<endl;
        cout<<"Jumlah Produk \t: "<<max_produk<<endl;
    } else {
        cout << "Tidak ada brand dengan produk" << endl;
    }
}


void brandDenganProdukTersedikit(list_brand b) {
    adr_brand pb = b.pertama_brand;
    adr_brand brand_tersedikit = NULL;
    int min_produk = INT_MAX;
    while(pb != NULL) {
        int jumlah_produk = 0;
        if(pb->produk.pertama_relasi != NULL) {
            adr_relasi r = pb->produk.pertama_relasi;
            while(r != NULL) {
                jumlah_produk++;
                r = r->selanjutnya_relasi;
            }
        }
        if(jumlah_produk < min_produk) {
            min_produk = jumlah_produk;
            brand_tersedikit = pb;
        }
        pb = pb->selanjutnya_brand;
    }
    if(brand_tersedikit != NULL) {
        cout<<"Brand dengan produk tersedikit:"<<endl;
        cout<<"ID Brand \t: "<<brand_tersedikit->info_brand.id_brand<<endl;
        cout<<"Nama Brand \t: "<<brand_tersedikit->info_brand.nama_brand<<endl;
        cout<<"Jumlah Produk \t: "<<min_produk<<endl;
    } else {
        cout << "Tidak ada brand dengan produk" << endl;
    }
}
// Implementasi untuk menampilkan semua brand
void tampilkanSemuaBrand(const list_brand &b) {
    adr_brand pb = b.pertama_brand;
    cout << "======================= List Brand =========================" << endl;
    while (pb != NULL) {
        cout << "[" << pb->info_brand.id_brand << "] nama brand: " << pb->info_brand.nama_brand << endl;
        pb = pb->selanjutnya_brand;
    }
    cout << "============================================================" << endl;
    cout << endl;
}

// Implementasi untuk menampilkan semua produk
void tampilkanSemuaProduk(const list_produk &p) {
    adr_produk pp = p.pertama_produk;
    cout << "======================= List Produk ========================" << endl;
    while (pp != NULL) {
        cout << "[" << pp->info_produk.id_produk << "] nama produk: " << pp->info_produk.nama_produk << endl;
        cout << "harga: " << pp->info_produk.harga << endl;
        pp = pp->selanjutnya_produk;
    }
    cout << "============================================================" << endl;

    cout << endl;
}

