// File: Bread.h
//-----------------------------------------------------------------------------
#ifndef BREAD_H
#define BREAD_H
//-----------------------------------------------------------------------------
#include "BakedGood.h"
//-----------------------------------------------------------------------------
class Bread : public BakedGood
{
public:
    Bread();
    Bread(string variety);

    string toString() const;
    double discountedPrice(int count) const;
protected:
    string variety;
};
//-----------------------------------------------------------------------------
#endif // BREAD_H
