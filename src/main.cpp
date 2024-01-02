#include <iostream>
#include "include/Menu.hpp"

int main()
{
    while (true)
    {
        std::cout << "Welcome to Sales Management" << std::endl;
        int choice = Menu::StartMenu();
        return 0;
    }
}
