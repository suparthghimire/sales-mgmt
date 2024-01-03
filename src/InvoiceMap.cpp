#include "include/InvoiceMap.hpp"

T_InvoiceMap InvoiceMap::invoiceMap;

void InvoiceMap::addInvoice(std::unique_ptr<Invoice> invoice)
{
    invoiceMap.emplace(invoice->getId(), std::move(invoice));
}

T_InvoiceMap InvoiceMap::getInvoiceMap()
{
    return std::move(invoiceMap);
}

std::unique_ptr<Invoice> &InvoiceMap::getInvoice(int id)
{
    // return std::move(invoiceMap[id]);
    auto it = invoiceMap.find(id);
    if (it == invoiceMap.end())
    {
        static std::unique_ptr<Invoice> nullInvoice; // Return a static null object
        return nullInvoice;
    }
    return it->second;
}

void InvoiceMap::display()
{
    for (auto &invoice : invoiceMap)
    {
        invoice.second->display();
    }
}
