#include <iostream>
#include "include/Menu.hpp"
#include "include/ProductMap.hpp"

int main()
{
    system("clear");
    // read products from file
    // stores them in array
    ProductMap::load();
    ProductMap::display();

    // Menu::StartMenu();
    return 0;
}
