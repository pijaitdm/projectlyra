#include <iostream>
#include <string>
#include <vector>
#include "input.hpp"
#include "folder.hpp"

void pilihan2() {
    std::cout << " Inputan UE Visit\n";
    std::string tahun_folder = tahun(); // dari input.hpp, default "2025"
    std::string bulan = validasi_bulan();
    if (bulan.empty()) return;
    std::string tempat = inputan("Tempat : ");
    std::string tanggal = inputan("Tanggal : ");

    // Gabungkan semua input sebagai tingkat folder
    std::vector<std::string> tingkat = {lib(), tahun_folder, bulan, tempat, tanggal};
    std::string folder_path = buat_folder_bertingkat(tingkat);

    std::cout << "Folder lengkap: " << folder_path << std::endl;
    std::cout << "-----------------------------\n";
}
