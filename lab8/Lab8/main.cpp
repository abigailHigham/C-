#include <iostream>

using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void menu();

int main()
{
    string name;
    string date;

    cout << "Enter Customer's Name: ";
    getline(cin, name);
    cout << "Enter Today's Date: ";
    getline(cin, date);

    ShoppingCart shoppingCart(name, date);

    string option;
    while (true)
    {
        cout << endl;
        cout << "Enter option: ";
        getline(cin, option);

        if (option == "add")
        {
            string name;
            string description;
            float price;
            int quantity;

            cout << "Enter the item name: ";
            getline(cin, name);
            cout << "Enter the item description: ";
            getline(cin, description);
            cout << "Enter the item price: ";
            cin >> price;
            cout << "Enter the item quantity: ";
            cin >> quantity;
            cin.get(); // ignore newline

            ItemToPurchase item(name, description, price, quantity);
            shoppingCart.addItem(item);
        }
        else if (option == "remove")
        {
            string name;
            cout << "Enter name of the item to remove: ";
            getline(cin, name);

            shoppingCart.removeItem(name);
        }
        else if (option == "change")
        {
            string name;
            int quantity;
            cout << "Enter the item name: ";
            getline(cin, name);
            cout << "Enter the item quantity: ";
            cin >> quantity;
            cin.get(); // ignore newline

            shoppingCart.updateItem(name, quantity);
        }
        else if (option == "descriptions")
        {
            shoppingCart.printDescription();
        }
        else if (option == "cart")
        {
            shoppingCart.printCost();
        }
        else if (option == "options")
        {
            menu();
        }
        else if (option == "quit")
        {
            break;
        }
        else
            menu();
    }

    cout << "Goodbye." << endl;

    return 0;
}

void menu()
{
    cout << "MENU" << endl;
    cout << "add - Add item to cart" << endl;
    cout << "remove - Remove item from cart" << endl;
    cout << "change - Change item quantity" << endl;
    cout << "descriptions - Output items' descriptions" << endl;
    cout << "cart - Output shopping cart" << endl;
    cout << "options - Print the options menu" << endl;
    cout << "quit - Quit" << endl;
}
