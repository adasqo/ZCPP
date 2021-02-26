#pragma once
#include "dense.hpp"
#include "layer.hpp"
#include "../matrix/matrix.hpp"


Dense::Dense() : Layer() {};
Dense::Dense(int units) : Layer(units) {};
Dense::Dense(int units, int incoming_units) : Layer(units, incoming_units) {};

Matrix<float> Dense::perform_calculations(Matrix<float> input)
{
    Matrix<float> output = Matrix<float>();
    return output;
};
