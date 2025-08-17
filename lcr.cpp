#include <iostream>
#include <string>
#include <filesystem>   
#include <fstream>
#include <sstream>
#include <map>
#include "input.hpp"
#include "folder.hpp"

// Helper: Validasi dan parsing baris CSV
bool parse_stok_line(const std::string& line, std::string& nama, float& jumlah) {
    std::istringstream ss(line);
    return std::getline(ss, nama, ',') && ss >> jumlah;
}

// Membuat atau membuka file stok
std::string file_stok() {
    std::string bulan = input_bulan();
    if (bulan.empty()) return "";

    std::string path_stok = folder_stok() + "/" + bulan + ".csv";

    if (!std::filesystem::exists(path_stok)) {
        std::cout << "File belum ada: " << path_stok << "\n";
        int simpan = userInput("< lanjut membuat tekan [1] atau [0] untuk batal > : ");
        if (simpan != 1) {
            std::cout << "Dibatalkan.\n";
            return "";
        }

        std::ofstream file(path_stok);
        if (!file) {
            std::cerr << "Gagal membuat file: " << path_stok << "\n";
            return "";
        }
        std::cout << "File dibuat ~> " << path_stok << "\n";
    } else {
        std::cout << "File ditemukan ~> " << path_stok << "\n";
    }

    return path_stok;
}

// Menambah stok awal jika file kosong
void tambah_stok() {
    std::string f_stok = file_stok();
    if (f_stok.empty()) return;

    std::ifstream cek_file(f_stok);
    if (!cek_file.is_open()) {
        std::cerr << "Gagal membuka file.\n";
        return;
    }

    if (cek_file.peek() != std::ifstream::traits_type::eof()) {
        std::cout << "File sudah berisi data. Lanjut ke pembaruan stok.\n";
        return;
    }

    std::cout << "\nFile kosong. Tambah stok awal:\n";
    std::map<std::string, float> stok_awal = {
        {"flinkote", floatInput("Flinkote : ")},
        {"noxudol",  floatInput("Noxudol : ")},
        {"tiner",    floatInput("Tiner : ")},
        {"aerosol",  floatInput("Aerosol : ")}
    };

    int simpan = userInput("Simpan? (1 = ya, 0 = batal): ");
    if (simpan != 1) {
        std::cout << "Batal menyimpan.\n";
        return;
    }

    std::ofstream file(f_stok, std::ios::app);
    if (!file) {
        std::cerr << "Gagal menulis ke file.\n";
        return;
    }

    for (const auto& [nama, jumlah] : stok_awal) {
        file << nama << "," << jumlah << "\n";
    }

    std::cout << "✅ Stok awal ditambahkan ke --> " << f_stok << "\n";
}

// Melihat isi file stok
void lihat_stok() {
    std::cout << "Cek laporan stok bulan sebelumnya\n";
    std::string bulan = input_bulan();
    if (bulan.empty()) return;

    std::string path_file = folder_stok() + "/" + bulan + ".csv";
    if (!std::filesystem::exists(path_file)) {
        std::cout << "File " << bulan << " tidak ditemukan.\n";
        return;
    }

    std::ifstream file(path_file);
    if (!file.is_open()) {
        std::cerr << "Gagal membuka file: " << path_file << "\n";
        return;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "File kosong.\n";
        return;
    }

    std::cout << "Isi file stok --> " << bulan << ":\n";
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
}

// Memperbarui stok
void perbarui_stok() {
    std::string bulan = input_bulan();
    if (bulan.empty()) {
        std::cout << "Dibatalkan.\n";
        return;
    }

    std::string path_file = folder_stok() + "/" + bulan + ".csv";
    if (!std::filesystem::exists(path_file)) {
        std::cout << "File belum ada. Tambah stok awal...\n";
        tambah_stok();
        return;
    }

    std::ifstream file_in(path_file);
    if (!file_in.is_open()) {
        std::cerr << "Gagal membuka file: " << path_file << "\n";
        return;
    }

    std::map<std::string, float> stok;
    std::string line;
    while (std::getline(file_in, line)) {
        std::string nama;
        float jumlah;
        if (!parse_stok_line(line, nama, jumlah)) {
            std::cerr << "Format rusak di baris: " << line << "\n";
            return;
        }
        stok[nama] = jumlah;
    }
    file_in.close();

    std::cout << "\nMasukkan stok baru yang datang:\n";
    std::map<std::string, float> tambahan = {
        {"flinkote", floatInput("Flinkote : ")},
        {"noxudol",  floatInput("Noxudol : ")},
        {"tiner",    floatInput("Tiner : ")},
        {"aerosol",  floatInput("Aerosol : ")}
    };

    for (const auto& [nama, jumlah] : tambahan) {
        if (jumlah < 0) {
            std::cerr << "Input negatif terdeteksi pada: " << nama << ". Dibatalkan.\n";
            return;
        }
    }

    int simpan = userInput("Simpan pembaruan? (1 = ya, 0 = batal): ");
    if (simpan != 1) {
        std::cout << "Batal memperbarui stok.\n";
        return;
    }

    for (const auto& [nama, jumlah] : tambahan) {
        stok[nama] += jumlah;
    }

    std::ofstream file_out(path_file, std::ios::trunc);
    if (!file_out.is_open()) {
        std::cerr << "Gagal menulis ke file: " << path_file << "\n";
        return;
    }

    for (const auto& [nama, jumlah] : stok) {
        file_out << nama << "," << jumlah << "\n";
    }

    std::cout << "✅ Stok berhasil diperbarui untuk bulan --> " << bulan << "\n";
}

