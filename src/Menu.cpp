#include "include/Menu.hpp"
#include "include/Customer.hpp"
#include "include/CustomerMap.hpp"
#include <iostream>
#include <limits>
#include <time.h>

void Menu::PressKeyToContinue()
{
    std::cout << "Press any key to go back";
    std::cin.ignore();
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
        "1. Invoice Management",
        "2. Customer Management",
        "3. Product Management",
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
            std::cout << "HERE" << std::endl;
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
    std::string menu_items[3] = {
        "1. Create Customer",
        "2. Show all customers",
        "3. Back",
    };

    while (true)
    {
        system("clear");
        int choice = DisplayMenu(menu_items, 3);
        switch (choice)
        {
        case 1:
        {
            std::cout << "Create Customer" << std::endl;
            std::cout << "Enter name: ";
            std::string name;
            std::getline(std::cin >> std::ws, name);

            // ignore
            std::cin.ignore();

            // create customer
            Customer customer(name);
            // to_csv to file
            customer.to_csv();

            // creatre unique_ptr of customer
            std::unique_ptr<Customer> customer_ptr = std::make_unique<Customer>(customer);

            // add customer to map
            CustomerMap::addCustomer(std::move(customer_ptr));

            Menu::PressKeyToContinue();
            break;
        }
        case 2:
            CustomerMap::display();
            Menu::PressKeyToContinue();
            break;
        case 3:
            return 0;
        default:
            std::cout << "Invalid choice" << std::endl;
            Menu::PressKeyToContinue();
            break;
        }
    }
}
