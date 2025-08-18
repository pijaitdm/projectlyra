#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <unordered_map> // agar data map tidak berututan seperti di map
#include <iomanip>
#include "input.hpp"
#include "folder.hpp"

// Helper: Validasi dan parsing baris CSV
bool parse_stok_line(const std::string& line, std::string& nama, float& jumlah) {
    std::istringstream ss(line);
    return std::getline(ss, nama, ',') && ss >> jumlah;
}

// Output status modular
void print_status(const std::string& msg, const std::string& path = "", const std::string& type = "info") {
    if (type == "success") {
        std::cout << "✅ " << msg << " --> " << path << "\n";
    } else if (type == "error") {
        std::cerr << "❌ " << msg << std::endl;
    } else if (type == "warn") {
        std::cout << "⚠️ " << msg << " --> " << path << "\n";
    } else {
        std::cout << "📁 " << msg << " --> " << path << "\n";
    }
}

// Membuat atau membuka file stok
std::string file_stok() {
    std::string bulan = input_bulan();
    if (bulan.empty()) return "";

    std::string path_stok = folder_stok() + "/" + bulan + ".csv";

    if (!std::filesystem::exists(path_stok)) {
        print_status("File belum ada", path_stok, "warn");
        int simpan = userInput("Lanjut buat file? [1 = Ya, 0 = Batal] : ");
        if (simpan != 1) {
            print_status("Dibatalkan", "", "error");
            return "";
        }

        std::ofstream file(path_stok);
        if (!file) {
            print_status("Gagal membuat file", path_stok, "error");
            return "";
        }
        print_status("File dibuat", path_stok, "success");
    } else {
        print_status("File ditemukan", path_stok);
    }

    return path_stok;
}

// Menambah stok awal jika file kosong
void tambah_stok() {
    std::string f_stok = file_stok();
    if (f_stok.empty()) return;

    std::ifstream cek_file(f_stok);
    if (!cek_file.is_open()) {
        print_status("Gagal membuka file", f_stok, "error");
        return;
    }

    if (cek_file.peek() != std::ifstream::traits_type::eof()) {
        print_status("File sudah berisi data. Lanjut ke pembaruan stok", f_stok);
        return;
    }

    std::cout << "\n--- Tambah Stok Awal ---\n";
    std::unordered_map<std::string, float> stok_awal = {
        {"flinkote", floatInput("Flinkote : ")},
        {"noxudol",  floatInput("Noxudol : ")},
        {"tiner",    floatInput("Tiner : ")},
        {"aerosol",  floatInput("Aerosol : ")}
    };

    for (const auto& [nama, jumlah] : stok_awal) {
        if (jumlah < 0) {
            print_status("Input negatif terdeteksi pada", nama, "error");
            return;
        }
    }

    int simpan = userInput("Konfirmasi simpan [1 = Ya, 0 = Batal] : ");
    if (simpan != 1) {
        print_status("Batal menyimpan", "", "error");
        return;
    }

    std::ofstream file(f_stok, std::ios::app);
    if (!file) {
        print_status("Gagal menulis ke file", f_stok, "error");
        return;
    }

    for (const auto& [nama, jumlah] : stok_awal) {
        file << nama << "," << jumlah << "\n";
    }

    print_status("Stok awal ditambahkan", f_stok, "success");
}

// Melihat isi file stok
void lihat_stok() {
    std::cout << "\n--- Cek Laporan Stok ---\n";
    std::string bulan = input_bulan();
    if (bulan.empty()) return;

    std::string path_file = folder_stok() + "/" + bulan + ".csv";
    if (!std::filesystem::exists(path_file)) {
        print_status("File tidak ditemukan", path_file, "error");
        return;
    }

    std::ifstream file(path_file);
    if (!file.is_open()) {
        print_status("Gagal membuka file", path_file, "error");
        return;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        print_status("File kosong", path_file, "warn");
        return;
    }

    std::cout << "\n📊 Isi Stok Bulan " << bulan << ":\n";
    std::cout << std::left << std::setw(15) << "Nama Barang" << std::right << std::setw(10) << "Jumlah\n";
    std::cout << "------------------------------\n";

    std::string line;
    while (std::getline(file, line)) {
        std::string nama;
        float jumlah;
        if (parse_stok_line(line, nama, jumlah)) {
            std::cout << std::left << std::setw(15) << nama << std::right << std::setw(10) << jumlah << "\n";
        }
    }
}

// Memperbarui stok
void perbarui_stok() {
    std::string bulan = input_bulan();
    if (bulan.empty()) {
        print_status("Dibatalkan", "", "error");
        return;
    }

    std::string path_file = folder_stok() + "/" + bulan + ".csv";
    if (!std::filesystem::exists(path_file)) {
        print_status("File belum ada. Tambah stok awal...", path_file, "warn");
        tambah_stok();
        return;
    }

    std::ifstream file_in(path_file);
    if (!file_in.is_open()) {
        print_status("Gagal membuka file", path_file, "error");
        return;
    }

    std::unordered_map<std::string, float> stok;
    std::string line;
    while (std::getline(file_in, line)) {
        std::string nama;
        float jumlah;
        if (!parse_stok_line(line, nama, jumlah)) {
            print_status("Format rusak di baris", line, "error");
            return;
        }
        stok[nama] = jumlah;
    }
    file_in.close();

    std::cout << "\n--- Tambah Stok Baru ---\n";
    std::unordered_map<std::string, float> tambahan = {
        {"flinkote", floatInput("Flinkote : ")},
        {"noxudol",  floatInput("Noxudol : ")},
        {"tiner",    floatInput("Tiner : ")},
        {"aerosol",  floatInput("Aerosol : ")}
    };

    for (const auto& [nama, jumlah] : tambahan) {
        if (jumlah < 0) {
            print_status("Input negatif terdeteksi pada", nama, "error");
            return;
        }
    }

    int simpan = userInput("Konfirmasi pembaruan [1 = Ya, 0 = Batal] : ");
    if (simpan != 1) {
        print_status("Batal memperbarui stok", "", "error");
        return;
    }

    for (const auto& [nama, jumlah] : tambahan) {
        stok[nama] += jumlah;
    }

    std::ofstream file_out(path_file, std::ios::trunc);
    if (!file_out.is_open()) {
        print_status("Gagal menulis ke file", path_file, "error");
        return;
    }

    for (const auto& [nama, jumlah] : stok) {
        file_out << nama << "," << jumlah << "\n";
    }

    print_status("Stok berhasil diperbarui", bulan, "success");
}

