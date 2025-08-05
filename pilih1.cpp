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
std::string moon  = validasi_bulan();
std::string lanjut;
do{
//membuat isi update
std::ofstream file("lib/2025.csv", std::ios::app);
  //menambah bulan
  file << moon << ",";
  // menginput UE
  file << userInput("Masukan UE : ") << std::endl;
  file.close();
  std::cout << moon << " berhasil ditambahkan \n";
  std::cout << "lanjut tekan [1] : ";
  std::cin >> lanjut;
}
while(lanjut != "1");
}
