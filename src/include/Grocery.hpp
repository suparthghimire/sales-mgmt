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
    Grocery(std::string name, Product::ProductType type, GroceryType grocery_type);
    void setPrice(double price);
    void to_csv();
};