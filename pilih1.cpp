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
std::string lanjut;

do{
  std::ofstream file("lib/2025.csv", std::ios::app);
  std::string moon  = validasi_bulan();
  if(moon.empty()){
    std::cout << " dibatalkan kembali  ke menu \n";
    file.close();
    return;
  }
  int input_ue = userInput("Masukan UE : ");
  std::cout << "simpan dan lanjut tekan [1], kembali ke menu [0,,,] : ";
  std::cin >> lanjut;
  if (lanjut == "1"){
    file << moon << ",";
    std::cout << moon << " berhasil ditambahkan \n";
    file << input_ue << std::endl;
    std::cout << input_ue << " berhasil ditambahkan \n";
    file.close();
  }
  
  else {std::cout << "kembali ke menu \n";}
}
while(lanjut != "0");
}
