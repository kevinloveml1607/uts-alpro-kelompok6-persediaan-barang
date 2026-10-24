#include <iostream>
#include <string>
using namespace std;

int main() {
    // Deklarasi variabel input per barang
    string kodeBarang, namaBarang;
    int barangTerjual = 0, statusPilihan = 0;
    int jumlahPesan = 0, biayaPesan = 0;
    char lanjut = 'y';

    // Deklarasi variabel rekapitulasi (nilai awal sebelum perulangan)
    int jumlahAman = 0, jumlahMenipis = 0, jumlahHabis = 0;
    int totalTerjual = 0, totalUnitPesan = 0, totalBiayaPesan = 0;
    int penjualanTertinggi = -1;   // -1 agar barang pertama selalu menjadi rekor awal
    string kodeTertinggi = "", namaTertinggi = "";

    cout << "=== REKAPITULASI PERSEDIAAN BARANG (MODUL B) ===" << endl;

    // Perulangan utama: proses barang selama petugas memilih lanjut
    while (lanjut == 'y' || lanjut == 'Y') {
        cout << "\n--- Hasil Evaluasi Barang ---" << endl;
        cout << "Kode barang : ";
        getline(cin >> ws, kodeBarang);
        cout << "Nama barang : ";
        getline(cin >> ws, namaBarang);

        // Validasi barang terjual (tidak boleh negatif atau bukan angka)
        do {
            cout << "Barang terjual : ";
            if (!(cin >> barangTerjual)) {
                cin.clear();
                cin.ignore(10000, '\n');
                barangTerjual = -1;
            }
            if (barangTerjual < 0)
                cout << "  [!] Harus berupa angka dan tidak boleh negatif." << endl;
        } while (barangTerjual < 0);

        // Validasi status barang (hanya 1, 2, atau 3)
        do {
            cout << "Status (1=Aman, 2=Menipis, 3=Habis): ";
            if (!(cin >> statusPilihan)) {
                cin.clear();
                cin.ignore(10000, '\n');
                statusPilihan = 0;
            }
            if (statusPilihan < 1 || statusPilihan > 3)
                cout << "  [!] Pilih 1, 2, atau 3." << endl;
        } while (statusPilihan < 1 || statusPilihan > 3);

        // Validasi jumlah pesan
        do {
            cout << "Jumlah dipesan : ";
            if (!(cin >> jumlahPesan)) {
                cin.clear();
                cin.ignore(10000, '\n');
                jumlahPesan = -1;
            }
            if (jumlahPesan < 0)
                cout << "  [!] Harus berupa angka dan tidak boleh negatif." << endl;
        } while (jumlahPesan < 0);

        // Validasi biaya pemesanan
        do {
            cout << "Biaya pemesanan : Rp";
            if (!(cin >> biayaPesan)) {
                cin.clear();
                cin.ignore(10000, '\n');
                biayaPesan = -1;
            }
            if (biayaPesan < 0)
                cout << "  [!] Harus berupa angka dan tidak boleh negatif." << endl;
        } while (biayaPesan < 0);

        // Hitung jumlah barang per status
        if (statusPilihan == 1) {
            jumlahAman++;
        } else if (statusPilihan == 2) {
            jumlahMenipis++;
        } else {
            jumlahHabis++;
        }

        // Akumulasi total
        totalTerjual    += barangTerjual;
        totalUnitPesan  += jumlahPesan;
        totalBiayaPesan += biayaPesan;

        // Cari barang dengan penjualan tertinggi
        if (barangTerjual > penjualanTertinggi) {
            penjualanTertinggi = barangTerjual;
            kodeTertinggi = kodeBarang;
            namaTertinggi = namaBarang;
        }

        // Tanya lanjut, tolak jawaban selain y/n
        do {
            cout << "\nProses barang lain? (y/n): ";
            cin >> lanjut;
            cin.ignore(10000, '\n');
            if (lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N')
                cout << "  [!] Jawab y atau n." << endl;
        } while (lanjut != 'y' && lanjut != 'Y' && lanjut != 'n' && lanjut != 'N');
    }

    // Tampilkan rekapitulasi
    cout << "\n--- Rekapitulasi Persediaan ---" << endl;
    cout << "Barang aman         : " << jumlahAman << endl;
    cout << "Barang menipis      : " << jumlahMenipis << endl;
    cout << "Barang habis        : " << jumlahHabis << endl;
    cout << "Total unit terjual  : " << totalTerjual << endl;
    cout << "Total unit dipesan  : " << totalUnitPesan << " unit" << endl;
    cout << "Total biaya pesan   : Rp" << totalBiayaPesan << endl;
    cout << "Penjualan tertinggi : " << kodeTertinggi << " / " << namaTertinggi
         << " (" << penjualanTertinggi << " unit)" << endl;

    cout << "\nProgram selesai." << endl;
    return 0;
}