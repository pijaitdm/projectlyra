#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

std::string folder_lcr(){
std::string file_path = "lib/LCR";
return file_path;
}

std::string get_tahun_sekarang() {
    time_t t = time(nullptr);
    tm* waktu = localtime(&t);
    int tahun = waktu->tm_year + 1900; // tm_year adalah jumlah tahun sejak 1900
    return std::to_string(tahun);
}


//cek folder
std::string c_folder(){
  std::string folder = folder_lcr();
  
  if(!std::filesystem::exists(folder)){
  std::filesystem::create_directories(folder);
  }
  
  std::string laporan_lcr = folder + "/" + get_tahun_sekarang()+".csv";
    if(!std::filesystem::exists(laporan_lcr)){
      std::ofstream file(laporan_lcr);
      std::cout << laporan_lcr << " file berhasil dibuat \n";
    }
  return laporan_lcr;
}

//buat folder stok alat lcr
void cek_folder(){
std::string folder_bulan;
folder_bulan = inputan("Untuk Bulan : ");
std::string pathBulan = "lib/lcr/stok";

if(!std::filesystem::exists || !std::filesystem::is_directory){
std::filesystem::create_directories(pathFolder);
}
else {std::cout << "Membuka Folder ~> " << pathFolder << std::endl;}
}




