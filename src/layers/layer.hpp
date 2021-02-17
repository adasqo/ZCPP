#pragma once
#include "../matrix/matrix.hpp"

class Layer
{
    protected:
        int units;
        int incoming_units;
        Matrix<float> m;
    public:
        Layer();
        Layer(int);
        Layer(int, int);
};

Layer::Layer(){}
Layer::Layer(int units): units(units){}
Layer::Layer(int units, int incoming_units): units(units), incoming_units(incoming_units) 
{
    m = Matrix<float>(incoming_units + 1, units);
}