#include <iostream>
#include <string>
using namespace std;

int main() {
    // ===== Variabel Modul A: proses tiap barang =====
    string kodeBarang, namaBarang, statusBarang;
    int stokAwal = 0, barangMasuk = 0, barangTerjual = 0;
    int stokMinimum = 0, hargaBeli = 0, stokTersedia = 0;
    int stokAkhir = 0, jumlahPesan = 0, biayaPesan = 0;
    char lanjut = 'y';

    // ===== Variabel Modul B: rekapitulasi (di luar perulangan, diisi 0) =====
    int jumlahAman = 0;
    int jumlahMenipis = 0;
    int jumlahHabis = 0;

    int totalTerjual = 0;
    int totalPesan = 0;
    long long totalBiayaPemesanan = 0;

    int penjualanTertinggi = -1;
    string barangTerlaris;

    cout << "=== EVALUASI PERSEDIAAN BARANG (PROGRAM TERINTEGRASI) ===" << endl;

    // Perulangan utama: proses barang selama petugas memilih lanjut
    while (lanjut == 'y' || lanjut == 'Y') {
        // ---------- MODUL A: input dan validasi ----------
        cout << "\n--- Data Barang ---" << endl;
        cout << "Kode barang : ";
        getline(cin >> ws, kodeBarang);
        cout << "Nama barang : ";
        getline(cin >> ws, namaBarang);

        // Validasi stok awal (tidak boleh negatif atau bukan angka)
        do {
            cout << "Stok awal   : ";
            if (!(cin >> stokAwal)) {
                cin.clear();
                cin.ignore(10000, '\n');
                stokAwal = -1;
            }
            if (stokAwal < 0)
                cout << "  [!] Harus berupa angka dan tidak boleh negatif." << endl;
        } while (stokAwal < 0);

        // Validasi barang masuk
        do {
            cout << "Barang masuk: ";
            if (!(cin >> barangMasuk)) {
                cin.clear();
                cin.ignore(10000, '\n');
                barangMasuk = -1;
            }
            if (barangMasuk < 0)
                cout << "  [!] Harus berupa angka dan tidak boleh negatif." << endl;
        } while (barangMasuk < 0);

        // Stok yang tersedia untuk dijual
        stokTersedia = stokAwal + barangMasuk;

        // Validasi barang terjual (tidak boleh melebihi stok tersedia)
        do {
            cout << "Barang terjual (maks " << stokTersedia << "): ";
            if (!(cin >> barangTerjual)) {
                cin.clear();
                cin.ignore(10000, '\n');
                barangTerjual = -1;
            }
            if (barangTerjual < 0 || barangTerjual > stokTersedia)
                cout << "  [!] Penjualan tidak valid (0 sampai " << stokTersedia << ")." << endl;
        } while (barangTerjual < 0 || barangTerjual > stokTersedia);

        // Validasi stok minimum
        do {
            cout << "Stok minimum: ";
            if (!(cin >> stokMinimum)) {
                cin.clear();
                cin.ignore(10000, '\n');
                stokMinimum = -1;
            }
            if (stokMinimum < 0)
                cout << "  [!] Harus berupa angka dan tidak boleh negatif." << endl;
        } while (stokMinimum < 0);

        // Validasi harga beli
        do {
            cout << "Harga beli  : Rp";
            if (!(cin >> hargaBeli)) {
                cin.clear();
                cin.ignore(10000, '\n');
                hargaBeli = -1;
            }
            if (hargaBeli < 0)
                cout << "  [!] Harus berupa angka dan tidak boleh negatif." << endl;
        } while (hargaBeli < 0);

        // ---------- MODUL A: perhitungan ----------
        // Hitung stok akhir
        stokAkhir = stokTersedia - barangTerjual;

        // Tentukan status barang
        if (stokAkhir == 0) {
            statusBarang = "Habis";
        } else if (stokAkhir < stokMinimum) {
            statusBarang = "Menipis";
        } else {
            statusBarang = "Aman";
        }

        // Hitung jumlah pesan: sampai stok mencapai dua kali stok minimum
        if (statusBarang == "Habis" || statusBarang == "Menipis") {
            jumlahPesan = (2 * stokMinimum) - stokAkhir;
        } else {
            jumlahPesan = 0;
        }

        // Hitung biaya pemesanan
        biayaPesan = jumlahPesan * hargaBeli;

        // ---------- MODUL B: perbarui rekapitulasi ----------
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

        // Cari barang dengan penjualan tertinggi
        if (barangTerjual > penjualanTertinggi) {
            penjualanTertinggi = barangTerjual;
            barangTerlaris = namaBarang;
        }

        // ---------- MODUL A: tampilkan rincian ----------
        cout << "\n--- Rincian Barang ---" << endl;
        cout << "Kode / Nama     : " << kodeBarang << " / " << namaBarang << endl;
        cout << "Stok awal       : " << stokAwal << endl;
        cout << "Barang masuk    : " << barangMasuk << endl;
        cout << "Barang terjual  : " << barangTerjual << endl;
        cout << "Stok akhir      : " << stokAkhir << endl;
        cout << "Stok minimum    : " << stokMinimum << endl;
        cout << "Status          : " << statusBarang << endl;
        cout << "Jumlah dipesan  : " << jumlahPesan << " unit" << endl;
        cout << "Biaya pemesanan : Rp" << biayaPesan << endl;

        // Pilihan mengulang atau mengakhiri (hanya menerima y atau n)
        do {
            cout << "\nProses barang lain? (y/n): ";
            cin >> lanjut;

            if (lanjut != 'y' && lanjut != 'Y' &&
                lanjut != 'n' && lanjut != 'N') {
                cout << "[!] Pilihan hanya y atau n." << endl;
            }
        } while (lanjut != 'y' && lanjut != 'Y' &&
                 lanjut != 'n' && lanjut != 'N');
    }

    // ---------- MODUL B: tampilkan rekapitulasi ----------
    cout << "\n===== HASIL REKAPITULASI =====" << endl;
    cout << "Jumlah barang aman     : " << jumlahAman << endl;
    cout << "Jumlah barang menipis  : " << jumlahMenipis << endl;
    cout << "Jumlah barang habis    : " << jumlahHabis << endl;
    cout << "Total unit terjual     : " << totalTerjual << endl;
    cout << "Total unit dipesan     : " << totalPesan << endl;
    cout << "Total biaya pemesanan  : Rp" << totalBiayaPemesanan << endl;
    cout << "Barang terlaris        : " << barangTerlaris << endl;
    cout << "Penjualan tertinggi    : " << penjualanTertinggi << " unit" << endl;

    cout << "\nProgram selesai." << endl;
    return 0;
}