#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cstdlib>
#include "input.hpp"
#include "folder.hpp"
std::string path_lcr = c_folder();
bool bulanSudahAda(const std::string& file_csv, const std::string& bulan) {
    std::ifstream file(path_lcr);
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
std::cout << "Membuka file --> " << path_lcr << std::endl;// untuk membuat folder dan file  csv
std::string lanjut;
std::ofstream file(path_lcr, std::ios::app);

while(true){
  std::string moon  = input_bulan();
  if (bulanSudahAda(path_lcr, moon)) {
    std::cout << "Bulan sudah ada di file. kembali ke menu\n";
    break;
}
  if(moon.empty()){
    std::cout << " dibatalkan kembali  ke menu \n";
    file.close();
    break;
  }
  
  int input_ue = userInput("Masukan UE : ");
  std::cout << "simpan dan lanjut tekan [1], batal dan kembali ke menu utama [0,,,] : ";
  std::cin >> lanjut;
  if (lanjut == "1"){
    file << moon << "," << input_ue << std::endl;
    std::cout << moon << " : " << input_ue << " (berhasil ditambahkan) \n";
  }
  
  else {
  std::cout << moon << " : " << input_ue << " (tidak tersimpan  !!) \n \n";
  }
  }

file.close();
}
