#pragma once
#include "dense.hpp"
#include "layer.hpp"
#include "../matrix/matrix.hpp"
#include <time.h>

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
    weights = Matrix<float>(incoming_units + 1, units);
    initiatie_weights();
};

void Dense::initiatie_weights()
{
    srand(time(NULL));
    for (int i = 0; i < incoming_units + 1; ++i)
        for (int j = 0; j < units; ++j)
            weights(i, j) = 2*float(float(rand()) / float(RAND_MAX)) - 1;
}
Matrix<float> Dense::perform_calculations_forward(Matrix<float> input)
{
    Matrix<float> input_biased = Matrix<float>(input.get_rows() + 1, 1);
    input_biased(0, 0) = 1;
    for (int i=0; i < input.get_rows(); ++i)
        input_biased(i + 1, 0) = input(i, 0);
    std::cout << "input: " << input_biased << std::endl;
    if(input_biased.get_rows() != weights.get_rows())
        throw std::out_of_range("Index out of bounds");
    std::cout << "weights:" << std::endl;
    std::cout << weights << std::endl;

    return weights.transpose()*input_biased;
};
