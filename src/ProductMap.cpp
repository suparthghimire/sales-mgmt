#include "include/ProductMap.hpp"
#include "include/FileHandler.hpp"
#include "include/Product.hpp"
#include "include/Electronics.hpp"
#include "include/Clothing.hpp"
#include "include/Grocery.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <sstream>

T_ProductMap ProductMap::products;

void ProductMap::addProductToMap(int id, std::unique_ptr<Product> value)
{
    products.emplace(std::make_pair(id, std::move(value)));
}

T_ProductMap ProductMap::getProducts()
{
    return std::move(products);
}

std::unique_ptr<Product> &ProductMap::getSingleProduct(int id)
{

    auto iterator = products.find(id);
    if (iterator == products.end())
    {
        static std::unique_ptr<Product> nullProduct; // Return a static null object
        return nullProduct;
    }
    return iterator->second;
}

void ProductMap::load()
{
    // variable that will have list of all products

    std::string content;
    FileHandler::readFromFile("products", content);
    /**
     * For each line
     * 1. split the line by comma
     * 2. col-1 -> id
     * 3. col-2 -> name
     * 4. col-3 -> price
     * 5. col-4 -> type (electronics, grocery, clothing)
     * 6. col-5 -> sub type (gadgetType, groceryType, clothingAgeType)
     */
    std::istringstream stream(content);

    std::string line;

    // empty the map
    products.clear();

    while (std::getline(stream, line))
    {
        std::istringstream lineStream(line);

        int id, type, subType;
        std::string name;
        double price;

        // Parse individual columns
        lineStream >> id;
        lineStream.ignore(); // Skip the comma
        std::getline(lineStream, name, ',');
        lineStream >> price;
        lineStream.ignore(); // Skip the comma
        lineStream >> type;
        lineStream.ignore(); // Skip the comma
        lineStream >> subType;

        Product::ProductType pt = static_cast<Product::ProductType>(type);
        std::unique_ptr<Product> product;

        switch (pt)
        {
        case 0:
            product = std::make_unique<Electronics>(id, name, price, pt, static_cast<Electronics::GadgetType>(subType));
            break;
        case 1:
            product = std::make_unique<Grocery>(id, name, price, pt, static_cast<Grocery::GroceryType>(subType));
            break;
        case 2:
            product = std::make_unique<Clothing>(id, name, price, pt, static_cast<Clothing::ClothingAgeType>(subType));
            break;
        }

        ProductMap::addProductToMap(id, std::move(product));
    }
}

void ProductMap::display()
{
    std::cout << "Displaying products" << std::endl;
    for (auto &product : products)
    {
        std::cout << "=================" << std::endl;
        product.second->display();
        std::cout << "=================" << std::endl;
    }
}