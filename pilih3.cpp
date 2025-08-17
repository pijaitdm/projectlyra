#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip> // untuk std::setw
#include "input.hpp"
#include "folder.hpp"
#include "menu.hpp"
#include "lcr.hpp"



void laporan_lcr() {
    std::string f_lcr = c_folder();
    std::ifstream file(f_lcr);
    if (!file.is_open()) {
        std::cerr << "❌ Gagal membuka file: " << f_lcr << "\n";
        return;
    }

    batas();
    std::cout << "📊 Laporan Bulanan UE\n";
    std::cout << std::left << std::setw(10) << "Bulan" << " | " << "UE\n";
    std::cout << "-------------------------\n";

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string kolom_bulan, kolom_angka;
        std::getline(ss, kolom_bulan, ',');
        std::getline(ss, kolom_angka);
        std::cout << std::left << std::setw(10) << kolom_bulan << " | " << kolom_angka << "\n";
    }

    file.close();
}

void pilihan3() {
    std::cout << "\n=== 📋 Menu Laporan LCR ===\n";
    std::cout << "[1] 📊 Laporan Bulanan LCR\n";
    std::cout << "[2] 📦 Laporan Stok alat LCR\n";
    std::cout << "[3] ➕ Tambah Stok alat LCR\n";
    std::cout << "[0] 🔙 Kembali ke menu utama\n";

    int pilihan;
    do {
        pilihan = userInput("🔽 Pilih menu [0-3] : ");

        switch (pilihan) {
            case 1:
                std::cout << "\n📊 Menampilkan Laporan Bulanan LCR...\n";
                laporan_lcr();
                batas();
                break;
            case 2:
                std::cout << "\n📦 Menampilkan Laporan Stok LCR...\n";
                // (isi laporan stok bisa ditambahkan di sini)
                break;
            case 3:
                std::cout << "\n➕ Menambah Stok Alat LCR...\n";
                // (fungsi tambah stok bisa ditambahkan di sini)
                break;
            case 0:
                std::cout << "🔙 Kembali ke menu utama.\n";
                break;
            default:
                std::cout << "⚠️  Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    } while (pilihan != 0);
}

