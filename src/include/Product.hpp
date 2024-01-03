#pragma once

#include <string>

class Product
{
    static int object_id;

public:
    enum ProductType
    {
        ELECTRONICS,
        GROCERY,
        CLOTHING,
    };

protected:
    std::string name;
    double price;
    int id;
    ProductType type;

public:
    Product(std::string name, ProductType type);
    virtual void setPrice(double price) = 0;
    virtual void to_csv() = 0;
};