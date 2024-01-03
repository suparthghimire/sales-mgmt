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
    Clothing(std::string name, Product::ProductType type, ClothingAgeType clothing_age_type);
    void setPrice(double price);
    void to_csv();
};