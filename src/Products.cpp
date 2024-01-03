#include "include/Product.hpp"
#include "include/FileHandler.hpp"
#include <memory>
#include <string>
#include <random>
#include <chrono>

int Product::obj_id = 0;

// required when user is entering data
Product::Product(std::string name, Product::ProductType type)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Generate a random number between 0 and 99
    std::uniform_int_distribution<int> distribution(0, 99);
    int random_number = distribution(generator);

    this->id = random_number + (++obj_id);

    this->id = id;
    this->name = name;
    this->type = type;
}

// required when loading from file
Product::Product(int id, std::string name, double price, Product::ProductType type)
{
    this->id = id;
    this->name = name;
    this->price = price;
    this->type = type;
}

int Product::getId()
{
    return this->id;
}
double Product::getPrice()
{
    return this->price;
}

std::string Product::getName()
{
    return this->name;
}