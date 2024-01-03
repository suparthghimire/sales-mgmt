#pragma once
#include <map>
#include <memory>
#include "Customer.hpp"

typedef std::map<int, std::unique_ptr<Customer>> T_CustomerMap;

class CustomerMap
{
private:
    static T_CustomerMap customers;

public:
    static void addCustomer(std::unique_ptr<Customer> customer);
    static T_CustomerMap getAllCustomers();
    static std::unique_ptr<Customer> getSingleCustomer(int id);
    static void load();
    static void display();
};