// File: CupCake.h
//-----------------------------------------------------------------------------
#ifndef CUPCAKE_H
#define CUPCAKE_H
//-----------------------------------------------------------------------------
#include "Cake.h"
//-----------------------------------------------------------------------------
class CupCake : public Cake
{
public:
    CupCake();
    CupCake(string flavor, string frosting, string color);

    string toString() const;
    double discountedPrice(int count) const;
protected:
    string color;
};
//-----------------------------------------------------------------------------
#endif // CUPCAKE_H
