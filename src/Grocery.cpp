#include "include/Grocery.hpp"
#include "include/FileHandler.hpp"

Grocery::Grocery(int id, std::string name, double price, Product::ProductType type, GroceryType grocery_type) : Product(id, name, price, type)
{
    this->grocery_type = grocery_type;
}

Grocery::Grocery(std::string name, Product::ProductType type, GroceryType grocery_type) : Product(name, type)
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

std::string GetGroceryTypeName(Grocery::GroceryType grocery_type)
{
    switch (grocery_type)
    {
    case Grocery::GroceryType::NON_VEG:
        return "Non Veg";
        break;
    case Grocery::GroceryType::VEG:
        return "Veg";
        break;
    default:
        return "Unknown";
        break;
    }
}

void Grocery::display()
{
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Price: " << this->price << std::endl;
    std::cout << "Type: " << this->type << std::endl;
    std::cout << "Grocery Type: " << GetGroceryTypeName(this->grocery_type) << std::endl;
}

int Grocery::getSubType()
{
    return static_cast<int>(this->grocery_type);
}