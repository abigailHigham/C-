// File: main.cpp
//-----------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
//-----------------------------------------------------------------------------
#include "Bread.h"
#include "LayerCake.h"
#include "CupCake.h"
//-----------------------------------------------------------------------------
int main()
{
    vector<BakedGood*> goods;

    bool done = false;

    cout << "**Bread and Cakes Bakery**\n\n";
    cout << "Enter sub-order (enter \"done\" to finish)\n";

    /// Part 1 - Enter the bakery order and create class objects

    while (!done)
    {
        cout << "Sub-order: ";

        string bakedGood;
        int quantity;

        cin >> bakedGood;

        if (bakedGood == "Bread")
        {
            string variety;
            cin >> variety >> quantity;

            for (int i = 0; i < quantity; ++i)
                goods.push_back(new Bread(variety));
        }
        else if (bakedGood == "Layer-cake")
        {
            string flavor, frosting;
            int layers;
            cin >> flavor >> frosting;
            cin >> layers >> quantity;

            for (int i = 0; i < quantity; ++i)
                goods.push_back(new LayerCake(flavor, frosting, layers));

        }
        else if (bakedGood == "Cupcake")
        {
            string flavor, frosting;
            string color;
            cin >> flavor >> frosting;
            cin >> color >> quantity;

            for (int i = 0; i < quantity; ++i)
                goods.push_back(new CupCake(flavor, frosting, color));
        }
        else
            done = true;
    }

    /// Part 2 - Confirm proper class creation by printing your vector with toString

    cout << "\nOrder Confirmations:\n";

    for (size_t i = 0; i < goods.size(); ++i)
        cout << goods[i]->toString() << endl;

    /// Part 3 - Print an Invoice

    int totalQuantity = 0;
    double totalPrice = 0.0;

    // vector for unique goods strings
    vector<string> uniqueGoods;

    // collect unique goods strings
    for (size_t i = 0; i < goods.size(); ++i)
    {
        string str = goods[i]->toString();
        size_t j = 0;

        for (; j < uniqueGoods.size(); ++j)
        {
            if (str == uniqueGoods[j]) // already exist
                break;
        }
        // if does not exist yet
        if (j == uniqueGoods.size())
            uniqueGoods.push_back(str);
    }

    cout << "\nInvoice:\n";
    cout << setw(75) << left << "Baked Good" << endl;
    cout << setw(9) << left << "Quantity" << setw(9) << "Total" << endl;

    // set  floating-point format
    cout << fixed << setprecision(2);

    // for each the unique baked good
    for (size_t i = 0; i < uniqueGoods.size(); ++i)
    {
        int quantity = 0;       // unique counter
        double price = 0.0;     // unique total price

        // pointer to one of the unique good to call discountedPrice()
        BakedGood* bakedGoodPtr = NULL;

        // Counting the unique goods
        for (size_t j = 0; j < goods.size(); ++j)
        {
            if (goods[j]->toString() == uniqueGoods[i])
            {
                ++quantity;         // count

                if (!bakedGoodPtr)  // initialize pointer
                    bakedGoodPtr = goods[j];
            }
        }

        totalQuantity += quantity;
        price = bakedGoodPtr->discountedPrice(quantity);
        totalPrice += price;

        // print unique good string, quantity and total price
        cout << setw(75) << left << uniqueGoods[i] << endl;
        cout << setw(9) << left << quantity << setw(9) << price << endl;
    }

    // print Totals
    cout << setw(9) << left << "Totals" << endl;
    cout << setw(9) << left << totalQuantity << setw(9) << totalPrice << endl;

    cout << "Good Bye" << endl;

    /// Delete dynamically allocated objects

    for (size_t i = 0; i < goods.size(); ++i)
        delete goods[i];

    return 0;
}
//-----------------------------------------------------------------------------
