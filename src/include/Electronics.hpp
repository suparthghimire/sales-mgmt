#pragma once

#include "Product.hpp"

class Electronics : public Product
{
public:
    enum GadgetType
    {
        WEARABLE,
        NON_WEARABLE,
    };

private:
    enum GadgetType gadget_type;

public:
    // product with id and price (required when reading from file)
    Electronics(int id, std::string name, double price, Product::ProductType type, GadgetType gadget_type);

    // product without  id (required when user is entering data)
    Electronics(std::string name, Product::ProductType type, GadgetType gadget_type);
    void setPrice(double price);
    void to_csv();
    void display();
    int getSubType();
};