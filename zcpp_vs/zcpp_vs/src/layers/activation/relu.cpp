#include "relu.hpp"

ReLU::ReLU() : ActivationLayer(), actv_point(0), coeff(1) {};
ReLU::ReLU(int incoming_units) : ActivationLayer(incoming_units), actv_point(0), coeff(1) {};

float ReLU::calculate_result(float input)
{
    return coeff * input ? input > actv_point: 0;
};
float ReLU::calculate_derivative(float input)
{
    return 1 ? input > actv_point: 0;
}
void ReLU::set_actv_point(float actv_point)
{
    actv_point = actv_point;
}
void ReLU::set_coeff(float coeff)
{
    coeff = coeff;
}