#include "softmax.hpp"
#include <math.h>  
#include <tuple>

Softmax::Softmax() : ActivationLayer(), beta(1) {};
Softmax::Softmax(int incoming_units) : ActivationLayer(incoming_units), beta(1) {} ;

float Softmax::calculate_result(float) { return 0; };
float Softmax::calculate_derivative(float) { return 0; };
Matrix<float> Softmax::transfer_result(Matrix<float> input)
{
    float sum = 0;
    for (int i = 0; i < input.get_rows(); ++i)
        sum += exp(float(input(i, 0)));
   
    for (int i = 0; i < input.get_rows(); ++i)
        input(i, 0) = exp(float(input(i, 0))) / sum;

    return input;
};
std::tuple<Matrix<float>, Matrix<float>> Softmax::transfer_derivative(Matrix<float> input)
{
    Matrix<float> out = Matrix<float>(input.get_rows(), 1);
    for (int i = 0; i < out.get_rows(); i++)
        out(i, 0) = 1;
    return std::make_tuple(input, out);
};
void Softmax::set_beta(float beta)
{
    beta = beta;
}