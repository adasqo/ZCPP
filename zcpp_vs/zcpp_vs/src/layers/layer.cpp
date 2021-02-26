#pragma once
#include "layer.hpp"


Layer::Layer()
{
    weights = Matrix<float>();
};
Layer::Layer(int units) : units(units)
{
    weights = Matrix<float>();
};
Layer::Layer(int units, int incoming_units) : units(units), incoming_units(incoming_units)
{
    weights = Matrix<float>(incoming_units + 1, units);
};
