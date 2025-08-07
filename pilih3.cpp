#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "input.hpp"
#include "folder.hpp"


void pilihan3(){
std::cout <<  "Menu Laporan : \n";
std::cout <<  "[1]. Laporan Bulanan LCR \n";
std::cout <<  "[2]. Laporan Stok alat LCR \n";
std::cout <<  "------------------------------------- \n";

std::string f_lcr = c_folder();
std::cout << f_lcr << std::endl;
std::cout <<  "------------------------------------- \n";
}
