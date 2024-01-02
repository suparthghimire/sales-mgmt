#include "include/Customer.hpp"
#include "include/FileHandler.hpp"

#include <iostream>

int Customer::obj_id = 0;

Customer::Customer(std::string name)
{
    this->id = ++obj_id;
    this->name = name;
}

void Customer::to_csv()
{

    std::string fileName = "customers";
    std::string data = std::to_string(this->id) + "," + this->name;
    FileHandler::writeFile(fileName, data);
}