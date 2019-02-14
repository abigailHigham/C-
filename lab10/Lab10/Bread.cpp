// File: Bread.cpp
//-----------------------------------------------------------------------------
#include "Bread.h"
//-----------------------------------------------------------------------------
#include <sstream>
using namespace std;
//-----------------------------------------------------------------------------
Bread::Bread() : BakedGood(), variety("NoName")
{

}
//-----------------------------------------------------------------------------
Bread::Bread(string variety) : BakedGood(), variety(variety)
{
    const double BASE_PRICE = 4.5;
    this->price = BASE_PRICE;
}
//-----------------------------------------------------------------------------
string Bread::toString() const
{
    ostringstream str;
    str << variety << " bread" << BakedGood::toString();
    return str.str();
}
//-----------------------------------------------------------------------------
double Bread::discountedPrice(int count) const
{
    const int FREE_EVERY_OF = 3;

    return this->price * ((count / FREE_EVERY_OF) * (FREE_EVERY_OF - 1) + count % FREE_EVERY_OF);
}
//-----------------------------------------------------------------------------
