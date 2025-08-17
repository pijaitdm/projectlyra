#include <iostream>
#include <string>
#include <vector>
#include "input.hpp"

void batas() {
    std::cout << std::string(30, '=') << "\n";
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
        "📊 [1] Input UE LCR",
        "📍 [2] Input UE Visit",
        "📋 [3] Laporan LCR",
        "🔄 [5] Refresh Menu",
        "🚪 [0] Keluar"
    };

    std::cout << "\n=== 📁 Menu Utama ===\n";
    for (const auto& item : menu_arr)
        std::cout << item << "\n";
}

void menu() {
    drawBox("Project LYRA Versi 1");
    batas();
    pilih_menu();
    batas();
}
