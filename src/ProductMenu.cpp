#include "include/Menu.hpp"
#include "include/Product.hpp"
#include "include/Electronics.hpp"

#include <iostream>
#include <memory>
#include <limits>
std::unique_ptr<Product> createProduct(Product::ProductType type)
{
    std::string name;

    std::cout << "Enter Product Name: ";
    std::getline(std::cin >> std::ws, name);

    std::cin.ignore();

    switch (type)
    {
    case Product::ProductType::ELECTRONICS:
    {
        std::string available_gadgets[] = {
            "1. Wearable",
            "2. Non-Wearable",
        };
        int gadgetChoice = Menu::DisplayMenu(available_gadgets, 2);
        if (gadgetChoice < 1 || gadgetChoice > 2)
        {
            std::cout << "Invalid choice" << std::endl;
            Menu::PressKeyToContinue();
            return nullptr;
        }

        Electronics::GadgetType gt = static_cast<Electronics::GadgetType>(gadgetChoice - 1);
        return std::make_unique<Electronics>(name, type, gt);
    }

    default:
    {
        std::cout << "Invalid Product Type" << std::endl;
        return nullptr;
    }
    }
}

int Menu::ProductMenu()
{
    system("clear");
    std::string menu_items[2] = {
        "1. Create Product",
        "2. Back",
    };

    int choice = DisplayMenu(menu_items, 2);

    switch (choice)
    {
    case 1:
    {
        std::cout << "Choose Product Type" << std::endl;
        std::string available_products[] = {
            "1. Electronics",
            "2. Grocery",
            "3. Clothing",
        };
        int productChoice = Menu::DisplayMenu(available_products, 3);

        if (productChoice < 1 || productChoice > 3)
        {
            std::cout << "Invalid choice" << std::endl;
            Menu::PressKeyToContinue();
            return 0;
        }

        Product::ProductType pt = static_cast<Product::ProductType>(productChoice - 1);

        std::unique_ptr<Product> product = createProduct(pt);

        if (product == nullptr)
        {
            std::cout << "Product creation failed" << std::endl;
            Menu::PressKeyToContinue();
            return 0;
        }

        double price;

        // if price is not a number, make user reenter
        while (true)
        {
            std::cout << "Enter Product Price: ";
            try
            {
                std::cin >> price;

                if (std::cin.fail())
                    throw std::runtime_error("Invalid input. Please enter a number");

                break;
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }

        std::cin.ignore();

        product->setPrice(price);
        product->to_csv();

        std::cout << "Product created successfully" << std::endl;
        Menu::PressKeyToContinue();
        return 0;
    }
    case 2:
        return 0;
    default:
        std::cout << "Invalid choice" << std::endl;
        Menu::PressKeyToContinue();
        return 0;
    }
}
