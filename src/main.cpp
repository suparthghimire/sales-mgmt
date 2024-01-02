#include <iostream>
#include "include/Menu.hpp"

int main()
{
    system("clear");
    std::cout << "Welcome to Sales Management" << std::endl;
    Menu::PressKeyToContinue("Press any key to continue");
    int choice = Menu::StartMenu();
    return 0;
}
