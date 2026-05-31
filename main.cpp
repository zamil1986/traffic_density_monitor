#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;
string namaJalan[MAX];
int truk[MAX];
int mobil[MAX];
int motor[MAX];
string kategori[MAX];
int jumlahData = 0;
int totalkendaraan[MAX];

string tentukanKategori(int kendaraan) {
    if (kendaraan <= 70) {
        return "LANCAR";
    } else if (kendaraan <= 120) {
        return "PADAT";
    } else {
        return "MACET TOTAL";
    }
}

void tambahData() {
    int jumlahInput;

    cout << "\n==========\n";
    cout << "Berapa data yang ingin ditambahkan? ";
    cin >> jumlahInput;
    cin.ignore();

    for (int i = 0; i < jumlahInput; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama Jalan   : ";
        getline(cin, namaJalan[jumlahData]);
        cout << "Jumlah Truk  : ";
        cin >> truk[jumlahData];
        cout << "Jumlah Mobil : ";
        cin >> mobil[jumlahData];
        cout << "Jumlah Motor : ";
        cin >> motor[jumlahData];
        cin.ignore();

        totalkendaraan[jumlahData] = truk[jumlahData]
                                   + mobil[jumlahData]
                                   + motor[jumlahData];

        kategori[jumlahData] = tentukanKategori(truk[jumlahData]*5 + mobil[jumlahData]*3 + motor[jumlahData]*2);

        jumlahData++;
        cout << "Data berhasil ditambahkan!\n";
    }
}

void tampilkanData() {
    cout << "\n===== DATA LALU LINTAS =====\n";
    if (jumlahData == 0) {
        cout << "Data masih kosong.\n";
        return;
    }

    cout << left
         << setw(5)  << "No"
         << setw(25) << "Nama Jalan"
         << setw(15) << "Truk"
         << setw(15) << "Mobil"
         << setw(15) << "Motor"
         << setw(20) << "Total Kendaraan"
         << setw(15) << "Kategori"
         << endl;

    cout << string(110, '-') << "\n";

    for (int i = 0; i < jumlahData; i++) {
        cout << left
             << setw(5)  << i + 1
             << setw(25) << namaJalan[i]
             << setw(15) << truk[i]
             << setw(15) << mobil[i]
             << setw(15) << motor[i]
             << setw(20) << totalkendaraan[i]
             << setw(15) << kategori[i]
             << endl;
    }
}

void sortingKemacetan() {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            if (totalkendaraan[j] < totalkendaraan[j + 1]) {
                swap(totalkendaraan[j], totalkendaraan[j + 1]);
                swap(namaJalan[j],      namaJalan[j + 1]);
                swap(kategori[j],       kategori[j + 1]);
                swap(truk[j],           truk[j + 1]);
                swap(mobil[j],          mobil[j + 1]);
                swap(motor[j],          motor[j + 1]);
            }
        }
    }
    cout << "\nData berhasil diurutkan dari paling macet.\n";
}

int cariJalan(string target) {
    for (int i = 0; i < jumlahData; i++) {
        if (namaJalan[i] == target) {
            return i;
        }
    }
    return -1;
}

void searchingData() {
    string target;

    cout << "\n===== SEARCHING JALAN =====\n";
    cin.ignore();
    cout << "Masukkan nama jalan: ";
    getline(cin, target);

    int hasil = cariJalan(target);

    if (hasil != -1) {
        cout << "\nData ditemukan!\n";
        cout << "Nama Jalan       : " << namaJalan[hasil] << endl;
        cout << "Total Kendaraan  : " << totalkendaraan[hasil] << endl;
        cout << "Kategori         : " << kategori[hasil] << endl;
    } else {
        cout << "\nData tidak ditemukan.\n";
    }
}

void statistik() {
    if (jumlahData == 0) {
        cout << "\nData masih kosong.\n";
        return;
    }

    int total    = 0;
    int terbesar = totalkendaraan[0];
    int terkecil = totalkendaraan[0];
    string jalanMacet  = namaJalan[0];
    string jalanLancar = namaJalan[0];

    for (int i = 0; i < jumlahData; i++) {
        total += totalkendaraan[i];

        if (totalkendaraan[i] > terbesar) {
            terbesar  = totalkendaraan[i];
            jalanMacet = namaJalan[i];
        }

        if (totalkendaraan[i] < terkecil) {
            terkecil   = totalkendaraan[i];
            jalanLancar = namaJalan[i];
        }
    }

    double rataRata = (double) total / jumlahData;

    cout << "\n===== STATISTIK LALU LINTAS =====\n";
    cout << "Total Kendaraan      : " << total     << endl;
    cout << "Rata-rata Kendaraan  : " << rataRata  << endl;
    cout << "Jalan Paling Macet   : " << jalanMacet
         << " (" << terbesar << " kendaraan)" << endl;
    cout << "Jalan Paling Lancar  : " << jalanLancar
         << " (" << terkecil << " kendaraan)" << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n";
        cout << "============================================\n";
        cout << " SISTEM PEMANTAUAN KEPADATAN KENDARAAN KOTA\n";
        cout << "============================================\n";
        cout << "1. Tambah Data Jalan\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Sorting Kemacetan\n";
        cout << "4. Cari Jalan\n";
        cout << "5. Statistik\n";
        cout << "6. Exit\n";
        cout << "=====================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData();      break;
            case 2: tampilkanData();   break;
            case 3: sortingKemacetan(); break;
            case 4: searchingData();   break;
            case 5: statistik();       break;
            case 6: cout << "\nProgram selesai.\n"; break;
            default: cout << "\nMenu tidak valid.\n";
        }

    } while (pilihan != 6);

    return 0;
}
