#include "relu.hpp"

ReLU::ReLU() : ActivationLayer(), actv_point(0), coeff(1) 
{
    name = "ReLU";
};
ReLU::ReLU(int incoming_units) : ActivationLayer(incoming_units), actv_point(0), coeff(1) 
{
    name = "ReLU";
};

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
std::string ReLU::return_information()
{
    std::string info = "{\n \
                        name: ReLU,\n \
                        incoming_inputs: " + std::to_string(incoming_units) + ",\n \
                        units: " + std::to_string(units) + ",\n \
                        actv_point: " + std::to_string(actv_point) + ",\n \
                        coeff: " + std::to_string(coeff) + "\n}";
    return info;
};