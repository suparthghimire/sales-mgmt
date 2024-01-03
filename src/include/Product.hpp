#pragma once

#include <string>
#include <memory>
#include <map>

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

private:
    // map of all products: <pair<id, type>, unique_ptr of product>

protected:
    std::string name;
    double price;
    int id;
    ProductType type;

public:
    // product with id and price (required when reading from file)
    Product(int id, std::string name, double price, ProductType type);
    // product without  id (required when user is entering data)
    Product(std::string name, ProductType type);

    // set price of product
    virtual void setPrice(double price) = 0;
    // save to file
    virtual void to_csv() = 0;

    virtual void display() = 0;
};