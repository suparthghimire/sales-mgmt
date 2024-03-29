#pragma once

#include <string>

class Menu
{
public:
    static int DisplayMenu(std::string menu_items[], int menu_items_length);
    static int StartMenu();
    static int InvoiceMenu();
    static int CustomerMenu();
    static int ProductMenu();
    static void PressKeyToContinue();
};