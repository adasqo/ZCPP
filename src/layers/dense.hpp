#pragma once
#include "layer.hpp"
#include "../matrix/matrix.hpp"

class Dense: public Layer
{
    public:
        Dense(): Layer(){};
        Dense(int units): Layer(units) {};
        Dense(int units, int incoming_units): Layer(units, incoming_units) {};

        Matrix<float> perform_calculations(Matrix<float> input) override
        {
            Matrix<float> output = Matrix<float>(); 
            return output;
        };
};