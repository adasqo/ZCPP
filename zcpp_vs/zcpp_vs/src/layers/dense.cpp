#pragma once
#include "dense.hpp"
#include "layer.hpp"
#include "../matrix/matrix.hpp"
#include <time.h>
#include <tuple>

Dense::Dense() : Layer()
{
    name = "Dense";
    weights = Matrix<float>();
};
Dense::Dense(int units) : Layer(units)
{
    name = "Dense";
    weights = Matrix<float>();
};
Dense::Dense(int incoming_units, int units) : Layer(incoming_units, units)
{
    name = "Dense";
    weights = Matrix<float>(incoming_units, units);
    initiatie_weights();
};

void Dense::initiatie_weights()
{
    srand(time(NULL));
    for (int i = 0; i < incoming_units; ++i)
        for (int j = 0; j < units; ++j)
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
    update_weights(derivative, alpha);
    return weights * derivative;
};
void Dense::update_weights(Matrix<float> derivative, float alpha)
{
    weights = weights - result * derivative.transpose() * alpha;
}
std::string Dense::return_information()
{
    std::string info = "{\n \
                        name: Dense,\n \
                        incoming_inputs: " + std::to_string(incoming_units) + ",\n \
                        units: " + std::to_string(units) + ",\n \
                        weights: {\nrows: " + std::to_string(weights.get_rows()) + ",\ncols: " + std::to_string(weights.get_cols()) + ",\n";
    for (int i = 0; i < weights.get_rows(); ++i)
        for (int j = 0; j < weights.get_cols(); ++j)
            info += std::to_string(weights(i, j)) + ",\n";
    info += "}\n}";
    return info;
};
void Dense::set_weights(Matrix<float> _weights)
{
    weights = _weights;
}
