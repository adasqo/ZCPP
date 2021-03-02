#include "softmax.hpp"
#include <math.h>  

Softmax::Softmax() : ActivationLayer(), beta(1) {};
Softmax::Softmax(int incoming_units) : ActivationLayer(incoming_units), beta(1) {} ;

float calculate_derivative(float)
{
    return 0;
};
Matrix<float> Softmax::transfer_result(Matrix<float> input)
{
    float sum = 0;
    for (int i = 0; i < input.get_rows(); ++i)
        sum += exp(float(input(i, 0)));
   
    for (int i = 0; i < input.get_rows(); ++i)
        input(i, 0) = exp(input(i, 0)) / sum;

    return input;
};
Matrix<float> Softmax::transfer_derivative(Matrix<float> input)
{
    // TO DO
    float sum = 0;
    for (int i = 0; i < input.get_rows(); ++i)
        sum += exp(float(input(i, 0)));

    for (int i = 0; i < input.get_rows(); ++i)
        input(i, 0) = exp(input(i, 0)) / sum;

    return input;
};
void Softmax::set_beta(float beta)
{
    beta = beta;
}