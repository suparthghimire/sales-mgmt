#include "include/Menu.hpp"
#include "include/InvoiceMap.hpp"
#include "include/CustomerMap.hpp"
#include "include/ProductMap.hpp"
#include "include/Invoice.hpp"
#include <iostream>
#include <memory>

void createInvoice()
{
    // ask for customer id
    // ask for date
    int customerId;
    int day, month, year;

    std::cout << "Enter customer id: ";
    std::cin >> customerId;

    std::unique_ptr<Customer> &customer = CustomerMap::getSingleCustomer(customerId);

    if (!customer)
    {
        std::cout << "Customer not found" << std::endl;
        return;
    }

    std::cout << "Enter year ";
    std::cin >> year;

    std::cout << "Enter month ";
    std::cin >> month;

    std::cout << "Enter day ";
    std::cin >> day;

    // Invoice invoice(customerId, year, month, day);
    std::unique_ptr<Invoice> invoicePtr = std::make_unique<Invoice>(customerId, year, month, day);
    InvoiceMap::addInvoice(std::move(invoicePtr));
}

void addProductToInvoice()
{

    // ask for invoice id
    int invoiceId;
    std::cout << "Enter invoice id: ";
    std::cin >> invoiceId;

    // check if invoice exists

    std::unique_ptr<Invoice> &invoice = InvoiceMap::getInvoice(invoiceId);

    if (!invoice)
    {
        std::cout << "Invoice not found" << std::endl;
        return;
    }

    int productId;
    std::cout << "Enter product id: ";
    std::cin >> productId;

    std::unique_ptr<Product> &product = ProductMap::getSingleProduct(productId);

    if (!product)
    {
        std::cout << "Product not found" << std::endl;
        return;
    }

    // ask for quantity
    int quantity;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    double total = quantity * product->getPrice();

    invoice->addItem(*product, quantity, total);
}

void displayInvoice()
{
    int invoiceId;
    std::cout << "Enter invoice id: ";
    std::cin >> invoiceId;

    std::unique_ptr<Invoice> &invoice = InvoiceMap::getInvoice(invoiceId);

    if (!invoice)
    {
        std::cout << "Invoice not found" << std::endl;
        return;
    }

    invoice->display();
}

void saveToFile()
{

    int id;
    std::cout << "Enter invoice id: ";
    std::cin >> id;

    std::unique_ptr<Invoice> &invoice = InvoiceMap::getInvoice(id);

    if (!invoice)
    {
        std::cout << "Invoice not found" << std::endl;
        return;
    }

    invoice->saveToFile();
}

int Menu::InvoiceMenu()
{
    std::string menu_items[6] = {
        "1. Create Invoice",
        "2. Add product to invoice",
        "3. Display Single Invoice",
        "4. Display All Invoices",
        "5. Save Invoice",
        "6. Back",
    };

    system("clear");
    system("cls");
    int choice = DisplayMenu(menu_items, 6);

    switch (choice)
    {
    case 1:
    {
        std::cout << "Create Invoice" << std::endl;
        createInvoice();
        Menu::PressKeyToContinue();
        return 0;
    }
    case 2:
        std::cout << "Add product to invoice" << std::endl;
        addProductToInvoice();
        Menu::PressKeyToContinue();
        return 0;

    case 3:
        std::cout << "Display Single Invoice" << std::endl;
        displayInvoice();
        Menu::PressKeyToContinue();
        return 0;
    case 4:
        std::cout << "Display All Invoice" << std::endl;
        InvoiceMap::display();
        Menu::PressKeyToContinue();
        return 0;
    case 5:
        std::cout << "Save Invoice" << std::endl;
        saveToFile();
        Menu::PressKeyToContinue();
        return 0;
    case 6:
        return 0;
    default:
        std::cout << "Invalid choice" << std::endl;
        Menu::PressKeyToContinue();
        return 0;
    }

    // Add implementation for handling the choice in the InvoiceMenu
}
