// File: LayerCake.h
//-----------------------------------------------------------------------------
#ifndef LAYERCAKE_H
#define LAYERCAKE_H
//-----------------------------------------------------------------------------
#include "Cake.h"
//-----------------------------------------------------------------------------
class LayerCake : public Cake
{
public:
    LayerCake();
    LayerCake(string flavor, string frosting, int layers);

    string toString() const;
    double discountedPrice(int count) const;
protected:
    int layers;
};
//-----------------------------------------------------------------------------
#endif // LAYERCAKE_H
