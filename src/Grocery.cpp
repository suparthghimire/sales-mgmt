#include "include/Grocery.hpp"
#include "include/FileHandler.hpp"

Grocery::Grocery(std::string name, Product::ProductType type, Grocery::GroceryType grocery_type) : Product(name, type)
{
    this->grocery_type = grocery_type;
}

void Grocery::setPrice(double price)
{
    // if gadget is veg, subtract 10% due to government subsidy
    // government has given subsidy to veg products to promote local farmers
    if (this->grocery_type == GroceryType::VEG)
    {
        std::cout << "Veg grocery has 10\% discount due to government subsidy" << std::endl;
        this->price = price - (price * 0.1);
    }
    // else set price as it is
    else
    {
        this->price = price;
    }
}

void Grocery::to_csv()
{
    std::string fileName = "products";
    std::cout << "Price: " << this->price << std::endl;
    std::string data = std::to_string(this->id) + "," + this->name + "," + std::to_string(this->price) + "," + std::to_string(this->type) + "," + std::to_string(this->grocery_type);
    FileHandler::writeFile(fileName, data);
}
