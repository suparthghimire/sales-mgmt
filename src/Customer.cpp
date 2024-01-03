#include "include/Customer.hpp"
#include "include/FileHandler.hpp"
#include <random>
#include <chrono>

#include <iostream>

int Customer::obj_id = 0;

Customer::Customer(std::string name)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Generate a random number between 0 and 99
    std::uniform_int_distribution<int> distribution(0, 99);
    int random_number = distribution(generator);

    this->id = random_number + (++obj_id);
    this->name = name;
}

void Customer::to_csv()
{

    std::string fileName = "customers";
    std::string data = std::to_string(this->id) + "," + this->name;
    FileHandler::writeFile(fileName, data);
}

void Customer::display()
{
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Name: " << this->name << std::endl;
}

int Customer::getId()
{
    return this->id;
}