#include <iostream>
#include <string>
using namespace std;

int main() {
    string namaBarang, statusBarang;
    int barangTerjual, jumlahPesan, biayaPesan;
    char lanjut = 'y';

    // Variabel rekapitulasi
    int jumlahAman = 0;
    int jumlahMenipis = 0;
    int jumlahHabis = 0;

    int totalTerjual = 0;
    int totalPesan = 0;
    long long totalBiayaPemesanan = 0;

    int penjualanTertinggi = -1;
    string barangTerlaris;

    cout << "=== REKAPITULASI PERSEDIAAN BARANG (MODUL B) ===" << endl;

    while (lanjut == 'y' || lanjut == 'Y') {

        cout << "\nNama Barang : ";
        getline(cin >> ws, namaBarang);

        // Validasi status barang
        do {
            cout << "Status Barang (Aman/Menipis/Habis) : ";
            getline(cin >> ws, statusBarang);

            if (statusBarang != "Aman" &&
                statusBarang != "Menipis" &&
                statusBarang != "Habis") {

                cout << "[!] Status harus Aman, Menipis, atau Habis." << endl;
            }

        } while (statusBarang != "Aman" &&
                 statusBarang != "Menipis" &&
                 statusBarang != "Habis");

        // Validasi barang terjual
        do {
            cout << "Barang Terjual : ";

            if (!(cin >> barangTerjual)) {
                cin.clear();
                cin.ignore(10000, '\n');
                barangTerjual = -1;
            }

            if (barangTerjual < 0) {
                cout << "[!] Tidak boleh negatif." << endl;
            }

        } while (barangTerjual < 0);

        // Validasi jumlah pesan
        do {
            cout << "Jumlah Dipesan : ";

            if (!(cin >> jumlahPesan)) {
                cin.clear();
                cin.ignore(10000, '\n');
                jumlahPesan = -1;
            }

            if (jumlahPesan < 0) {
                cout << "[!] Tidak boleh negatif." << endl;
            }

        } while (jumlahPesan < 0);

        // Validasi biaya pesan
        do {
            cout << "Biaya Pemesanan : Rp";

            if (!(cin >> biayaPesan)) {
                cin.clear();
                cin.ignore(10000, '\n');
                biayaPesan = -1;
            }

            if (biayaPesan < 0) {
                cout << "[!] Tidak boleh negatif." << endl;
            }

        } while (biayaPesan < 0);

        // Rekap status
        if (statusBarang == "Aman")
            jumlahAman++;
        else if (statusBarang == "Menipis")
            jumlahMenipis++;
        else
            jumlahHabis++;

        // Rekap total
        totalTerjual += barangTerjual;
        totalPesan += jumlahPesan;
        totalBiayaPemesanan += biayaPesan;

        // Cari barang terlaris
        if (barangTerjual > penjualanTertinggi) {
            penjualanTertinggi = barangTerjual;
            barangTerlaris = namaBarang;
        }

        do {
            cout << "\nInput data lagi? (y/n) : ";
            cin >> lanjut;

            if (lanjut != 'y' && lanjut != 'Y' &&
                lanjut != 'n' && lanjut != 'N') {

                cout << "[!] Pilihan hanya y atau n." << endl;
            }

        } while (lanjut != 'y' && lanjut != 'Y' &&
                 lanjut != 'n' && lanjut != 'N');
    }

    // OUTPUT AKHIR MODUL B
    cout << "\n===== HASIL REKAPITULASI =====" << endl;

    cout << "Jumlah barang aman     : "
         << jumlahAman << endl;

    cout << "Jumlah barang menipis  : "
         << jumlahMenipis << endl;

    cout << "Jumlah barang habis    : "
         << jumlahHabis << endl;

    cout << "Total unit terjual     : "
         << totalTerjual << endl;

    cout << "Total unit dipesan     : "
         << totalPesan << endl;

    cout << "Total biaya pemesanan  : Rp"
         << totalBiayaPemesanan << endl;

    cout << "Barang terlaris        : "
         << barangTerlaris << endl;

    cout << "Penjualan tertinggi    : "
         << penjualanTertinggi << " unit" << endl;

    return 0;
}