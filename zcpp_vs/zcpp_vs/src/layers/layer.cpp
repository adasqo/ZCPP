#pragma once
#include "layer.hpp"


Layer::Layer() {};
Layer::Layer(int units) : units(units) {};
Layer::Layer(int incoming_units, int units) : incoming_units(incoming_units), units(units) {};
