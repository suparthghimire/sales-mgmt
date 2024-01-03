#include "include/Product.hpp"

int Product::object_id = 0;

Product::Product(std::string name, Product::ProductType type)
{
    this->id = ++object_id;
    this->name = name;
    this->type = type;
}
