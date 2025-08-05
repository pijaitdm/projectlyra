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
  std::cout << tahun() << " berhasil dibuat \n ";
}
else{
std::cout << "(lanjut input untuk tahun " << tahun();
}

return folder_tahun;
}
//tambah folder bulan
void tambah_bulan(){
std::string bulan; 
while(true){
bulan = input_bulan();
std::string buat_folder_bulan = tambah_tahun() +"/"+ bulan; 
if(!std::filesystem::exists(buat_folder_bulan) && !std::filesystem::is_directory(buat_folder_bulan)){
  std::filesystem::create_directories(buat_folder_bulan);
  std::cout << bulan << " berhasil dibuat \n";
  break;
}
else { std::cout << ", dan bulan " << bulan << " !!)" << std::endl; break;}
}
} 


void pilihan2(){
  std::cout << " Inputan UE  Visit \n";
  tambah_bulan();
  std::string validasi;
do{
  validasi = inputan(" lanjut input UE ya/tidak ! : ");
}while(validasi != "tidak");
}
