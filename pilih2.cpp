#include <iostream>
#include <string>
#include <filesystem>
#include "input.hpp"
#include "folder.hpp"

void membuat_folder_visit() {
    std::string tahun_folder = tahun(); // buat tahun otomatis
    std::string tempat = inputan("Tempat : ");
    std::string bulan = input_bulan();

    if (bulan.empty()) {
        std::cout << "Kembali ke menu\n";
        return;
    }

    std::string tanggal = inputan("Tanggal : ");

    // Hapus semua '0' di depan
    tanggal.erase(0, tanggal.find_first_not_of('0'));

    // Jika semua karakter nol, tanggal kosong
    if (tanggal.empty()) {
        std::cout << "Tanggal kosong\n";
        return;
    }
    int simpan = userInput("Simpan? (1 = ya, 0 = batal): ");
    if (simpan != 1) {
        std::cout << "Batal menyimpan.\n";
        return;
    }
    // Gabungkan semua input sebagai path folder
    std::string folder_visit = lib() + "/visit/" + tempat + "/" + bulan + "/" + tahun_folder + "/" + tanggal;

    if (!std::filesystem::exists(folder_visit) || !std::filesystem::is_directory(folder_visit)) {
        std::filesystem::create_directories(folder_visit);
        std::cout << "Membuat --> " << folder_visit << '\n';
    } else {
        std::cout << "Membuka --> " << folder_visit << '\n';
    }
}

void pilihan2() {
    std::cout << "Inputan UE Visit\n";
    membuat_folder_visit();
}
