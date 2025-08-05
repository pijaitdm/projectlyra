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

std::string validasi_bulan(){
std::string bulan; 
do{
bulan = input_bulan();
}while(bulan.empty());
return bulan;
}
//tambah folder bulan
std::string tambah_bulan(){
std::string buat_folder_bulan; 
std::string bulan = validasi_bulan();
buat_folder_bulan = tambah_tahun() +"/"+ bulan;
if(!std::filesystem::exists(buat_folder_bulan) && !std::filesystem::is_directory(buat_folder_bulan)){
  std::filesystem::create_directories(buat_folder_bulan);
  std::cout << validasi_bulan() << " berhasil dibuat \n";}
return buat_folder_bulan;
}

//tambah tempat
std::string tambah_tempat(){
std::string tempat;
std::string buat_folder_tempat = tambah_bulan()+"/"+tempat;
tempat = inputan("Tempat : ");
if(!std::filesystem::exists(buat_folder_tempat)&&!std::filesystem::is_directory(buat_folder_tempat)){
  std::filesystem::create_directories(buat_folder_tempat);
  std::cout << tempat << " berhasil di buat \n";}
return buat_folder_tempat;
}

void pilihan2(){
  std::cout << " Inputan UE  Visit \n";
  std::string validasi; std::string tanggal; 
  std::string folder = tambah_tempat();
do{

std::string buat_folder_tanggal = folder +"/"+tanggal;
tanggal = inputan("tanggal : ");
if(!std::filesystem::exists(buat_folder_tanggal)&&!std::filesystem::is_directory(buat_folder_tanggal)){
  std::filesystem::create_directories(buat_folder_tanggal);
  std::cout << tanggal << " berhasil di buat \n";
  break;
}
std::cout << "----------------------------- \n" ;
validasi = inputan(" lanjut input UE ya/tidak ! : ");
}while(validasi != "tidak");
}
