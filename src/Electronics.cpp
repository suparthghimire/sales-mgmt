#include "include/Electronics.hpp"
#include "include/FileHandler.hpp"

Electronics::Electronics(int id, std::string name, double price, Product::ProductType type, GadgetType gadget_type) : Product(id, name, price, type)
{
    this->gadget_type = gadget_type;
}

Electronics::Electronics(std::string name, Product::ProductType type, GadgetType gadget_type) : Product(name, type)
{
    this->gadget_type = gadget_type;
}

void Electronics::setPrice(double price)
{
    // if gadget is non wearable, add 10% more to price due to additional hardware
    // eg. with smartphones you also get charger and earphones
    if (this->gadget_type == GadgetType::NON_WEARABLE)
    {
        std::cout << "Non wearable gadget warraents additional 10\% feature cost" << std::endl;
        this->price = price + (price * 0.1);
    }
    // else set price as it is
    else
    {
        this->price = price;
    }
}

void Electronics::to_csv()
{
    std::string fileName = "products";
    std::cout << "Price: " << this->price << std::endl;
    std::string data = std::to_string(this->id) + "," + this->name + "," + std::to_string(this->price) + "," + std::to_string(this->type) + "," + std::to_string(this->gadget_type);
    FileHandler::writeFile(fileName, data);
}

std::string GetGadgetTypeName(Electronics::GadgetType gadget_type)
{
    switch (gadget_type)
    {
    case Electronics::GadgetType::WEARABLE:
        return "Wearable";
        break;
    case Electronics::GadgetType::NON_WEARABLE:
        return "Non Wearable";
        break;
    default:
        return "Unknown";
        break;
    }
}

void Electronics::display()
{
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Price: " << this->price << std::endl;
    std::cout << "Type: " << this->type << std::endl;
    std::cout << "Gadget Type: " << GetGadgetTypeName(this->gadget_type) << std::endl;
}

int Electronics::getSubType()
{
    return static_cast<int>(this->gadget_type);
}