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
    Electronics(std::string name, Product::ProductType type, GadgetType gadget_type);
    void setPrice(double price);
    void to_csv();
};