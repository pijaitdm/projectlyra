#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

// tahun 
const std::string tahun(){
std::string folder_tahun = "2025";
return folder_tahun;
}

// folder lib
const std::string lib(){
std::string folder_lib = "lib/";
return folder_lib;
}

int userInput(const std::string& pesan){
    while(true){
        int user;
        std::cout << pesan;
        std::cin >> user;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\nInputan tidak valid!\n";
            continue;
        }
         if (user < 0){
        std::cout << user <<  " bilangan minus, inputan tidak valid\n";
        continue;
        }
        else {
            return user;
        }
    }
}

std::string inputan(const std::string& pesan) {
    std::string user_input;
    std::cout << pesan;
    std::getline(std::cin >> std::ws, user_input);  // menangkap input dengan spasi

    return user_input;
}

float floatInput(const std::string& pesan) {
    while(true){
        float user;
        std::cout << pesan;
        std::cin >> user;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\nInputan tidak valid!\n";
            continue;
        }
         if (user < 0){
        std::cout << user <<  " bilangan minus, inputan tidak valid\n";
        continue;
        }
        else {
            return user;
        }
    }
}



std::string input_bulan() {
    std::string input_bulan_str;
    const std::vector<std::string> bulan = {
        "januari", "februari", "maret", "april", "mei", "juni",
        "juli", "agustus", "september", "oktober", "november", "desember"
    };

    while (true) {
        std::cout << "Bulan : ";
        std::cin >> input_bulan_str;

        // Mengubah input menjadi huruf kecil untuk perbandingan yang tidak case-sensitive
        std::transform(input_bulan_str.begin(), input_bulan_str.end(), 
        input_bulan_str.begin(),[](unsigned char c){ return std::tolower(c); });

        // Mencari input di dalam vektor bulan
        if (std::find(bulan.begin(), bulan.end(), input_bulan_str) != bulan.end()) {
            return input_bulan_str;
        } else {
            std::cout << "Bulan tidak valid !!\n";
            return "";
        }      
    }
}
