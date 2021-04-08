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
           // weights(i, j) = float(float(rand()) / float(RAND_MAX));
            weights(i, j) = float(float(rand()) / float(RAND_MAX)) - 0.5;
}
Matrix<float> Dense::perform_calculations_forward(Matrix<float> input)
{
    Matrix<float> bias = Matrix<float>(weights.get_cols(), 1);
    for (int i = 0; i < bias.get_rows(); ++i)
        bias(i, 0) = 0.1;
    if(input.get_rows() != weights.get_rows())
        throw std::out_of_range("Index out of bounds");
    output = weights.transpose() * input;
    output = output + bias;
    return output;
};
std::tuple<Matrix<float>, Matrix<float>> Dense::perform_calculations_backward(std::tuple<Matrix<float>, Matrix<float>> derivative, float alpha)
{
    float error;
    Matrix<float> errors_out = Matrix<float>(weights.get_rows(), 1);
    for (int i = 0; i < weights.get_rows(); i++)
    {
        error = 0;
        for (int j = 0; j < weights.get_cols(); j++)
            error += weights(i, j) * (std::get<0>(derivative))(j, 0);
        errors_out(i, 0) = error;
    }
    update_weights(derivative, alpha);
    return std::make_tuple(errors_out, Matrix<float>());
};
void Dense::update_weights(std::tuple<Matrix<float>, Matrix<float>> derivative, float alpha)
{
    for (int i = 0; i < weights.get_rows(); i++)
        for (int j = 0; j < weights.get_cols(); j++)
            weights(i, j) -= alpha * (std::get<0>(derivative))(j, 0) * (std::get<1>(derivative))(j, 0);
}
