#include "ShoppingCart.h"

#include <iostream>
using std::cout;
using std::endl;
//-----------------------------------------------------------------------------
ShoppingCart::ShoppingCart(string name, string date)
    : name(name), date(date), items()
{
}
//-----------------------------------------------------------------------------
string ShoppingCart::getName()
{
    return name;
}
//-----------------------------------------------------------------------------
string ShoppingCart::getDate()
{
    return date;
}
//-----------------------------------------------------------------------------
void ShoppingCart::addItem(ItemToPurchase item)
{
    int index = findItem(item.getName());
    if (index == -1)
        items.push_back(item);
    else
        cout << "Item is already in cart. Nothing added." << endl;
}
//-----------------------------------------------------------------------------
void ShoppingCart::removeItem(string itemName)
{
    int index = findItem(itemName);
    if (index != -1)
        items.erase(items.begin() + index);
    else
        cout << "Item not found in cart. Nothing removed." << endl;
}
//-----------------------------------------------------------------------------
void ShoppingCart::updateItem(string itemName, int quantity)
{
    int index = findItem(itemName);
    if (index != -1)
        items[index].setQuantity(quantity);
    else
        cout << "Item not found in cart. Nothing modified." << endl;
}
//-----------------------------------------------------------------------------
int ShoppingCart::getTotalQuantity()
{
    int total = 0;
    for (size_t i = 0; i < items.size(); ++i)
        total += items[i].getQuantity();
    return total;
}
//-----------------------------------------------------------------------------
float ShoppingCart::getTotalCost()
{
    float total = 0.0;
    for (size_t i = 0; i < items.size(); ++i)
        total += items[i].getQuantity() * items[i].getPrice();
    return total;
}
//-----------------------------------------------------------------------------
void ShoppingCart::printCost()
{
    printCartHeader();
    if (getTotalQuantity())
    {
        cout << "Number of Items: " << getTotalQuantity() << endl;
        cout << endl;
        for (size_t i = 0; i < items.size(); ++i)
        {
            if (items[i].getQuantity() != 0) // skip empty items
            {
                items[i].printPrice();
                cout << endl;
            }
        }
        cout << endl;
        cout << "Total: $" << getTotalCost() << endl;
    }
    else
        cout << "Shopping cart is empty." << endl;
}
//-----------------------------------------------------------------------------
void ShoppingCart::printDescription()
{
    printCartHeader();
    if (getTotalQuantity())
    {
        cout << "Item Descriptions" << endl;
        for (size_t i = 0; i < items.size(); ++i)
        {
            if (items[i].getQuantity() != 0) // skip empty items
            {
                items[i].printDescription();
                cout << endl;
            }
        }
    }
    else
        cout << "Shopping cart is empty." << endl;
}
//-----------------------------------------------------------------------------
int ShoppingCart::findItem(string name)
{
    for (size_t i = 0; i < items.size(); ++i)
        if (items[i].getName() == name)
            return i;
    return -1;
}
//-----------------------------------------------------------------------------
void ShoppingCart::printCartHeader()
{
    cout << name << "'s Shopping Cart - " << date << endl;
}
//-----------------------------------------------------------------------------
