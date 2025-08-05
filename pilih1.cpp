#include <iostream>
#include "menu.hpp"
#include "input.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cstdlib>

//buat file baru


//cek file ada atau tidak
void c_file(){
  std::string cek_file = "lib/2025.csv";
    if(!std::filesystem::exists(cek_file)){
      std::ofstream file(cek_file);
      std::cout << cek_file << " file berhasil dibuat \n";
    }
    else{ std::cout << "Membuka File "<< cek_file << std::endl;}
}


   
void pilihan1() {
c_file();// untuk membuat folder dan file  csv
std::string bulan = input_bulan();
//membuat isi update
std::ofstream file("lib/2025.csv", std::ios::app);
if(file.is_open()){
  if (bulan.empty()) {
    std::cout << "data tidak disimpan,\nkembali ke menu\n";
    file.close();
    return; // atau break kalau di dalam loop
}
  //menambah bulan
  file << bulan << ",";
  // menginput UE
  file << userInput("Masukan UE : ") << std::endl;
  file.close();
  std::cout << bulan << " berhasil ditambahkan \n";
}
}
