#include "include/Clothing.hpp"
#include "include/FileHandler.hpp"

Clothing::Clothing(int id, std::string name, double price, Product::ProductType type, ClothingAgeType clothing_age_type) : Product(id, name, price, type)
{
    this->clothing_age_type = clothing_age_type;
}

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

std::string GetClothingAgeTypeName(Clothing::ClothingAgeType clothing_age_type)
{
    switch (clothing_age_type)
    {
    case Clothing::ClothingAgeType::ADULT:
        return "Adult";
        break;
    case Clothing::ClothingAgeType::CHILD:
        return "Child";
        break;
    default:
        return "Unknown";
        break;
    }
}

void Clothing::display()
{
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Price: " << this->price << std::endl;
    std::cout << "Type: " << this->type << std::endl;
    std::cout << "Clothing Age Type: " << GetClothingAgeTypeName(this->clothing_age_type) << std::endl;
}