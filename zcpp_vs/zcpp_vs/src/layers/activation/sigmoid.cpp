#include "sigmoid.hpp"
#include <math.h>

Sigmoid::Sigmoid() : ActivationLayer() {};
Sigmoid::Sigmoid(int incoming_units) : ActivationLayer(incoming_units) {};

float Sigmoid::calculate_result(float input)
{
    return 1 / (1 + exp(-input));
};
float Sigmoid::calculate_derivative(float input)
{
    return calculate_result(input) * (1 - calculate_result(input));
};
