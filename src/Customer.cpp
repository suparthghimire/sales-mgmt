#include "include/Customer.hpp"
#include "include/FileHandler.hpp"

#include <iostream>

int Customer::obj_id = 0;

Customer::Customer(std::string name)
{
    this->id = ++obj_id;
    this->name = name;
}

void Customer::save()
{

    std::string fileName = std::to_string(this->id) + "-" + this->name;
    std::string fileParent = "customers";
    std::string path = fileParent + "/" + fileName + ".txt";
    std::string data = std::to_string(this->id) + "\n" + this->name;

    FileHandler::writeFile(path, data);
}