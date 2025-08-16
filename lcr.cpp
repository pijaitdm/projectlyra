#include <iostream>
#include <string>
#include <filesystem>   
#include <fstream>
#include <sstream>
#include "input.hpp"
#include "folder.hpp"

//membuat file stok
std::string file_stok(){
std::string addBulan;

std::string pathlcr = folder_stok();

addBulan = input_bulan();
  if(addBulan.empty()){return "";}

std::string pathStok = pathlcr + "/" + addBulan + ".csv";
  if(!std::filesystem::exists(pathStok)){
  int simpan = userInput("< simpan  tekan 1 atau 0 untuk batal > : ");
    if (simpan == 1){

    std::ofstream file(pathStok);
    std::cout << "membuat ~> " << pathStok << std::endl;
    }
    else{std::cout << "batal memyimpan\n"; return ""; }
  }

  else {std::cout << "berhasil membuka ~> " << pathStok << std::endl;}
  
return pathStok;
}

void tambah_manual(){
//ini hanya untuk menambah secara manual atau awal
const std::string path_stok = file_stok();
std::ofstream file(path_stok, std::ios::app);
          std::cout << "tambah stok awal secara manual!!\n";
            float add_flinkote = floatInput("Flinkote : ");
            float add_noxudol = floatInput("noxudol : ");
            float add_tiner = floatInput("tiner : ");
            float add_aerosol = floatInput("aerosol : ");
            //validasi 
            int simpan = userInput("simpan ( tekan 1 atau 0 untuk batal) : ");
            if (simpan == 1){
              file << "flinkote" << "," << add_flinkote << std::endl;
              file << "noxudol"<< "," << add_noxudol << std::endl;
              file << "tiner" << "," << add_tiner << std::endl;
              file << "aerosol" << "," << add_aerosol << std::endl;
              std::cout << "berhasil menambahkan stok ke --> " << path_stok << std::endl;
            } else {std::cout << "batal menyimpan \n";return;}
}


//menambah isi stok di file stok
void tambah_stok(){
const std::string f_stok = file_stok();
std::ifstream file(f_stok);
if(!file.is_open()){
std::cerr << "error file tidak terbuka\n";
}
//tambah stok awal secara manual
  if(file.peek() == std::ifstream::traits_type::eof()){
    std::cout << "\nisi kosong\n\n";

    std::ofstream file(f_stok, std::ios::app);
    std::cout << "tambah stok awal secara manual!!\n";
            float add_flinkote = floatInput("Flinkote : ");
            float add_noxudol = floatInput("noxudol : ");
            float add_tiner = floatInput("tiner : ");
            float add_aerosol = floatInput("aerosol : ");
            //validasi 
            int simpan = userInput("simpan ( tekan 1 atau 0 untuk batal) : ");
            if (simpan == 1){
              file << "flinkote" << "," << add_flinkote << std::endl;
              file << "noxudol"<< "," << add_noxudol << std::endl;
              file << "tiner" << "," << add_tiner << std::endl;
              file << "aerosol" << "," << add_aerosol << std::endl;
              std::cout << "berhasil menambahkan stok ke --> " << f_stok << std::endl;
            } else {std::cout << "batal menyimpan \n";return;}
return;
}
}




void lihat_stok(){
std::cout << "Cek Laporan Stok Bulan sebelumnya \n";
std::string bulan_lalu  = input_bulan();
std::string buka_bulan  = folder_stok() + "/" + bulan_lalu + ".csv";
      if (!std::filesystem::exists(buka_bulan)){
        std::cout << bulan_lalu << " tidak ditemukan !! \n";}

      else{std::cout << "membuka file stok --> " << bulan_lalu << std::endl;}

std::ifstream file (buka_bulan);
std::string line;
  if(file.is_open()){
    while(std::getline(file, line)){
      std::cout << line << std::endl;
      }
    }
  else{std::cout << "gagal membuka file " << bulan_lalu << std::endl;}
}



void hitung_stok(){
std::cout << "Memperbarui stok untuk ";
std::string untuk_bulan = input_bulan();

// untuk mengecek file stok jika tidak ada buat baru
 std::string untuk_bulan_file = folder_stok() + "/" + untuk_bulan + ".csv";
  if(!std::filesystem::exists(untuk_bulan_file)){
    std::cout << untuk_bulan << " belum ada\n";
    //std::ofstream(untuk_bulan_file);
    }
  else{std::cout << "bulan < " << untuk_bulan << " > sudah ada\n";}

//menghitung jumlah sisa alat lcr

}


