#include "include/Menu.hpp"
#include <iostream>
#include <time.h>

void Menu::PressKeyToContinue()
{
    std::cin.ignore();
    std::string input;
    std::cout << "Press any key to go back";
    std::cin.get();
}

int Menu::DisplayMenu(std::string menu_items[], int menu_items_length)
{

    for (int i = 0; i < menu_items_length; i++)
    {
        std::cout << menu_items[i] << std::endl;
    }

    int choice;

    std::cout << ">";
    std::cin >> choice;

    return choice;
}

int Menu::StartMenu()
{
    std::string menu_items[4] = {
        "1. Manage invoices",
        "2. Manage Customers",
        "3. Handle Products",
        "4. Quit"};

    while (true)
    {
        system("clear");
        int choice = DisplayMenu(menu_items, 4);

        switch (choice)
        {
        case 1:
            InvoiceMenu();
            break;
        case 2:
            CustomerMenu();
            break;
        case 3:
            ProductMenu();
            break;
        case 4:
            return 0;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }
}

int Menu::InvoiceMenu()
{
    std::string menu_items[4] = {
        "1. Create Invoice",
        "2. Add product to invoice",
        "3. Calculate invoice total",
        "4. Back"};

    while (true)
    {
        system("clear");
        int choice = DisplayMenu(menu_items, 4);

        switch (choice)
        {
        case 1:
            std::cout << "Create Invoice" << std::endl;
            // get input
            Menu::PressKeyToContinue();
            break;
        case 2:
            std::cout << "Add product to invoice" << std::endl;
            Menu::PressKeyToContinue();
            break;
        case 3:
            std::cout << "Calculate invoice total" << std::endl;
            Menu::PressKeyToContinue();
            break;
        case 4:
            return 0;
        default:
            std::cout << "Invalid choice" << std::endl;
            Menu::PressKeyToContinue();
            break;
        }
    }

    // Add implementation for handling the choice in the InvoiceMenu
}

int Menu::CustomerMenu()
{
    system("clear");
    std::string menu_items[2] = {
        "1. Create Customer",
        "2. Back"};

    while (true)
    {
        int choice = DisplayMenu(menu_items, 2);
        switch (choice)
        {
        case 1:
            std::cout << "Create Customer" << std::endl;
            Menu::PressKeyToContinue();
            break;
        case 2:
            std::cout << "Going back";
            Menu::PressKeyToContinue();
            return 0;
        default:
            std::cout << "Invalid choice" << std::endl;
            Menu::PressKeyToContinue();
            break;
        }
    }

    // Add implementation for handling the choice in the CustomerMenu
}

int Menu::ProductMenu()
{
    system("clear");
    std::string menu_items[2] = {
        "1. Create Product",
        "2. Back"};

    int choice = DisplayMenu(menu_items, 2);
    // Add implementation for handling the choice in the ProductMenu
}
