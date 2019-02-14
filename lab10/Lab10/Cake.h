// File: Cake.h
//-----------------------------------------------------------------------------
#ifndef CAKE_H
#define CAKE_H
//-----------------------------------------------------------------------------
#include "BakedGood.h"
//-----------------------------------------------------------------------------
// Abstract base class
class Cake : public BakedGood
{
public:
    Cake();
    Cake(string flavor, string frosting);
protected:
    string flavor;
    string frosting;
};
//-----------------------------------------------------------------------------
#endif // CAKE_H
