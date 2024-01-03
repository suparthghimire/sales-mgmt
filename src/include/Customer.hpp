#pragma once

#include <string>

// Class representing a Customer with a unique identifier and name.
class Customer
{
public:
    int id = 0; // Unique identifier for the customer.
private:
    static int obj_id;     // Static variable to track the next available customer ID.
    std::string name = ""; // Name of the customer.

public:
    // Constructor to initialize a Customer with a given name.
    Customer(std::string name);
    void to_csv();
    void display();
    int getId();
};
