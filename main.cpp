//program ini dibuat oleh @pijai
#include <iostream>
#include <string>
#include "menu.hpp"
#include <cstdlib>
#include "input.hpp"
#include "pilih1.hpp"
#include "pilih2.hpp"
#include "pilih3.hpp"

int main () {

menu();
int pilihan;
do{ 
    pilihan = userInput("Pilih menu : ");
    switch(pilihan){
      case 1:
        system("clear");
        std::cout << "menu 1 \n";
        pilihan1();
        menu();
        break;
        
      case 2:
        system("clear");
        std::cout << "Menu 2 - Input UE Pos \n";
        pilihan2();
        menu();
        break;
        
      case 3:
        system("clear");
        std::cout << "menu 3 \n";
        pilihan3();
        menu();
        break;
      
      case 5:
        system("clear");
        menu();
        break;
        
      default:
        std::cout << "Pilihan tidak valid.\n";
        break;
        
      case 0:
        std::cout << "keluar \n";
        break;
    }
    }while( pilihan != 0);
      
    
    
    
return 0;
}
