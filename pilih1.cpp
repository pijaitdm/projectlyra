#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cstdlib>
#include "menu.hpp"
#include "input.hpp"
#include "folder.hpp"
#include <ctime> // untuk fungsi waktu

std::string get_tahun_sekarang() {
    time_t t = time(nullptr);
    tm* waktu = localtime(&t);
    int tahun = waktu->tm_year + 1900; // tm_year adalah jumlah tahun sejak 1900
    return std::to_string(tahun);
}

void c_folder(){
  std::string folder = folder_lcr();
  std::string laporan_lcr = folder +"/"+ get_tahun_sekarang();
  std::filesystem::create_directory(folder);
    if(!std::filesystem::exists(laporan_lcr)){
      std::ofstream file(laporan_lcr);
      std::cout << " file berhasil dibuat \n";
    }
    else{ std::cout << "Membuka File -- > "<<laporan_lcr << std::endl;}
}

void pilihan1() {
c_folder();// untuk membuat folder dan file  csv
std::string lanjut;
std::string file_csv = folder_lcr();

do{
  std::ofstream file(file_csv, std::ios::app);
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
    file << moon << "," << input_ue << std::endl;
    std::cout << moon << " = " << input_ue << " (berhasil ditambahkan) \n";
    file.close();
  }
  
  else {std::cout << "kembali ke menu \n";}
}
while(lanjut != "0");
}
