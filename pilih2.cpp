  #include <iostream>
  #include <string>
  #include <vector>
  #include <filesystem>
  #include "input.hpp"
  #include "folder.hpp"
  
  
  void membuat_folder_visit(){
  std::string tahun_folder = tahun(); //buat tahun otomatis
      
      std::string bulan = input_bulan();
      if (bulan.empty()) {
        std::cout << "Kembali ke menu \n";
        return;
      }
      
       std::string tempat = inputan("Tempat : ");
       std::string tanggal = inputan("Tanggal : ");

      // Gabungkan semua input sebagai tingkat folder
       std::string folder_visit = lib() + "/" + tahun_folder + "/" + bulan + "/" + tempat + "/" + tanggal;
      
      
      if (!std::filesystem::exists(folder_visit) || !std::filesystem::is_directory(folder_visit)){
        
      std::filesystem::create_directories(folder_visit);
      std::cout << "Membuat --> " << folder_visit << std::endl;
      }
      else{ 
      std::cout << "Membuka --> " << folder_visit << std::endl;
      }  
  }
  void pilihan2() {
      std::cout << " Inputan UE Visit\n";
      membuat_folder_visit();
  }
