#pragma once
#include <memory>
#include <map>

#include "Product.hpp"
typedef std::map<int, std::unique_ptr<Product>> T_ProductMap;

class ProductMap
{
private:
    static T_ProductMap products;

public:
    static void addProductToMap(int id, std::unique_ptr<Product> value);
    static T_ProductMap getProducts();
    static std::unique_ptr<Product> &getSingleProduct(int id);
    static void load();
    static void display();
};