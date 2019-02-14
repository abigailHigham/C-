// File: CupCake.cpp
//-----------------------------------------------------------------------------
#include "CupCake.h"
//-----------------------------------------------------------------------------
#include <sstream>
using namespace std;
//-----------------------------------------------------------------------------
CupCake::CupCake()
    : Cake(), color("None")
{
}
//-----------------------------------------------------------------------------
CupCake::CupCake(string flavor, string frosting, string color)
    : Cake(flavor, frosting), color(color)
{
    const double BASE_PRICE = 1.95;
    const double CREAM_CHEESE = 0.2;
    this->price = BASE_PRICE;
    if (frosting == "cream-cheese")
        this->price += CREAM_CHEESE;
}
//-----------------------------------------------------------------------------
string CupCake::toString() const
{
    ostringstream str;
    str << flavor << " cupcake with " << frosting << " frosting and "
        << color << " sprinkles" << BakedGood::toString();
    return str.str();
}
//-----------------------------------------------------------------------------
double CupCake::discountedPrice(int count) const
{
    const int MIN_FOR_DISCOUNT1  = 2;
    const double DISCOUNT1 = 0.3;
    const int MIN_FOR_DISCOUNT2  = 4;
    const double DISCOUNT2 = 0.4;

    if (count < MIN_FOR_DISCOUNT1)
        return this->price * count;
    if (count < MIN_FOR_DISCOUNT2)
        return (this->price - DISCOUNT1) * count;

    return (this->price - DISCOUNT2) * count;
}
//-----------------------------------------------------------------------------
