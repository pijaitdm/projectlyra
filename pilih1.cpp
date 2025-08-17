#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cstdlib>
#include "input.hpp"
#include "folder.hpp"
bool bulanSudahAda(const std::string& file_csv, const std::string& bulan) {
    std::ifstream file(file_csv);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string bulan_ada;
        if (std::getline(ss, bulan_ada, ',')) {
            if (bulan_ada == bulan) return true;
        }
    }
    return false;
}


void pilihan1(){
const std::string path_lcr = c_folder();

std::ofstream file(path_lcr, std::ios::app);
  std::string moon  = input_bulan();
  if (bulanSudahAda(path_lcr, moon)) {
    std::cout << "Bulan sudah ada di file. kembali ke menu\n";
    return;
}
  if(moon.empty()){
    std::cout << ",dibatalkan kembali  ke menu \n";
    file.close();
    return;
  }
  
  int input_ue = userInput("Masukan UE : ");
  int simpan = userInput("Simpan? (1 = ya, 0 = batal): ");
  if (simpan != 1) {
        std::cout << "Batal menyimpan.\n";
        return;
    }
    file << moon << "," << input_ue << std::endl;
    std::cout << moon << " : " << input_ue << " (berhasil ditambahkan) \n";

file.close();
}
