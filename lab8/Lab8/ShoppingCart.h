#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>
using std::string;
#include <vector>
using std::vector;

#include "ItemToPurchase.h"

class ShoppingCart
{
public:
    ShoppingCart(string name = "none",
                 string date = "January 1, 2016");

    string getName();
    string getDate();

    void addItem(ItemToPurchase item);
    void removeItem(string itemName);
    void updateItem(string itemName, int quantity);
    int getTotalQuantity();
    float getTotalCost();
    void printCost();
    void printDescription();
private:
    string name;
    string date;
    vector<ItemToPurchase> items;

    // Returns item index if exist or -1 otherwise
    int findItem(string name);
    // Prints cart header(customer name and date)
    void printCartHeader();
};

#endif // SHOPPINGCART_H
