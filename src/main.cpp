#include <iostream>
#include "include/Menu.hpp"
#include "include/ProductMap.hpp"
#include "include/CustomerMap.hpp"

int main()
{
    system("clear");
system("cls");
;
    // read products from file
    ProductMap::load();
    // read customers from file
    // stores them in array
    CustomerMap::load();

    Menu::StartMenu();
    return 0;
}
