#include "softmax.hpp"
#include <math.h>  

Softmax::Softmax() : Layer(), beta(1) {};
Softmax::Softmax(int incoming_units) : beta(1) 
{
    this->incoming_units = incoming_units;
};

Matrix<float> Softmax::perform_calculations_forward(Matrix<float> input)
{
    std::cout << "Softmax" << std::endl;
    std::cout << input << std::endl;
    float sum = 0;
    for (int i = 0; i < input.get_rows(); ++i)
        std::cout << input(i, 0) << std::endl;
        //sum += exp(float(input(i, 0)));
   
    for (int i = 0; i < input.get_rows(); ++i)
        input(i, 0) = exp(input(i, 0)) / sum;

    return input;
};
void Softmax::set_beta(float beta)
{
    beta = beta;
}