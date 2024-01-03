#include "include/Product.hpp"
#include "include/FileHandler.hpp"
#include <memory>
#include <string>
int Product::object_id = 0;

// required when user is entering data
Product::Product(std::string name, Product::ProductType type)
{
    int id = ++object_id;
    this->id = id;
    this->name = name;
    this->type = type;
}

// required when loading from file
Product::Product(int id, std::string name, double price, Product::ProductType type)
{
    this->id = id;
    this->name = name;
    this->price = price;
    this->type = type;
}
