#pragma once
#include <memory>
#include <map>

#include "Product.hpp"
typedef std::map<std::pair<int, int>, std::unique_ptr<Product>> T_ProductMap;

class ProductMap
{
private:
    static T_ProductMap products;

public:
    static void addProductToMap(std::pair<int, int> key, std::unique_ptr<Product> value);
    static T_ProductMap getProducts();
    static std::unique_ptr<Product> getSingleProduct(std::pair<int, int> key);
    static void load();
    static void display();
};