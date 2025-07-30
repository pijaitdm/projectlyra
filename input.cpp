//inputan user
#include <iostream>
#include <string>

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
  
std::string tambah_bulan(std::string par_bulan) {
    std::string bulan[] = {
        "januari", "februari", "maret", "april", "mei", "juni",
        "juli", "agustus", "september", "oktober", "november", "desember"
    };

    for (int i = 0; i < 12; ++i) {
        if (par_bulan == bulan[i]) {
            return bulan[i];  // dikembalikan
        }
    }

    std::cout << "Bulan tidak valid.\n";
    return "";
}
  
