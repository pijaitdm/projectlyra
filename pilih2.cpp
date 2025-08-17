#include <iostream>
#include <string>
#include <filesystem>
#include "input.hpp"
#include "folder.hpp"

void membuat_folder_visit() {
    std::cout << "\n--- 📁 Input UE Visit ---\n";

    std::string tahun_folder = tahun(); // buat tahun otomatis
    std::string tempat = inputan("Tempat : ");
    std::string bulan = input_bulan();

    if (bulan.empty()) {
        std::cout << "⚠️  Bulan kosong. Kembali ke menu.\n";
        return;
    }

    std::string tanggal = inputan("Tanggal : ");
    tanggal.erase(0, tanggal.find_first_not_of('0'));

    if (tanggal.empty()) {
        std::cout << "❌ Tanggal kosong.\n";
        return;
    }

    int simpan = userInput("Konfirmasi simpan [1 = Ya, 0 = Batal] : ");
    if (simpan != 1) {
        std::cout << "❌ Batal menyimpan.\n";
        return;
    }

    std::string folder_visit = lib() + "/visit/" + tempat + "/" + bulan + "/" + tahun_folder + "/" + tanggal;

    if (!std::filesystem::exists(folder_visit) || !std::filesystem::is_directory(folder_visit)) {
        std::filesystem::create_directories(folder_visit);
        std::cout << "✅ Folder dibuat --> " << folder_visit << '\n';
    } else {
        std::cout << "📂 Folder sudah ada --> " << folder_visit << '\n';
    }
}

void pilihan2() {
    std::cout << "\n=== ✨ Menu Visit UE ===\n";
    membuat_folder_visit();
}

