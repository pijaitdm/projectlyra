#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "input.hpp"
#include "folder.hpp"

void pilihan2() {
    std::cout << " Inputan UE Visit\n";
    std::string tahun_folder = tahun(); //buat tahun otomatis
    std::string bulan = input_bulan();
    if (bulan.empty()) {
      std::cout << "Kembali ke menu \n";
      return;
    }
    const std::string tempat = inputan("Tempat : ");
    const std::string tanggal = inputan("Tanggal : ");

    // Gabungkan semua input sebagai tingkat folder
    std::vector<std::string> tingkat = {lib(), tahun_folder, bulan, tempat, tanggal};
    std::string folder_path = buat_folder_bertingkat(tingkat);
    
    if (std::filesystem::exists(folder_path)){
    std::cout << "Membuka --> " << folder_path << std::endl;
    }
}
