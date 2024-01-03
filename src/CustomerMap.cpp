#include "include/CustomerMap.hpp"
#include "include/FileHandler.hpp"
#include <sstream>
T_CustomerMap CustomerMap::customers;

void CustomerMap::addCustomer(std::unique_ptr<Customer> customer)
{
    customers.emplace(std::make_pair(customer->id, std::move(customer)));
}

T_CustomerMap CustomerMap::getAllCustomers()
{
    return std::move(customers);
}

std::unique_ptr<Customer> CustomerMap::getSingleCustomer(int id)
{
    std::unique_ptr<Customer> customer = std::move(customers[id]);
    return customer;
}

void CustomerMap::load()
{
    std::string content;
    FileHandler::readFromFile("customers", content);

    /**
     * For each line
     * 1. split the line by comma
     * 2. col-1 -> id
     * 3. col-2 -> name
     */
    std::istringstream stream(content);

    std::string line;

    while (std::getline(stream, line))
    {
        std::istringstream lineStream(line);

        int id;
        std::string name;

        // Parse individual columns
        lineStream >> id;
        lineStream.ignore(); // Skip the comma
        std::getline(lineStream, name, ',');

        // Create a new customer object
        std::unique_ptr<Customer> customer = std::make_unique<Customer>(name);
        customer->id = id;

        // Add the customer to the map
        CustomerMap::addCustomer(std::move(customer));
    }
}
void CustomerMap::display()
{
    std::cout << "Displaying Customers" << std::endl;
    for (auto &customer : customers)
    {
        std::cout << "=================" << std::endl;
        customer.second->display();
        std::cout << "=================" << std::endl;
    }
}