#pragma once

#include "Product.hpp"

class Clothing : public Product
{
public:
    enum ClothingAgeType
    {
        ADULT,
        CHILD,
    };

private:
    enum ClothingAgeType clothing_age_type;

public:
    // product with id and price (required when reading from file)
    Clothing(int id, std::string name, double price, Product::ProductType type, ClothingAgeType clothing_age_type);

    // product without  id (required when user is entering data)
    Clothing(std::string name, Product::ProductType type, ClothingAgeType clothing_age_type);
    void setPrice(double price);
    void to_csv();
    void display();
    int getSubType();
};