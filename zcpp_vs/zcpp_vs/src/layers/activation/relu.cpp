#include "relu.hpp"

ReLU::ReLU() : Layer(), actv_point(0), coeff(1) {};
ReLU::ReLU(int incoming_units): actv_point(0), coeff(1) 
{
    this->incoming_units = incoming_units;
};

Matrix<float> ReLU::perform_calculations_forward(Matrix<float> input)
{
    std::cout << "ReLU" << std::endl;
    std::cout << input << std::endl;
    for (int i = 0; i < input.get_rows(); ++i)
        if (input(i, 0) > actv_point)
            input(i, 0) *= coeff;
        else
            input(i, 0) = 0;

    return input;
};
void ReLU::set_actv_point(float actv_point)
{
    actv_point = actv_point;
}
void ReLU::set_coeff(float coeff)
{
    coeff = coeff;
}