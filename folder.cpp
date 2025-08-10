#include <iostream>
#include <string>
#include <vector>
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


// Membuat folder bertingkat dari vector nama folder.
std::string buat_folder_bertingkat(const std::vector<std::string>& tingkat) {
    std::string path = "";
    for (const auto& t : tingkat) {
        if (!path.empty()) path += "/";
        path += t;
        if (!std::filesystem::exists(path)) {
            std::filesystem::create_directories(path);
            std::cout << t << " berhasil dibuat di " << path << std::endl;
        }
    }
    return path;
}

//cek folder
std::string c_folder(){
  std::string folder = folder_lcr();
  std::string laporan_lcr = folder +"/"+ get_tahun_sekarang()+".csv";
  
  if(!std::filesystem::exists(folder)){
  std::filesystem::create_directory(folder);
  }
  
    if(!std::filesystem::exists(laporan_lcr)){
      std::ofstream file(laporan_lcr);
      std::cout << laporan_lcr << " file berhasil dibuat \n";
    }
  return laporan_lcr;
}


