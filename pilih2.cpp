#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "input.hpp"


std::string tambah_tahun(){
std::string folder_tahun = lib() + tahun() ;
if (!std::filesystem::exists(folder_tahun)&&!std::filesystem::is_directory(folder_tahun)){
  std::filesystem::create_directories(folder_tahun);
  std::cout << tahun() << " berhasil dibuat \n ";}
else{
std::cout << "Tahun : " << tahun() << std::endl;
}

return folder_tahun;
}

//tambah folder bulan
std::string tambah_bulan(){
std::string buat_folder_bulan; 
std::string bulan;
std::string tahun = tambah_tahun();
do{
bulan = validasi_bulan();
buat_folder_bulan = tahun +"/"+ bulan;
if(!std::filesystem::exists(buat_folder_bulan) && !std::filesystem::is_directory(buat_folder_bulan)){
  std::filesystem::create_directories(buat_folder_bulan);
  std::cout << bulan << " berhasil dibuat \n";}
  }while(bulan.empty());
return buat_folder_bulan;
}

//tambah tempat
std::string tambah_tempat(){
std::string tempat;
std::string folder_bulan = tambah_bulan();
tempat = inputan("Tempat : ");
std::string buat_folder_tempat = folder_bulan +"/"+tempat;
if(!std::filesystem::exists(buat_folder_tempat)&&!std::filesystem::is_directory(buat_folder_tempat)){
  std::filesystem::create_directories(buat_folder_tempat);
  std::cout << tempat << " berhasil di buat \n";}
return buat_folder_tempat;
}

void pilihan2(){
  std::cout << " Inputan UE  Visit \n";
  std::string validasi; std::string tanggal; 
  std::string folder = tambah_tempat();
  tanggal = inputan("tanggal : ");
  std::string buat_folder_tanggal = folder +"/"+tanggal;
  
if(!std::filesystem::exists(buat_folder_tanggal)&&!std::filesystem::is_directory(buat_folder_tanggal)){
  std::filesystem::create_directories(buat_folder_tanggal);
  std::cout << tanggal << " berhasil di buat \n";
}
std::cout << "----------------------------- \n" ;
}
