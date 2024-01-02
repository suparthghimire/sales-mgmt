#include "include/Menu.hpp"
#include <iostream>

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
    return DisplayMenu(menu_items, 4);
}

void Menu::InvoiceMenu()
{
    std::string menu_items[4] = {
        "1. Create Invoice",
        "2. Add product to invoice",
        "3. Calculate invoice total",
        "4. Back"};

    int choice = DisplayMenu(menu_items, 4);
    // Add implementation for handling the choice in the InvoiceMenu
}

void Menu::CustomerMenu()
{
    std::string menu_items[2] = {
        "1. Create Customer",
        "2. Back"};

    int choice = DisplayMenu(menu_items, 2);
    // Add implementation for handling the choice in the CustomerMenu
}

void Menu::ProductMenu()
{
    std::string menu_items[2] = {
        "1. Create Product",
        "2. Back"};

    int choice = DisplayMenu(menu_items, 2);
    // Add implementation for handling the choice in the ProductMenu
}
