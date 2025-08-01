#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int userInput(const std::string& pesan){
    while(true){
        int user;
        std::cout << pesan;
        std::cin >> user;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\n Inputan tidak Valid! \n";
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
        std::cout << "Masukan Bulan: ";
        std::cin >> input_bulan_str;

        // Mengubah input menjadi huruf kecil untuk perbandingan yang tidak case-sensitive
        std::transform(input_bulan_str.begin(), input_bulan_str.end(), 
        input_bulan_str.begin(),[](unsigned char c){ return std::tolower(c); });

        // Mencari input di dalam vektor bulan
        if (std::find(bulan.begin(), bulan.end(), input_bulan_str) != bulan.end()) {
            return input_bulan_str;
        } else {
            std::cout << "Bulan tidak valid\n";
            return "";
        }      
    }
}
