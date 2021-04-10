#pragma once
#include "dense.hpp"
#include "layer.hpp"
#include "../matrix/matrix.hpp"
#include <time.h>
#include <tuple>

Dense::Dense() : Layer()
{
    weights = Matrix<float>();
};
Dense::Dense(int units) : Layer(units)
{
    weights = Matrix<float>();
};
Dense::Dense(int incoming_units, int units) : Layer(incoming_units, units)
{
    weights = Matrix<float>(incoming_units, units);
    initiatie_weights();
};

void Dense::initiatie_weights()
{
    srand(time(NULL));
    for (int i = 0; i < incoming_units; ++i)
        for (int j = 0; j < units; ++j)
            //weights(i, j) = 0;
            weights(i, j) = float(float(rand()) / float(RAND_MAX)) - 0.5;
}
Matrix<float> Dense::perform_calculations_forward(Matrix<float> input)
{
    result = input;
    Matrix<float> bias = Matrix<float>(weights.get_cols(), 1);
    for (int i = 0; i < bias.get_rows(); ++i)
        bias(i, 0) = 0;
    if(input.get_rows() != weights.get_rows())
        throw std::out_of_range("Index out of bounds");
    output = weights.transpose() * input;

    return output;
};
Matrix<float> Dense::perform_calculations_backward(Matrix<float> derivative, float alpha)
{
    //std::cout << derivative << std::endl;
    update_weights(derivative, alpha);
    return weights * derivative;
};
void Dense::update_weights(Matrix<float> derivative, float alpha)
{
    //std::cout << result << std::endl;
    //std::cout << derivative.transpose() << std::endl;
    //std::cout << result * derivative.transpose() * alpha << std::endl;
    weights = weights - result * derivative.transpose() * alpha;
}
