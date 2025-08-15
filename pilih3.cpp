#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip> // untuk std::setw
#include "input.hpp"
#include "folder.hpp"
#include "menu.hpp"





void menu_pilih3(){
std::cout <<  "Menu Laporan : \n";
std::cout <<  "[1]. Laporan Bulanan LCR \n";
std::cout <<  "[2]. Laporan Stok alat LCR \n";
std::cout <<  "[3]. Tambah Stok alat LCR \n";
std::cout <<  "[0]. Kembali ke menu utama \n";
}

void laporan_lcr(){

std::string f_lcr = c_folder();
  std::ifstream file(f_lcr);
   if (!file.is_open()) {
        std::cerr << "Gagal membuka file!\n";
        return ;
    }
    
batas();    
std::cout << std::left << std::setw(10) << "Bulan" << " | " << "UE" <<std::endl;
std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string kolom_bulan;
        std::string kolom_angka;
        
        std::getline(ss, kolom_bulan, ',');
        std::getline (ss, kolom_angka);
        std::cout << std::left << std::setw(10)<<kolom_bulan << " | " << kolom_angka << "\n"; //std::setw membuat sama rata
        }
file.close();
}

void pilihan3(){
menu_pilih3();

int pilihan;
do{

pilihan = userInput("Pilih Menu : ");

  switch(pilihan){
        case 1: 
                std::cout << "Laporan Bulanan LCR \n";
                laporan_lcr();
                batas();
                break;
        case 2: 
                std::cout << "Laporan Stok LCR \n";
                break;
        case 3:
                std::cout << "Tambah Stok Alat LCR \n";
                break;
        default:
                std::cout << "Pilihan tidak valid \n";
                 break;
        case 0:
                break;
  }              
}while(pilihan != 0);
}
