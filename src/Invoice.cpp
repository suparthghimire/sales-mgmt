#include "include/Invoice.hpp"
#include "include/Customer.hpp"
#include "include/CustomerMap.hpp"
#include "include/FileHandler.hpp"
#include <vector>
#include <fstream>
#include <iomanip>
#include <memory>
#include <random>
#include <chrono>

int Invoice::obj_id = 0;

Invoice::Invoice(int customerId, int year, int month, int day)
{
    this->id = ++obj_id;

    this->customerId = customerId;
    this->year = year;
    this->month = month;
    this->day = day;
}

void Invoice::addItem(Product &product, int qty, int total)
{
    // calculate new total
    this->grand_total += total;
    std::unique_ptr<InvoiceItem> invoiceItem = std::make_unique<InvoiceItem>(product, qty, total);
    this->invoiceItems.push_back(std::move(invoiceItem));
}

void Invoice::display()
{
    // format
    std::cout << "Invoice ID: " << this->id << std::endl;
    std::cout << "Customer" << std::endl;

    std::unique_ptr<Customer> &customer = CustomerMap::getSingleCustomer(this->customerId);

    if (customer == nullptr)
    {
        std::cout << "Customer not found" << std::endl;
        return;
    }

    customer->display();
    std::cout << std::endl;
    std::cout << "Date: " << this->day << "/" << this->month << "/" << this->year << std::endl;

    std::cout << std::setw(20) << std::left << "Items";
    std::cout << std::setw(10) << std::right << "Price";
    std::cout << std::setw(10) << std::right << "Qty";
    std::cout << std::setw(10) << std::right << "Total" << std::endl;

    std::cout << "-----------------------------------------------------------" << std::endl;

    for (auto &item : this->invoiceItems)
    {
        std::cout << std::setw(20) << std::left << item->product.getName();
        std::cout << std::setw(10) << std::right << item->product.getPrice();
        std::cout << std::setw(10) << std::right << item->quantity;
        std::cout << std::setw(10) << std::right << item->total << std::endl;
    }

    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "Grand Total: " << this->grand_total << std::endl;
}

void Invoice::saveToFile()
{
    // first display the invoice
    // whatever is in out buffer, write that to text file

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Generate a random number between 0 and 99
    std::uniform_int_distribution<int> distribution(0, 99);
    int random_number = distribution(generator);

    std::string name = "invoice_" + std::to_string(this->id) + std::to_string(random_number) + ".txt";
    std::string path = "data/invoices/" + name;
    std::ofstream output(path);

    std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
    std::cout.rdbuf(output.rdbuf());             // redirect std::cout to out.txt!

    this->display();

    std::cout.rdbuf(coutbuf); // reset to standard output again

    // close the file
    output.close();
}

int Invoice::getId()
{
    return this->id;
}
