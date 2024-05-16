#include "multi_list_MtoN.h" // Mengimpor file header "multi_list_MtoN.h" yang berisi deklarasi struktur data dan fungsi-fungsi yang digunakan dalam program ini.

#include <iostream> // Mengimpor library standar iostream untuk melakukan operasi input/output seperti cout dan cin.
#include <string> // Mengimpor library standar string untuk bekerja dengan tipe data string.

using namespace std; // Menggunakan namespace std untuk mengakses elemen-elemen dalam namespace std secara langsung tanpa harus menuliskan std::.

void createListChild(ListChild &LC) // Fungsi untuk membuat list anak yang kosong.
{
    LC.first_Child = NULL; // Mengosongkan pointer first_Child dari list anak.
}

void createListParent(ListParent &LP) // Fungsi untuk membuat list orang tua yang kosong.
{
    LP.first_Parent = NULL; // Mengosongkan pointer first_Parent dari list orang tua.
}

adr_child createElmChild(InfoChild info) // Fungsi untuk membuat elemen baru pada list anak dengan informasi yang diberikan.
{
    adr_child c = new ElmChild; // Membuat objek baru dari tipe ElmChild dan menyimpan alamatnya di pointer c.
    c->info = info; // Menyalin informasi anak yang diberikan ke dalam elemen baru.
    c->next_child = NULL; // Mengosongkan pointer next_child dari elemen baru.
    return c; // Mengembalikan alamat elemen baru yang dibuat.
}

adr_parent createElmParent(InfoParent info) // Fungsi untuk membuat elemen baru pada list orang tua dengan informasi yang diberikan.
{
    adr_parent p = new ElmParent; // Membuat objek baru dari tipe ElmParent dan menyimpan alamatnya di pointer p.
    p->info = info; // Menyalin informasi orang tua yang diberikan ke dalam elemen baru.
    p->next_parent = NULL; // Mengosongkan pointer next_parent dari elemen baru.
    p->child.first_Child = NULL; // Mengosongkan pointer first_Child dari list anak pada elemen orang tua baru.
    return p; // Mengembalikan alamat elemen baru yang dibuat.
}

void insertChild(ListChild &LC, adr_child c) // Fungsi untuk memasukkan elemen anak baru ke dalam list anak.
{
    if (LC.first_Child == NULL) // Jika list anak kosong.
    {
        LC.first_Child = c; // Elemen baru menjadi elemen pertama pada list anak.
    }
    else // Jika list anak tidak kosong.
    {
        adr_child p = LC.first_Child; // Pointer p menunjuk ke elemen pertama pada list anak.
        while (p->next_child != NULL) // Perulangan untuk mencari elemen terakhir pada list anak.
        {
            p = p->next_child; // Pointer p berpindah ke elemen berikutnya.
        }
        p->next_child = c; // Elemen baru ditambahkan setelah elemen terakhir pada list anak.
    }
}

void insertParent(ListParent &LP, adr_parent p) // Fungsi untuk memasukkan elemen orang tua baru ke dalam list orang tua.
{
    if (LP.first_Parent == NULL) // Jika list orang tua kosong.
    {
        LP.first_Parent = p; // Elemen baru menjadi elemen pertama pada list orang tua.
    }
    else // Jika list orang tua tidak kosong.
    {
        adr_parent q = LP.first_Parent; // Pointer q menunjuk ke elemen pertama pada list orang tua.
        while (q->next_parent != NULL) // Perulangan untuk mencari elemen terakhir pada list orang tua.
        {
            q = q->next_parent; // Pointer q berpindah ke elemen berikutnya.
        }
        q->next_parent = p; // Elemen baru ditambahkan setelah elemen terakhir pada list orang tua.
    }
}

adr_child searchChild(ListChild LC, string idChild) // Fungsi untuk mencari elemen anak berdasarkan ID anak yang diberikan.
{
    if (LC.first_Child == NULL) // Jika list anak kosong.
    {
        return NULL; // Mengembalikan NULL karena elemen tidak ditemukan.
    }
    else // Jika list anak tidak kosong.
    {
        adr_child c = LC.first_Child; // Pointer c menunjuk ke elemen pertama pada list anak.
        while ((c->next_child != NULL) && (c->info.idChild != idChild)) // Perulangan untuk mencari elemen dengan ID anak yang sesuai.
        {
            c = c->next_child; // Pointer c berpindah ke elemen berikutnya.
        }
        if (c->info.idChild == idChild) // Jika elemen dengan ID anak yang sesuai ditemukan.
        {
            return c; // Mengembalikan alamat elemen yang ditemukan.
        }
        else // Jika elemen tidak ditemukan.
        {
            return NULL; // Mengembalikan NULL.
        }
    }
}

adr_parent searchParent(ListParent LP, string idParent) // Fungsi untuk mencari elemen orang tua berdasarkan ID orang tua yang diberikan.
{
    if (LP.first_Parent == NULL) // Jika list orang tua kosong.
    {
        return NULL; // Mengembalikan NULL karena elemen tidak ditemukan.
    }
    else // Jika list orang tua tidak kosong.
    {
        adr_parent p = LP.first_Parent; // Pointer p menunjuk ke elemen pertama pada list orang tua.
        while ((p->next_parent != NULL) && (p->info.idParent != idParent)) // Perulangan untuk mencari elemen dengan ID orang tua yang sesuai.
        {
            p = p->next_parent; // Pointer p berpindah ke elemen berikutnya.
        }
        if (p->info.idParent == idParent) // Jika elemen dengan ID orang tua yang sesuai ditemukan.
        {
            return p; // Mengembalikan alamat elemen yang ditemukan.
        }
        else // Jika elemen tidak ditemukan.
        {
            return NULL; // Mengembalikan NULL.
        }
    }
}

void addChild(ListChild &LC, ListParent &LP, string idChild, string idParent)
{
    adr_child c, q;
    adr_parent p;
    c = searchChild(LC, idChild); // Mencari elemen anak berdasarkan ID anak yang diberikan.
    p = searchParent(LP, idParent); // Mencari elemen orang tua berdasarkan ID orang tua yang diberikan.
    if ((c != NULL) && (p != NULL)) // Jika elemen anak dan elemen orang tua ditemukan.
    {
        q = createElmChild(c->info); // Membuat elemen anak baru dengan informasi yang sama seperti elemen anak yang ditemukan.
        insertChild(p->child, q); // Memasukkan elemen anak baru ke dalam list anak pada elemen orang tua yang ditemukan.
    }
}

void viewParent(ListParent &LP) // Fungsi untuk menampilkan semua elemen orang tua pada list orang tua.
{
    if (LP.first_Parent == NULL) // Jika list orang tua kosong.
    {
        cout << "Kosong"; // Menampilkan pesan "Kosong".
    }
    else // Jika list orang tua tidak kosong.
    {
        adr_parent p = LP.first_Parent; // Pointer p menunjuk ke elemen pertama pada list orang tua.
        while (p->next_parent != NULL) // Perulangan untuk menampilkan semua elemen orang tua kecuali elemen terakhir.
        {
            cout << "[" << p->info.idParent << "," << p->info.NamaParent << "] "; // Menampilkan ID dan Nama orang tua.
            p = p->next_parent; // Pointer p berpindah ke elemen berikutnya.
        }
        cout << "[" << p->info.idParent << "," << p->info.NamaParent << "]"; // Menampilkan ID dan Nama orang tua untuk elemen terakhir.
    }
}

void viewChild(ListChild &LC) // Fungsi untuk menampilkan semua elemen anak pada list anak dengan warna hijau.
{
    cout << "\033[32m"; // Mengubah warna teks menjadi hijau.
    if (LC.first_Child == NULL) // Jika list anak kosong.
    {
        cout << "Kosong"; // Menampilkan pesan "Kosong".
    }
    else // Jika list anak tidak kosong.
    {
        adr_child c = LC.first_Child; // Pointer c menunjuk ke elemen pertama pada list anak.
        while (c->next_child != NULL) // Perulangan untuk menampilkan semua elemen anak kecuali elemen terakhir.
        {
            cout << "[" << c->info.idChild << "," << c->info.NamaChild << "] "; // Menampilkan ID dan Nama anak.
            c = c->next_child; // Pointer c berpindah ke elemen berikutnya.
        }
        cout << "[" << c->info.idChild << "," << c->info.NamaChild << "]"; // Menampilkan ID dan Nama anak untuk elemen terakhir.
    }
    cout << "\033[33m"; // Mengubah warna teks menjadi kuning.
}

void viewParentChild(ListParent &LP) // Fungsi untuk menampilkan semua elemen orang tua dan anak-anaknya pada list orang tua.
{
    if (LP.first_Parent == NULL) // Jika list orang tua kosong.
    {
        cout << "Kosong"; // Menampilkan pesan "Kosong".
    }
    else // Jika list orang tua tidak kosong.
    {
        adr_parent p = LP.first_Parent; // Pointer p menunjuk ke elemen pertama pada list orang tua.
        while (p->next_parent != NULL) // Perulangan untuk menampilkan semua elemen orang tua dan anak-anaknya kecuali elemen terakhir.
        {
            cout << "[" << p->info.idParent << "," << p->info.NamaParent << " ( "; // Menampilkan ID dan Nama orang tua.
            viewChild(p->child); // Menampilkan semua anak pada elemen orang tua saat ini.
            cout << " )] "; // Menutup tampilan anak-anak pada elemen orang tua saat ini.
            p = p->next_parent; // Pointer p berpindah ke elemen berikutnya.
        }
        cout << "[" << p->info.idParent << "," << p->info.NamaParent << " ( "; // Menampilkan ID dan Nama orang tua untuk elemen terakhir.
        viewChild(p->child); // Menampilkan semua anak pada elemen orang tua terakhir.
        cout << " )] "; // Menutup tampilan anak-anak pada elemen orang tua terakhir.
    }
}

void deleteAfterParent(ListParent &LP, string idParent) // Fungsi untuk menghapus elemen orang tua setelah elemen dengan ID orang tua yang diberikan.
{
    if (LP.first_Parent == NULL) return; // Jika list orang tua kosong, fungsi akan keluar.

    adr_parent temp = LP.first_Parent; // Pointer temp menunjuk ke elemen pertama pada list orang tua.
    if (temp->info.idParent == idParent) // Jika elemen pertama memiliki ID orang tua yang sesuai.
    {
        LP.first_Parent = temp->next_parent; // Elemen pertama dihapus dengan mengubah pointer first_Parent menjadi elemen berikutnya.
        delete temp; // Menghapus elemen yang ditunjuk oleh pointer temp.
        return; // Keluar dari fungsi.
    }

    adr_parent prev = NULL; // Pointer prev diinisialisasi dengan NULL.
    while (temp != NULL && temp->info.idParent != idParent) // Perulangan untuk mencari elemen dengan ID orang tua yang sesuai.
    {
        prev = temp; // Pointer prev menunjuk ke elemen saat ini.
        temp = temp->next_parent; // Pointer temp berpindah ke elemen berikutnya.
    }

    if (temp != NULL) // Jika elemen dengan ID orang tua yang sesuai ditemukan.
    {
        prev->next_parent = temp->next_parent; // Menghapus elemen dengan mengubah pointer next_parent dari elemen sebelumnya menjadi elemen setelah elemen yang dihapus.
        delete temp; // Menghapus elemen yang ditunjuk oleh pointer temp.
    }
}

void deleteParent(ListParent &LP, string idParent)
{
    adr_parent p = searchParent(LP, idParent); // Mencari elemen orang tua berdasarkan ID orang tua yang diberikan.
    if (p != NULL) // Jika elemen orang tua ditemukan.
    {
        while (p->child.first_Child != NULL) // Perulangan untuk menghapus semua anak pada elemen orang tua.
        {
            deleteAfterChild(p->child, p->child.first_Child->info.idChild); // Menghapus anak pertama pada elemen orang tua.
        }
        deleteAfterParent(LP, idParent); // Menghapus elemen orang tua setelah menghapus semua anaknya.
    }
}

void deleteAfterChild(ListChild &LC, string idChild) // Fungsi untuk menghapus elemen anak setelah elemen dengan ID anak yang diberikan.
{
    if (LC.first_Child == NULL) return; // Jika list anak kosong, fungsi akan keluar.

    adr_child temp = LC.first_Child; // Pointer temp menunjuk ke elemen pertama pada list anak.
    if (temp->info.idChild == idChild) // Jika elemen pertama memiliki ID anak yang sesuai.
    {
        LC.first_Child = temp->next_child; // Elemen pertama dihapus dengan mengubah pointer first_Child menjadi elemen berikutnya.
        delete temp; // Menghapus elemen yang ditunjuk oleh pointer temp.
        return; // Keluar dari fungsi.
    }

    adr_child prev = NULL; // Pointer prev diinisialisasi dengan NULL.
    while (temp != NULL && temp->info.idChild != idChild) // Perulangan untuk mencari elemen dengan ID anak yang sesuai.
    {
        prev = temp; // Pointer prev menunjuk ke elemen saat ini.
        temp = temp->next_child; // Pointer temp berpindah ke elemen berikutnya.
    }

    if (temp != NULL) // Jika elemen dengan ID anak yang sesuai ditemukan.
    {
        prev->next_child = temp->next_child; // Menghapus elemen dengan mengubah pointer next_child dari elemen sebelumnya menjadi elemen setelah elemen yang dihapus.
        delete temp; // Menghapus elemen yang ditunjuk oleh pointer temp.
    }
}

void deleteChild(ListChild &LC, ListParent &LP, string idChild) // Fungsi untuk menghapus elemen anak berdasarkan ID anak yang diberikan.
{
    deleteAfterChild(LC, idChild); // Menghapus elemen anak dari list anak utama.

    adr_parent p = LP.first_Parent; // Pointer p menunjuk ke elemen pertama pada list orang tua.
    while (p != NULL) // Perulangan untuk menghapus elemen anak dari list anak setiap elemen orang tua.
    {
        deleteAfterChild(p->child, idChild); // Menghapus elemen anak dari list anak pada elemen orang tua saat ini.
        p = p->next_parent; // Pointer p berpindah ke elemen berikutnya.
    }
}