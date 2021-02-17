#pragma once
#include "layer.hpp"

class Dense: public Layer
{
    public:
        Dense(int units): Layer(units) {};
        // virtual void add();
        // virtual void compile();
};