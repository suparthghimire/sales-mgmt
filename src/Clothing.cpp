#include "include/Clothing.hpp"
#include "include/FileHandler.hpp"

Clothing::Clothing(std::string name, Product::ProductType type, ClothingAgeType clothing_age_type) : Product(name, type)
{
    this->clothing_age_type = clothing_age_type;
}

void Clothing::setPrice(double price)
{

    // if clothing is for adults, add 10% more to price due to additional material
    if (this->clothing_age_type == ClothingAgeType::ADULT)
    {
        std::cout << "Adult clothing warraents additional 10\% material cost" << std::endl;
        this->price = price + (price * 0.1);
    }
    // else set price as it is
    else
    {
        this->price = price;
    }
}

void Clothing::to_csv()
{
    std::string fileName = "products";
    std::cout << "Price: " << this->price << std::endl;
    std::string data = std::to_string(this->id) + "," + this->name + "," + std::to_string(this->price) + "," + std::to_string(this->type) + "," + std::to_string(this->clothing_age_type);
    FileHandler::writeFile(fileName, data);
}
