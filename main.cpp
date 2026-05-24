#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;

string namaJalan[MAX];
int jumlahKendaraan[MAX];
string kategori[MAX];

int jumlahData = 0;

string tentukanKategori(int kendaraan) {

    if (kendaraan <= 100) {
        return "LANCAR";
    }
    else if (kendaraan <= 250) {
        return "PADAT";
    }
    else {
        return "MACET TOTAL";
    }

}

void tambahData() {

    int jumlahInput;

    cout << "\n===== TAMBAH DATA =====\n";
    cout << "Berapa data yang ingin ditambahkan? ";
    cin >> jumlahInput;

    cin.ignore();

    for (int i = 0; i < jumlahInput; i++) {

        cout << "\nData ke-" << i + 1 << endl;

        cout << "Nama Jalan        : ";
        getline(cin, namaJalan[jumlahData]);

        cout << "Jumlah Kendaraan  : ";
        cin >> jumlahKendaraan[jumlahData];

        cin.ignore();

        // Menentukan kategori otomatis
        kategori[jumlahData] =
            tentukanKategori(jumlahKendaraan[jumlahData]);

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
         << setw(20) << "Jumlah Kendaraan"
         << setw(20) << "Kategori"
         << endl;

    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < jumlahData; i++) {

        cout << left
             << setw(5)  << i + 1
             << setw(25) << namaJalan[i]
             << setw(20) << jumlahKendaraan[i]
             << setw(20) << kategori[i]
             << endl;

    }

}
void sortingKemacetan() {

    for (int i = 0; i < jumlahData - 1; i++) {

        for (int j = 0; j < jumlahData - i - 1; j++) {

            if (jumlahKendaraan[j] < jumlahKendaraan[j + 1]) {

                int tempJumlah = jumlahKendaraan[j];
                jumlahKendaraan[j] = jumlahKendaraan[j + 1];
                jumlahKendaraan[j + 1] = tempJumlah;

                string tempNama = namaJalan[j];
                namaJalan[j] = namaJalan[j + 1];
                namaJalan[j + 1] = tempNama;

                string tempKategori = kategori[j];
                kategori[j] = kategori[j + 1];
                kategori[j + 1] = tempKategori;

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

        cout << "Nama Jalan       : "
             << namaJalan[hasil] << endl;

        cout << "Jumlah Kendaraan : "
             << jumlahKendaraan[hasil] << endl;

        cout << "Kategori         : "
             << kategori[hasil] << endl;

    }
    else {

        cout << "\nData tidak ditemukan.\n";

    }

}

void statistik() {

    if (jumlahData == 0) {

        cout << "\nData masih kosong.\n";
        return;

    }

    int total = 0;
    int terbesar = jumlahKendaraan[0];
    int terkecil = jumlahKendaraan[0];

    string jalanMacet = namaJalan[0];
    string jalanLancar = namaJalan[0];

    for (int i = 0; i < jumlahData; i++) {

        total += jumlahKendaraan[i];

        if (jumlahKendaraan[i] > terbesar) {

            terbesar = jumlahKendaraan[i];
            jalanMacet = namaJalan[i];

        }

        if (jumlahKendaraan[i] < terkecil) {

            terkecil = jumlahKendaraan[i];
            jalanLancar = namaJalan[i];

        }

    }

    double rataRata = (double) total / jumlahData;

    cout << "\n===== STATISTIK LALU LINTAS =====\n";

    cout << "Total Kendaraan      : "
         << total << endl;

    cout << "Rata-rata Kendaraan  : "
         << rataRata << endl;

    cout << "Jalan Paling Macet   : "
         << jalanMacet
         << " (" << terbesar << " kendaraan)"
         << endl;

    cout << "Jalan Paling Lancar  : "
         << jalanLancar
         << " (" << terkecil << " kendaraan)"
         << endl;

}
int main() {

    int pilihan;

    do {

        cout << "\n";
        cout << "=====================================\n";
        cout << " SMART TRAFFIC DENSITY MONITOR\n";
        cout << "=====================================\n";

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

            case 1:
                tambahData();
                break;

            case 2:
                tampilkanData();
                break;

            case 3:
                sortingKemacetan();
                break;

            case 4:
                searchingData();
                break;

            case 5:
                statistik();
                break;

            case 6:
                cout << "\nProgram selesai.\n";
                break;

            default:
                cout << "\nMenu tidak valid.\n";

        }

    } while (pilihan != 6);

    return 0;
}
