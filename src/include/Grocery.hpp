#pragma once

#include "Product.hpp"

class Grocery : public Product
{
public:
    enum GroceryType
    {
        VEG,
        NON_VEG,
    };

private:
    enum GroceryType grocery_type;

public:
    // product with id and price (required when reading from file)
    Grocery(int id, std::string name, double price, Product::ProductType type, GroceryType grocery_type);

    // product without id and price (required when reading from user)
    Grocery(std::string name, Product::ProductType type, GroceryType grocery_type);
    void setPrice(double price);
    void to_csv();
    void display();
    int getSubType();
};