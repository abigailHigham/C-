#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using std::string;

class ItemToPurchase
{
public:
    ItemToPurchase(string name = "none",
                   string description = "none",
                   float price = 0.0,
                   int quantity = 0);
    // Getters
    string getName();
    string getDescription();
    float getPrice();
    int getQuantity();

    // Setters
    void setName(string name);
    void setDescription(string description);
    void setPrice(float price);
    void setQuantity(int quantity);

    // Prints function
    void printPrice();
    void printDescription();
private:
    string  name;
    string  description;
    float   price;
    int     quantity;
};

#endif // ITEMTOPURCHASE_H
