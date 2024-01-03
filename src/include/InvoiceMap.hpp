#pragma once
#include "Invoice.hpp"

typedef std::map<int, std::unique_ptr<Invoice>> T_InvoiceMap;

class InvoiceMap
{
private:
    static T_InvoiceMap invoiceMap;

public:
    static void addInvoice(std::unique_ptr<Invoice> invoice);
    static T_InvoiceMap getInvoiceMap();
    static std::unique_ptr<Invoice> &getInvoice(int id);
    static void display();
};
