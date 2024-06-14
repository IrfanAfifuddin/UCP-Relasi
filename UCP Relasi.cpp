#include <iostream>
#include <vector>
using namespace std;

class Penerbit;
class Namapenerbit {
public:
    string nama;
    vector<Penerbit*> daftar_Penerbit;
    Namapenerbit(string pNama) :nama(pNama) {
        cout << "Penerbit \"" << nama << "\" ada\n";
    }
    ~Namapenerbit() {
        cout << "Penerbit \"" << nama << "\" tidak ada\n";
    }
    void tambahPenerbit(Penerbit*);
    void cetakPenerbit(); 
};

class Penerbit {
public:
    string nama;
    vector<Namapenerbit*> daftar_Namapenerbit;

    Penerbit(string pNama) :nama(pNama) {
        cout << "Namapenerbit \"" << nama << "\" ada\n";
    }
    ~Penerbit() {
        cout << "Namapenerbit \"" << nama << "\" tidak ada\n";
    }
    void tambahNamapenerbit(Namapenerbit*);
    void cetakNamapenerbit();
};

class Pengarang;
class Namapengarang {
public:
    string nama;
    vector<Pengarang*> daftar_Pengarang;
    Namapengarang(string pNama) :nama(pNama) {
        cout << "Pengarang \"" << nama << "\" ada\n";
    }
    ~Namapengarang() {
        cout << "Pengarang \"" << nama << "\" tidak ada\n";
    }
    void tambahPengarang(Pengarang*);
    void cetakPengarang();
};

class Pengarang {
public:
    string nama;
    vector<Namapengarang*> daftar_Namapengarang;

    Pengarang(string pNama) :nama(pNama) {
        cout << "Namapengarang \"" << nama << "\" ada\n";
    }
    ~Pengarang() {
        cout << "Namapengarang \"" << nama << "\" tidak ada\n";
    }
    void tambahNamapenerbit(Namapenerbit*);
    void cetakNamapenerbit();
};

class Buku;
class Judulbuku {
public:
    string nama;
    vector<Buku*> daftar_Buku;
    Judulbuku(string pNama) :nama(pNama) {
        cout << "Buku \"" << nama << "\" ada\n";
    }
    ~Judulbuku() {
        cout << "Buku \"" << nama << "\" tidak ada\n";
    }
    void tambahBuku(Buku*);
    void cetakBuku();
};

class Buku {
public:
    string nama;
    vector<Judulbuku*> daftar_Judulbuku;

    Buku(string pNama) :nama(pNama) {
        cout << "Judulbuku \"" << nama << "\" ada\n";
    }
    ~Buku() {
        cout << "Judulbuku \"" << nama << "\" tidak ada\n";
    }
    void tambahJudulbukut(Judulbuku*);
    void cetakJudulbuku();
};

void Namapenerbit::tambahPenerbit(Penerbit* Penerbit) {
    daftar_Penerbit.push_back(Penerbit);
}
void Namapenerbit::cetakPenerbit() {
    cout << "Daftarnama Buku Yang Diterbitkan \"" << this->nama << "\":\n";
    for (auto& a : daftar_Penerbit) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void Penerbit:: tambahPenerbit(Namapenerbit* pNamapenerbit) {
    daftar_Namapenerbit.push_back(pNamapenerbit);
    pNamapenerbit->tambahPenerbit(this);
}
void Penerbit::cetakNamapenerbit() {
    cout << "Daftar Penerbit Buku \"" << this->nama << "\":\n";
    for (auto& a : daftar_Namapenerbit) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main()
{
    Penerbit* varPenerbit1 = new Penerbit("alenxader");
    Penerbit* varPenerbit2 = new Penerbit("samuel");
    Namapenerbit* varNamapenerbi1 = new Namapenerbit("john");
    Namapenerbit* varNamapenerbi2 = new Namapenerbit("asep");

    varPenerbit1->tambahNamapenerbit (varPenerbit1);
    varPenerbit1->tambahNamapenerbit (varPenerbit2);
    varPenerbit2->tambahNamapenerbit (varPenerbit1);

    varPenerbit1->cetakNamapenerbit();
    varPenerbit2->cetakNamapenerbit();
    varNamapenerbit1->cetakPenerbit();
    varNamapenerbit2->cetakPenerbit();

    delete varNamapenerbit1;
    delete varNamapenerbit2;
    delete varPenerbit1;
    delete varPenerbit2;

    return 0;
}