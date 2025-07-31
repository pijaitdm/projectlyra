#include <iostream>
#include <string>
#include <vector>
#include "input.hpp"

void batas() {

    for(int i = 0 ; i < 30 ; ++i){		
    std::cout << "=";
    }
    std::cout << std::endl ;
}

void drawBox(const std::string& text) {
    int width = text.length() + 4;
    std::string horizontal = "═";

    std::cout << "╔";
    for (int i = 0; i < width; ++i) std::cout << horizontal;
    std::cout << "╗" << std::endl;

    std::cout << "║  " << text << "  ║" << std::endl;

    std::cout << "╚";
    for (int i = 0; i < width; ++i) std::cout << horizontal;
    std::cout << "╝" << std::endl;
}

void pilih_menu() {
    std::vector<std::string> menu_arr = {
        "1. Input/update UE LCR",
        "2. Lihat / edit",
        "3. Clear/Menu Utama",
        "0. Keluar"
    };
    for (const auto& item : menu_arr)
        std::cout << item << std::endl;
}

void menu() {
    drawBox("Project LYRA LCR");
    batas();
    pilih_menu();
    batas();
    
    
          
    
}

