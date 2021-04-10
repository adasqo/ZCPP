#include "softmax.hpp"
#include <math.h>  
#include <tuple>

Softmax::Softmax() : ActivationLayer(), beta(1) {};
Softmax::Softmax(int incoming_units) : ActivationLayer(incoming_units), beta(1) {} ;

float Softmax::calculate_result(float) { return 0; };
float Softmax::calculate_derivative(float input)
{
    return (float)((float)1 / (float)(1 + exp(-input))) * (1 - (float)((float)1 / (float)(1 + exp(-input))));
};
Matrix<float> Softmax::transfer_result(Matrix<float> input)
{
    result = Matrix<float>(input.get_rows(), 1);
    float sum = 0;
    for (int i = 0; i < input.get_rows(); ++i)
        sum += exp(float(input(i, 0)));
   
    for (int i = 0; i < input.get_rows(); ++i)
        result(i, 0) = exp(float(input(i, 0))) / sum;

    return result;
};
void Softmax::set_beta(float beta)
{
    beta = beta;
}