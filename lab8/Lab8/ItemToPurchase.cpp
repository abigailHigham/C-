#include "ItemToPurchase.h"

#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::fixed;
using std::setprecision;
//-----------------------------------------------------------------------------
ItemToPurchase::ItemToPurchase(string name,
                               string description,
                               float price,
                               int quantity)
    : name(name), description(description), price(price), quantity(quantity)
{
}
//-----------------------------------------------------------------------------
string ItemToPurchase::getName()
{
    return name;
}
//-----------------------------------------------------------------------------
string ItemToPurchase::getDescription()
{
    return description;
}
//-----------------------------------------------------------------------------
float ItemToPurchase::getPrice()
{
    return price;
}
//-----------------------------------------------------------------------------
int ItemToPurchase::getQuantity()
{
    return quantity;
}
//-----------------------------------------------------------------------------
void ItemToPurchase::setName(string name)
{
    this->name = name;
}
//-----------------------------------------------------------------------------
void ItemToPurchase::setDescription(string description)
{
    this->description = description;
}
//-----------------------------------------------------------------------------
void ItemToPurchase::setPrice(float price)
{
    this->price = price;
}
//-----------------------------------------------------------------------------
void ItemToPurchase::setQuantity(int quantity)
{
    this->quantity = quantity;
}
//-----------------------------------------------------------------------------
void ItemToPurchase::printPrice()
{
    cout << fixed << setprecision(2);
    cout << name << " " << quantity << " @ $" << price << " = $" << quantity * price;
}
//-----------------------------------------------------------------------------
void ItemToPurchase::printDescription()
{
    cout << name << ": " << description;
}
//-----------------------------------------------------------------------------
