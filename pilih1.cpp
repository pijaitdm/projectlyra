#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cstdlib>
#include "menu.hpp"
#include "input.hpp"
#include "folder.hpp"
#include <ctime> // untuk fungsi waktu


void pilihan1() {
std::string file_csv = c_folder ();
std::cout << "Membuka file --> " << file_csv << std::endl;// untuk membuat folder dan file  csv
std::string lanjut;
std::ofstream file(file_csv, std::ios::app);

do{
  std::string moon  = input_bulan();
  if(moon.empty()){
    std::cout << " dibatalkan kembali  ke menu \n";
    file.close();
    return;
  }
  int input_ue = userInput("Masukan UE : ");
  std::cout << "simpan dan lanjut tekan [1], batal dan kembali ke menu [0,,,] : ";
  std::cin >> lanjut;
  if (lanjut == "1"){
    file << moon << "," << input_ue << std::endl;
    std::cout << moon << " : " << input_ue << " (berhasil ditambahkan) \n";
  }
  
  else {
  std::cout << moon << " & " << input_ue << " tidak tersimpan \n" << "kembali ke menu \n";
  }
}
while(lanjut != "0");
file.close();
}
