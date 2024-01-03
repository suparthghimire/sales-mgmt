#pragma once
#include "Product.hpp"
#include "Customer.hpp"
#include <string>
#include <memory>
#include <vector>
#include <iostream>

struct InvoiceItem
{
    Product &product;
    int quantity;
    double total;

    InvoiceItem(Product &product, int quantity, double total)
        : product(product), quantity(quantity), total(total)
    {
    }
};

class Invoice
{
    static int obj_id;

private:
    int id;

    std::vector<std::unique_ptr<InvoiceItem>> invoiceItems;
    int customerId;
    int quantity;
    double grand_total;
    // date
    int year;
    int month;
    int day;

public:
    Invoice(int customerId, int year, int month, int day);
    void addItem(Product &product, int qty, int total);
    void display();
    void saveToFile();
    int getId();
};
