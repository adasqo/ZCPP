#pragma once
#include "dense.hpp"
#include "layer.hpp"
#include "../matrix/matrix.hpp"
#include <time.h>

Dense::Dense() : Layer() {};
Dense::Dense(int units) : Layer(units) {};
Dense::Dense(int incoming_units, int units) : Layer(incoming_units, units)
{
    initiatie_weights();
};

void Dense::initiatie_weights()
{
    srand(time(NULL));
    for (int i = 0; i < incoming_units + 1; ++i)
        for (int j = 0; j < units; ++j)
            weights(i, j) = float(float(rand()) / float(RAND_MAX));
}
Matrix<float> Dense::perform_calculations(Matrix<float> input)
{
    Matrix<float> input_biased = Matrix<float>(input.get_rows() + 1, 1);
    input_biased(0, 0) = 1;
    for (int i=0; i < input.get_rows(); ++i)
        input_biased(i + 1, 0) = input(i, 0);
    if(input_biased.get_rows() != weights.get_rows())
        throw std::out_of_range("Index out of bounds");

    return input_biased.transpose()*weights;
};
