#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "input.hpp"
#include "folder.hpp"


std::string file_stok(){
std::string addBulan;

std::string pathlcr = folder_stok();

addBulan = input_bulan();
if(addBulan.empty()){
return "";
}
const std::string pathStok = pathlcr + "/" + addBulan + ".csv";
if(!std::filesystem::exists(pathStok)){
std::cout << "membuat ~> " << pathStok << std::endl;
std::ofstream file(pathStok);
}
else {std::cout << "membuka ~> " << pathStok << std::endl;}
return pathStok;
}


void lcr(){
file_stok();
}
