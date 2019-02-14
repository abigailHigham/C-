// File: LayerCake.cpp
//-----------------------------------------------------------------------------
#include "LayerCake.h"
//-----------------------------------------------------------------------------
#include <sstream>
using namespace std;
//-----------------------------------------------------------------------------
LayerCake::LayerCake()
    : Cake(), layers(0)
{
}
//-----------------------------------------------------------------------------
LayerCake::LayerCake(string flavor, string frosting, int layers)
    : Cake(flavor, frosting), layers(layers)
{
    const double BASE_PRICE = 9.0;
    const double CREAM_CHEESE = 1.0;
    const double LAYER = 3.0;
    this->price = BASE_PRICE;
    if (frosting == "cream-cheese")
        this->price += layers * CREAM_CHEESE;
    this->price += (layers - 1) * LAYER;
}
//-----------------------------------------------------------------------------
string LayerCake::toString() const
{
    ostringstream str;
    str << layers << "-layer " << flavor << " cake with "
        << frosting << " frosting" << BakedGood::toString();
    return str.str();
}
//-----------------------------------------------------------------------------
double LayerCake::discountedPrice(int count) const
{
    const int MIN_FOR_DISCOUNT  = 3;
    const double DISCOUNT = 2.0;

    if (count >= MIN_FOR_DISCOUNT)
        return (this->price - DISCOUNT) * count;

    return this->price  * count;
}
//-----------------------------------------------------------------------------
