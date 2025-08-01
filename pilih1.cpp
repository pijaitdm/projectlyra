#include <iostream>
#include "menu.hpp"
#include "input.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cstdlib>

//buat file baru

void buat_folder(){
//Buat file jika belum ada
    std::string folder = "lib/";

    if(std::filesystem::exists(folder) && std::filesystem::is_directory(folder)) {
    std::cout << "------------------------ \n" << std::endl;
    } 
    else{
    std::filesystem::create_directories(folder);
    std::cout << "buat file baru -- > " << folder << std::endl;
    }
}
//cek file ada atau tidak
void c_file(){
  std::string cek_file = "lib/2025.csv";
    if(!std::filesystem::exists(cek_file)){
      std::ofstream file(cek_file);
      std::cout << cek_file << " file berhasil dibuat \n";
    }
    else{ std::cout << "++ 2025 ++ \n \n";}
}


   
void pilihan1() {
buat_folder(); c_file();// untuk membuat folder dan file  csv
std::string bulan = input_bulan();
//membuat isi update
std::ofstream file("lib/2025.csv", std::ios::app);
if(file.is_open()){
  file << bulan << ",";
  file << userInput("Masukan UE : ") << std::endl;
  file.close();
  std::cout << bulan << " berhasil ditambahkan \n";
}
}
