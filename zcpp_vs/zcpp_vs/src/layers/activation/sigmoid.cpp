#include "sigmoid.hpp"
#include <math.h>

Sigmoid::Sigmoid() : ActivationLayer(), beta(1)
{
    name = "Sigmoid";
};
Sigmoid::Sigmoid(int incoming_units) : ActivationLayer(incoming_units), beta(1)
{
    name = "Sigmoid";
};

float Sigmoid::calculate_result(float input)
{
    return (float)((float)1 / (float)(1 + exp(-beta * input)));
};
float Sigmoid::calculate_derivative(float input)
{
    return calculate_result(input) * (1 - calculate_result(input));
};
void Sigmoid::set_beta(float beta)
{
    beta = beta;
}
std::string Sigmoid::return_information()
{
    std::string info = "{\n \
                        name: Sigmoid,\n \
                        incoming_inputs: " + std::to_string(incoming_units) + ",\n \
                        units: " + std::to_string(units) + ",\n \
                        beta: " + std::to_string(beta) + "\n}";
    return info;
};
